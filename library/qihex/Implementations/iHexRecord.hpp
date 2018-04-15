#ifndef IHEXRECORD_HPP
#define IHEXRECORD_HPP

#include <QDebug>
#include <QString>
#include <QRegExp>
#include <QException>

#include "../Interfaces/IiHexRecord.hpp"
#include "../Interfaces/IHexToStringCodec.hpp"
#include "../Interfaces/IChecksumCheckerGenerator.hpp"
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
				 * @brief RECLEN (Record Length) have this position in record data.
				 */
				const uint ReclenOffset = 0U;

				/**
				 * @brief Add this number to RECLEN, result have to be equal to record size.
				 */
				const int ReclenShift = 5;

				/**
				 * @brief Most significant bit of OFFSET field position in record data.
				 */
				const uint OffsetOffset = 1U;

				/**
				 * @brief RECTYPE (Record Type) field position in record data.
				 */
				const uint RectypeOffset = 3U;

				/**
				 * @brief Offset for records with no data.
				 */
				const uint ZeroOffset = 0U;

				/**
				 * @brief Reclen value for End of File record.
				 */
				const uint EndOfFileRecordReclen = 0U;

				/**
				 * @brief Reclen value for Extended Segment Address record.
				 */
				const uint ExtendedSegmentAddressRecordReclen = 7U;

				/**
				 * @brief Reclen value for Start Segment Address record.
				 */
				const uint StartSegmentAddressRecordReclen = 9U;

				/**
				 * @brief Reclen value for Extended Linear Address record.
				 */
				const uint ExtendedLinearAddressRecordReclen = 7U;

				/**
				 * @brief Reclen value for Start Linear Address record.
				 */
				const uint StartLinearAddressRecordReclen = 9U;

				/**
				 * @brief Payload starts at this position in record data.
				 */
				const uint PayloadOffset = 4U;

				/**
				* Intel HEX string regexp matcher.
				*/
				QRegExp* _lineRegExp;

				/**
				 * @brief String<->Hex codec.
				 */
				Interfaces::IHexToStringCodec* _codec;

				/**
				 * @brief Checksum checker.
				 */
				Interfaces::IChecksumCheckerGenerator* _checksumCheckerGenerator;

				/**
				 * @brief Data offset (i.e. address) in record.
				 */
				uint16_t _offset;

				/**
				 * @brief Record type.
				 */
				Interfaces::iHexRecordType _recordType;

				/**
				 * @brief Record payload.
				 */
				QVector<uint8_t> _payload;

				/**
				 * @brief Call it to show diagnostic message and throw exception about non-parseable line.
				 * @param data Line contents.
				 */
				void SignalizeLineIsNotParseable(QString data);
		};
	}
}



#endif // IHEXRECORD_HPP
