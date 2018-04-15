#ifndef IHEXREADER_HPP
#define IHEXREADER_HPP

#include <QtCore/qglobal.h>
#include <QFile>
#include <QException>
#include <QDebug>
#include <QTextStream>
#include <QString>

#include "../Interfaces/IiHexReader.hpp"
#include "../Interfaces/IiHexRecord.hpp"
#include "iHexRecord.hpp"
#include "Auxilliary.hpp"


namespace Fossa
{
	namespace	QiHex
	{
		/**
		 * @brief Possible Intel HEX reader states.
		 */
		enum iHexReaderState
		{
			MODE8,
			MODE16,
			MODE32,
			END
		};

		/**
		 * @brief Intel HEX reader class.
		 */
		class QIHEXSHARED_EXPORT iHexReader : public Interfaces::IiHexReader
		{
			public:
				virtual QVector<Interfaces::IiHexReadonlyDataset> ReadFile(QString fileName);

				virtual ~iHexReader();

			private:

				/**
				 * @brief Payload byte index for USBA upper byte (12-19).
				 */
				const int USBAHIndex = 0;

				/**
				 * @brief Shift USBAH to this value left.
				 */
				const uint USBAHShift = 12;

				/**
				 * @brief Payload byte index for USBA lower byte (4-11).
				 */
				const int USBALIndex = 0;

				/**
				 * @brief Shift USBAL to this value left.
				 */
				const uint USBALShift = 4;

				/**
				 * @brief Payload byte index for ULBA upper byte (24-31).
				 */
				const int ULBAHIndex = 0;

				/**
				 * @brief Shift ULBAH to this value left to get 3th (from 0) byte of ULBA.
				 */
				const uint ULBAHShift = 24L;

				/**
				 * @brief Payload byte index for ULBA lower byte (16-23)
				 */
				const int ULBALIndex = 1;

				/**
				 * @brief Shift ULBAL to this value left to get 2th (from 0) byte of ULBA.
				 */
				const uint ULBALShift = 16L;

				/**
				 * @brief State machine state.
				 */
				iHexReaderState _state;

				/**
				 * @brief Base address (meaning depends on _state).
				 */
				uint32_t _baseAddress;
		};
	}
}



#endif // IHEXREADER_HPP
