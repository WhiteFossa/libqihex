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
		}

		Interfaces::iHexRecordType iHexRecord::GetRecordType()
		{
			return Interfaces::iHexRecordType::Data;
		}

		uint16_t iHexRecord::GetOffset()
		{
			return 0;
		}

		QVector<uint8_t> iHexRecord::GetPayload()
		{
			return QVector<uint8_t>();
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
