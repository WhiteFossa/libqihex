#include "iHexReader.hpp"

namespace Fossa
{
	namespace QiHex
	{
		QVector<Interfaces::IiHexReadonlyDataset> Fossa::QiHex::iHexReader::ReadFile(QString fileName)
		{
			// Reset state
			_baseAddress = 0;
			_state = iHexReaderState::MODE8;

			// Reading file line by line
			QFile file(fileName);

			if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			{
				qCritical() << QObject::tr("File %1 can't be opened!").arg(fileName);

				throw new QException();
			}

			QTextStream fileStream(&file);

			uint lineNumber = 0;
			QString readLine;
			while (!fileStream.atEnd())
			{
				readLine = fileStream.readLine();

				try
				{
					Interfaces::IiHexRecord* record = new iHexRecord(readLine);

					if (iHexReaderState::END == _state)
					{
						// New record after end
						qCritical() << QObject::tr("Record after End of File record.");
						SafeDelete(record);
						throw new QException();
					}

					auto recordType = record->GetRecordType();

					// Maybe end of file?
					if (Interfaces::iHexRecordType::EndOfFile == recordType)
					{
						_state = iHexReaderState::END;
						SafeDelete(record);
						continue;
					}

					// Switching modes
					switch (_state)
					{
						case iHexReaderState::MODE8:
							if ((Interfaces::iHexRecordType::ExtendedSegmentAddress == recordType) || (Interfaces::iHexRecordType::StartSegmentAddress == recordType))
							{
								// 8 bit -> 16 bit
								_state = iHexReaderState::MODE16;
							}
							else if ((Interfaces::iHexRecordType::ExtendedLinearAddress == recordType) || (Interfaces::iHexRecordType::StartLinearAddress == recordType))
							{
								// 8bit -> 32 bit
								_state = iHexReaderState::MODE32;
							}
						break;
						case iHexReaderState::MODE16:
							if ((Interfaces::iHexRecordType::ExtendedLinearAddress == recordType) || (Interfaces::iHexRecordType::StartLinearAddress == recordType))
							{
								// 16 bit -> 32 bit. NOT ALLOWED!
								qCritical() << QObject::tr("Extended Linear Address or Start Linear Address in 16 bit mode.");
								SafeDelete(record);
								throw new QException();
							}
						break;
						case iHexReaderState::MODE32:
							if ((Interfaces::iHexRecordType::ExtendedSegmentAddress == recordType) || (Interfaces::iHexRecordType::StartSegmentAddress == recordType))
							{
								// 32 bit -> 16 bit. NOT ALLOWED!
								qCritical() << QObject::tr("Extended Segment Address or Start Segment Address in 32 bit mode.");
								SafeDelete(record);
								throw new QException();
							}
						break;
					}

					// Processing record
					auto recordPayload = record->GetPayload();
					auto recordOffset = record->GetOffset();

					switch (recordType)
					{
						case Interfaces::iHexRecordType::Data:
							// Adding data
							uint32_t effectiveAddress;

							for (int index = 0; index < recordPayload.size(); index++)
							{
								switch (_state)
								{
									case iHexReaderState::MODE8:
										effectiveAddress = index + recordOffset;
									break;

									case iHexReaderState::MODE16:
										effectiveAddress = _baseAddress + (uint16_t)(index + recordOffset);
									break;

									case iHexReaderState::MODE32:
										effectiveAddress = _baseAddress + index + recordOffset;
									break;
								}

								qWarning() << QObject::tr("Addr: %1, Data: %2").arg(effectiveAddress).arg(recordPayload[index]);
							}
						break;

						case Interfaces::iHexRecordType::ExtendedSegmentAddress:
							// Updating base address (16 bit mode)
							_baseAddress = (recordPayload[USBAHIndex] << USBAHShift) | (recordPayload[USBALIndex] << USBALShift); // Lower bits 0-3 is 0x00
						break;

						case Interfaces::iHexRecordType::ExtendedLinearAddress:
							// Updating base address (32 bit mode)
							_baseAddress = (recordPayload[ULBAHIndex] << ULBAHShift) | (recordPayload[ULBALIndex] << ULBALShift); // Payload contains two upper bytes, two lower is 0x00
						break;
					}

					SafeDelete(record);
				}
				catch (...)
				{
					qCritical() << QObject::tr("Error while processing line %1 : %2").arg(lineNumber).arg(readLine);

					file.close();
					throw;
				}

				lineNumber ++;
			}

			file.close();

			// TODO: Implement it
			return QVector<Interfaces::IiHexReadonlyDataset>();
		}

		Fossa::QiHex::iHexReader::~iHexReader()
		{
			// Cleanup here
		}
	}
}



