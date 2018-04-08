#ifndef CHECKSUMCHECKERGENERATOR_HPP
#define CHECKSUMCHECKERGENERATOR_HPP

#include "../Interfaces/IChecksumCheckerGenerator.hpp"

namespace Fossa
{
	namespace	QiHex
	{
		class ChecksumCheckerGenerator : public Interfaces::IChecksumCheckerGenerator
		{
			public:
				virtual bool Check(QVector<uint8_t> data);
				virtual uint8_t Generate(QVector<uint8_t> data);

				virtual ~ChecksumCheckerGenerator();
		};
	}
}

#endif // CHECKSUMCHECKERGENERATOR_HPP
