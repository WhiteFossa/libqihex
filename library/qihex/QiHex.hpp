#ifndef QIHEX_HPP
#define QIHEX_HPP

#include "qihex_global.hpp"
#include "Interfaces/IiHexReader.hpp"

namespace	Fossa
{
	namespace QiHex
	{
		/**
		 * @brief Main class for QiHex library.
		 */
		class QIHEXSHARED_EXPORT QiHex
		{
			public:
				QiHex();

				/**
				 * @brief Call this method to get iHex reader instance.
				 * @return iHex reader instance.
				 */
				Fossa::QiHex::Interfaces::IiHexReader* GetReader();
		};
	}
}


#endif // QIHEX_HPP
