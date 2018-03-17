#ifndef IIHEXREADONLYDATASET_HPP
#define IIHEXREADONLYDATASET_HPP

#include <QVector>

#include "qihex_global.hpp"
#include "QiHex.hpp"
#include "IiHexDataBlock.hpp"

namespace Fossa
{
	namespace QiHex
	{
		namespace Interfaces
		{
			/**
			 * @brief Class with data, read from Intel HEX file.
			 */
			class QIHEXSHARED_EXPORT IiHexReadonlyDataset
			{
				public:
					/**
					 * @brief File contains records, pointing to this mode. Mode detection based on analysis what records appeared in file.
					 */
					FileMode Mode;

					/**
					 * @brief Data blocks, read from file.
					 */
					QVector<IiHexDataBlock> DataBlocks;
			};
		}
	}
}

#endif // IIHEXREADONLYDATASET_HPP
