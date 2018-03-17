#ifndef IIHEXREADER_HPP
#define IIHEXREADER_HPP

#include <QVector>
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
					 * @return Dataset with data from file.
					 */
					virtual QVector<IiHexReadonlyDataset> ReadFile(QString file) = 0;
			};
		}
	}
}

#endif // IIHEXREADER_HPP
