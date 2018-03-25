#ifndef IHEXREADER_HPP
#define IHEXREADER_HPP

#include <QtCore/qglobal.h>
#include <QFile>
#include <QException>
#include <QDebug>
#include <QTextStream>
#include <QString>

#include "../Interfaces/IiHexReader.hpp"


namespace Fossa
{
	namespace	QiHex
	{
		class QIHEXSHARED_EXPORT iHexReader : public Interfaces::IiHexReader
		{
			public:
				virtual QVector<Interfaces::IiHexReadonlyDataset> ReadFile(QString fileName);

				virtual ~iHexReader();
		};
	}
}



#endif // IHEXREADER_HPP
