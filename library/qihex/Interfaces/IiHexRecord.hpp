#ifndef IIHEXRECORD_HPP
#define IIHEXRECORD_HPP

#include <QVector>
#include <QString>

namespace Fossa
{
	namespace QiHex
	{
		namespace Interfaces
		{
			/**
			 * @brief Possible records type for Intel HEX. Values are RECTYPE field content.
			 */
			enum iHexRecordType
			{
				Data										= 0x00,
				EndOfFile								= 0x01,
				ExtendedSegmentAddress	= 0x02,
				StartSegmentAddress			= 0x03,
				ExtendedLinearAddress		= 0x04,
				StartLinearAddress			= 0x05
			};

			/**
			 * @brief Interface for one Intel HEX record (i.e. line in file).
			 */
			class IiHexRecord
			{
				public:
					/**
					 * @brief Constructs record from string in Intel HEX file. Throws exception if string aren't parseable.
					 * @param data String from Intel HEX file.
					 */
					IiHexRecord(QString data)
					{
						Q_UNUSED(data);
						// Do nothing, have to be implemented in implementations.
					}

					/**
					 * @brief Call it to get record type.
					 * @return Record type.
					 */
					virtual iHexRecordType GetRecordType() = 0;

					/**
					 * @brief Call it to get data offset, i.e. address within segment of first data byte in record. Have to be 0x0000 for
					 * non-data records.
					 * @return Address within segment of first data byte.
					 */
					virtual uint16_t GetOffset() = 0;

					/**
					 * @brief Call it to get non-interpreted payload of record. First byte at 0 position in array.
					 * @return Record payload.
					 */
					virtual QVector<uint8_t> GetPayload() = 0;

					/**
					* Destructor.
					*/
					virtual ~IiHexRecord() {}
			};
		}
	}
}


#endif // IIHEXRECORD_HPP
