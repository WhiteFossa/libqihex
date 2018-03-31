#ifndef IHEXRECORD_HPP
#define IHEXRECORD_HPP

#include <QDebug>
#include <QString>
#include <QRegExp>
#include <QException>

#include "../Interfaces/IiHexRecord.hpp"
#include "Auxilliary.hpp"

namespace Fossa
{
	namespace	QiHex
	{
		/**
		 * @brief Class to parse generic Intel HEX record.
		 */
		class iHexRecord : public Interfaces::IiHexRecord
		{
			public:
				iHexRecord(QString data);

				virtual Interfaces::iHexRecordType GetRecordType();
				virtual uint16_t GetOffset();
				virtual QVector<uint8_t> GetPayload();

				virtual ~iHexRecord();

			private:
				/**
				 * @brief Input string have to match to this regexp.
				 */
				const QString LineRegexp = "^:[0-9ABCDEF]+";

				/**
				* Intel HEX string regexp matcher.
				*/
				QRegExp* _lineRegExp;

				/**
				 * @brief Call it to show diagnostic message and throw exception about non-parseable line.
				 * @param data Line contents.
				 */
				void SignalizeLineIsNotParseable(QString data);
		};
	}
}



#endif // IHEXRECORD_HPP
