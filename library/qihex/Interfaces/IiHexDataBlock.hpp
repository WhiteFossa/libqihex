#ifndef IIHEXDATABLOCK_HPP
#define IIHEXDATABLOCK_HPP

#include <QVector>

#include "qihex_global.hpp"

namespace Fossa
{
	namespace QiHex
	{
		namespace Interfaces
		{
			/**
			 * @brief Class with continous addresses data block;
			 */
			class QIHEXSHARED_EXPORT IiHexDataBlock
			{
				public:
					/**
					 * @brief Base address of data block, i.e. address of first byte in it.
					 */
					uint32_t BaseAddress;

					/**
					 * @brief Data, contained in this block.
					 */
					QVector<uint8_t> Data;
			};
		}
	}
}

#endif // IIHEXDATABLOCK_HPP
