#ifndef ICHECKSUMCHECKERWRITER_HPP
#define ICHECKSUMCHECKERWRITER_HPP

#include <QVector>

namespace	Fossa
{
	namespace	QiHex
	{
		namespace Interfaces
		{
			/**
			 * @brief Interface to check and generate Intel HEX checksums.
			 */
			class IChecksumCheckerGenerator
			{
				public:

					/**
					 * @brief Call it to check record checksum.
					 * @param data Record's bytes (including checksum byte).
					 * @return true if checksum correct.
					 */
					virtual bool Check(QVector<uint8_t> data) = 0;

					/**
					 * @brief Call it to generate checksum.
					 * @param data Record's bytes (without checksum byte).
					 * @return Checksum, put it into checksum byte.
					 */
					virtual uint8_t Generate(QVector<uint8_t> data) = 0;

					/**
					 * @brief Virtual destructor.
					 */
					virtual ~IChecksumCheckerGenerator() {}
			};
		}
	}
}

#endif // ICHECKSUMCHECKERWRITER_HPP
