#include "iHexReader.hpp"

namespace Fossa
{
	namespace QiHex
	{
		QVector<Interfaces::IiHexReadonlyDataset> Fossa::QiHex::iHexReader::ReadFile(QString fileName)
		{
			// Reading file line by line
			QFile file(fileName);

			if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			{
				qCritical() << QObject::tr("File %1 can't be opened!").arg(fileName);

				throw new QException();
			}

			QTextStream fileStream(&file);
			while (!fileStream.atEnd())
			{
				QString readedString = fileStream.readLine();

				Interfaces::IiHexRecord* record = new iHexRecord(readedString);

				SafeDelete(record);
			}

			file.close();

			// TODO: Implement it
			return QVector<Interfaces::IiHexReadonlyDataset>();
		}

		Fossa::QiHex::iHexReader::~iHexReader()
		{
			// Cleanup here
		}
	}
}



