#include "iHexRecord.hpp"
#include "HexToStringCodec.hpp"
#include "ChecksumCheckerGenerator.hpp"

namespace Fossa
{
	namespace QiHex
	{
		iHexRecord::iHexRecord(QString data) : Interfaces::IiHexRecord(data)
		{
			_lineRegExp = new QRegExp(LineRegexp);
			_codec = new HexToStringCodec();
			_checksumCheckerGenerator = new ChecksumCheckerGenerator();

			// We need to have odd characters number
			if ((data.length() % 2) != 1)
			{
				SignalizeLineIsNotParseable(data);
			}

			auto dataUpper = data.toUpper();
			if (!_lineRegExp->exactMatch(dataUpper))
			{
				SignalizeLineIsNotParseable(data);
			}

			// Removing ":" from begin
			dataUpper = dataUpper.right(dataUpper.length() - 1);

			// Reading characters by pairs
			QVector<uint8_t> lineData;
			auto byteIterator = dataUpper.begin();

			while (byteIterator != dataUpper.end())
			{
				QString pair;
				pair.append(*byteIterator);
				byteIterator ++;
				pair.append(*byteIterator);
				byteIterator ++;

				lineData.append(_codec->Decode(pair));
			}

			// Checking checksum
			if (!_checksumCheckerGenerator->Check(lineData))
			{
				qCritical() << QObject::tr("Checksum error.");

				throw new QException();
			}

			// Reading RECLEN (see format description)
			uint reclen = lineData[ReclenOffset];

			if (reclen + ReclenShift != (uint)lineData.size())
			{
				qCritical() << QObject::tr("Incorrect record length. Got %1, expected %2").arg(reclen).arg(lineData.size() - ReclenShift);

				throw new QException();
			}

			// Reading offset
			_offset = lineData[OffsetOffset] * 0x100 + lineData[OffsetOffset + 1];

			// Detecting record type
			uint8_t rectype = lineData[RectypeOffset];

			switch (rectype)
			{
				// Data
				case Interfaces::iHexRecordType::Data:
					_recordType = Interfaces::iHexRecordType::Data;
				break;

				// End of file
				case Interfaces::iHexRecordType::EndOfFile:
					_recordType = Interfaces::iHexRecordType::EndOfFile;

					if (_offset != ZeroOffset)
					{
						qCritical() << QObject::tr("Incorrect OFFSET for End of File record. Expected %1, got %2").arg(ZeroOffset).arg(_offset);

						throw new QException();
					}

					if (reclen != EndOfFileRecordReclen)
					{
						qCritical() << QObject::tr("Incorrect RECLEN for End of File record. Expected %1, got %2").arg(EndOfFileRecordReclen).arg(reclen);

						throw new QException();
					}
				break;

				// Extended segment address
				case Interfaces::iHexRecordType::ExtendedSegmentAddress:
					_recordType = Interfaces::iHexRecordType::ExtendedSegmentAddress;

					if (_offset != ZeroOffset)
					{
						qCritical() << QObject::tr("Incorrect OFFSET for Extended Segment Address record. Expected %1, got %2").arg(ZeroOffset).arg(_offset);

						throw new QException();
					}

					if (reclen != ExtendedSegmentAddressRecordReclen)
					{
						qCritical() << QObject::tr("Incorrect RECLEN for Extended Segment Address record. Expected %1, got %2").arg(ExtendedSegmentAddressRecordReclen).arg(reclen);

						throw new QException();
					}
				break;

				// Start segment address
				case Interfaces::iHexRecordType::StartSegmentAddress:
					_recordType = Interfaces::iHexRecordType::StartSegmentAddress;

					if (_offset != ZeroOffset)
					{
						qCritical() << QObject::tr("Incorrect OFFSET for Start Segment Address record. Expected %1, got %2").arg(ZeroOffset).arg(_offset);

						throw new QException();
					}

					if (reclen != StartSegmentAddressRecordReclen)
					{
						qCritical() << QObject::tr("Incorrect RECLEN for Start Segment Address record. Expected %1, got %2").arg(StartSegmentAddressRecordReclen).arg(reclen);

						throw new QException();
					}
				break;

				// Extended linear address
				case Interfaces::iHexRecordType::ExtendedLinearAddress:
					_recordType = Interfaces::iHexRecordType::ExtendedLinearAddress;

					if (_offset != ZeroOffset)
					{
						qCritical() << QObject::tr("Incorrect OFFSET for Extended Linear Address record. Expected %1, got %2").arg(ZeroOffset).arg(_offset);

						throw new QException();
					}

					if (reclen != ExtendedLinearAddressRecordReclen)
					{
						qCritical() << QObject::tr("Incorrect RECLEN for Extended Linear Address record record. Expected %1, got %2").arg(ExtendedLinearAddressRecordReclen).arg(reclen);

						throw new QException();
					}
				break;

				// Start linear address
				case Interfaces::iHexRecordType::StartLinearAddress:
					_recordType = Interfaces::iHexRecordType::StartLinearAddress;

					if (_offset != ZeroOffset)
					{
						qCritical() << QObject::tr("Incorrect OFFSET for Start Linear Address record. Expected %1, got %2").arg(ZeroOffset).arg(_offset);

						throw new QException();
					}

					if (reclen != StartLinearAddressRecordReclen)
					{
						qCritical() << QObject::tr("Incorrect RECLEN for Start Linear Address record record. Expected %1, got %2").arg(StartLinearAddressRecordReclen).arg(reclen);

						throw new QException();
					}
				break;

				default:
					qCritical() << QObject::tr("Incorrect record type code: %1").arg(rectype);

					throw new QException();
				break;
			}

			// Getting payload
			_payload = lineData.mid(PayloadOffset, lineData.length() - ReclenShift);
		}

		Interfaces::iHexRecordType iHexRecord::GetRecordType()
		{
			return _recordType;
		}

		uint16_t iHexRecord::GetOffset()
		{
			return _offset;
		}

		QVector<uint8_t> iHexRecord::GetPayload()
		{
			return _payload;
		}

		void iHexRecord::SignalizeLineIsNotParseable(QString data)
		{
			qCritical() << QObject::tr("Line isn't parseable: \"%0\"").arg(data);

			throw new QException();
		}

		iHexRecord::~iHexRecord()
		{
			SafeDelete(_checksumCheckerGenerator);
			SafeDelete(_codec);
			SafeDelete(_lineRegExp);
		}
	}
}
