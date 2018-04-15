#ifndef IIHEXREADONLYDATASET_HPP
#define IIHEXREADONLYDATASET_HPP

#include <QMap>

#include "qihex_global.hpp"
#include "QiHexTypes.hpp"

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
					 * @brief File contains records, stored in this mode. Mode detection based on analysis what records appeared in file.
					 */
					Fossa::QiHex::iHexAddressingMode Mode;

					/**
					 * @brief Data in dataset, key is address, value is data.
					 */
					QMap<uint32_t, uint8_t> Data;
			};
		}
	}
}

#endif // IIHEXREADONLYDATASET_HPP
