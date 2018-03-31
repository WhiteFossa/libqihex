#ifndef IHEXTOSTRINGCODEC_HPP
#define IHEXTOSTRINGCODEC_HPP

#include <QString>

namespace	Fossa
{
	namespace	QiHex
	{
		namespace Interfaces
		{
			/**
			 * @brief Interface to coding uint8_t to QString and back.
			 */
			class IHexToStringCodec
			{
				public:
					/**
					 * @brief Encode byte to string.
					 * @param Byte to encode.
					 * @return String representation of data.
					 */
					virtual QString Code(uint8_t data) = 0;

					/**
					 * @brief Decode string representation of one byte.
					 * @param data String to decode.
					 * @return Byte from string.
					 */
					virtual uint8_t Decode(QString data) = 0;

					/**
					 * @brief Virtual destructor.
					 */
					virtual ~IHexToStringCodec() {}
			};
		}
	}
}

#endif // IHEXTOSTRINGCODEC_HPP
