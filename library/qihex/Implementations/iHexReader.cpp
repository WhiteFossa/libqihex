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

			uint lineNumber = 0;
			QString readLine;
			while (!fileStream.atEnd())
			{
				readLine = fileStream.readLine();

				try
				{
					Interfaces::IiHexRecord* record = new iHexRecord(readLine);

					SafeDelete(record);
				}
				catch (...)
				{
					qCritical() << QObject::tr("Error while processing line %1 : %2").arg(lineNumber).arg(readLine);

					throw;
				}

				lineNumber ++;
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



