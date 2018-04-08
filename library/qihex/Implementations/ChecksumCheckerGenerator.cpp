#include "ChecksumCheckerGenerator.hpp"

namespace	Fossa
{
	namespace	QiHex
	{
		bool ChecksumCheckerGenerator::Check(QVector<uint8_t> data)
		{
			uint8_t buffer = 0x00; // Intentionally 8-bit, overflow is what we need.

			auto iterator = data.begin();
			while (iterator != data.end())
			{
				buffer += *iterator;
				iterator ++;
			}

			return 0x00 == buffer;
		}

		uint8_t ChecksumCheckerGenerator::Generate(QVector<uint8_t> data)
		{
			return 0x00;
		}

		ChecksumCheckerGenerator::~ChecksumCheckerGenerator()
		{

		}
	}
}
