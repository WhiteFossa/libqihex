#ifndef IIHEXREADER_HPP
#define IIHEXREADER_HPP

#include <QString>

#include "qihex_global.hpp"
#include "IiHexReadonlyDataset.hpp"

namespace	Fossa
{
	namespace	QiHex
	{
		namespace Interfaces
		{
			class QIHEXSHARED_EXPORT IiHexReader
			{
				public:
					/**
					 * @brief Call this method to read data from Intel HEX file.
					 * @param file File to read.
					 * @return Pointer to dataset with data from file.
					 */
					virtual Fossa::QiHex::Interfaces::IiHexReadonlyDataset* ReadFile(QString fileName) = 0;

					/**
					 * @brief Destructor.
					 */
					virtual ~IiHexReader()
					{
						// Do nothing, it's interface.
					}
			};
		}
	}
}

#endif // IIHEXREADER_HPP
