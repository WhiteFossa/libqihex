#ifndef IHEXREADER_HPP
#define IHEXREADER_HPP

#include <QtCore/qglobal.h>

#include "../Interfaces/IiHexReader.hpp"

namespace Fossa
{
	namespace	QiHex
	{
		class iHexReader : Interfaces::IiHexReader
		{
			public:
				QVector<Interfaces::IiHexReadonlyDataset> ReadFile(QString file) = 0;
		};
	}
}



#endif // IHEXREADER_HPP
