#ifndef HEXTOSTRINGCODEC_HPP
#define HEXTOSTRINGCODEC_HPP

#include <QRegExp>
#include <QDebug>
#include <QException>

#include "../Interfaces/IHexToStringCodec.hpp"
#include "Auxilliary.hpp"

namespace Fossa
{
	namespace	QiHex
	{
		class HexToStringCodec : public Interfaces::IHexToStringCodec
		{
			public:
				HexToStringCodec();

				QString Code(uint8_t data);
				uint8_t Decode(QString data);

				virtual ~HexToStringCodec();

			private:

				/**
				 * @brief Regexp, for what data in Decode() have to match.
				 */
				const QString StringRegExp = "[0-9ABCDEF]{2}";

				/**
				 * @brief Regexp matcher for StringRegExp.
				 */
				QRegExp* _stringRegExp;

				/**
				 * @brief Put message about non-decodeable string to console and throw an exception.
				 * @param str Non-parseable string.
				 */
				void SignalizeStringIsNotDecodeable(QString str);
		};
	}
}

#endif // HEXTOSTRINGCODEC_HPP
