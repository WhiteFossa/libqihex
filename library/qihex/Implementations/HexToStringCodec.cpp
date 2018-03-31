#include"HexToStringCodec.hpp"

namespace	Fossa
{
	namespace QiHex
	{
		HexToStringCodec::HexToStringCodec()
		{
			_stringRegExp = new QRegExp(StringRegExp);
		}

		QString HexToStringCodec::Code(uint8_t data)
		{
			return QString::number(data, 16).toUpper();
		}

		uint8_t HexToStringCodec::Decode(QString data)
		{
			if (!_stringRegExp->exactMatch(data))
			{
				SignalizeStringIsNotDecodeable(data);
			}

			auto isSuccess = false;
			uint8_t result = (uint8_t)data.toUInt(&isSuccess, 16);

			if (!isSuccess)
			{
				SignalizeStringIsNotDecodeable(data);
			}

			return result;
		}

		void HexToStringCodec::SignalizeStringIsNotDecodeable(QString str)
		{
				qCritical() << QObject::tr("Invalid string to decode: %1").arg(str);

				throw new QException();
		}

		HexToStringCodec::~HexToStringCodec()
		{
			SafeDelete(_stringRegExp);
		}
	}
}
