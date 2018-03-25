#ifndef QIHEXTYPES_HPP
#define QIHEXTYPES_HPP

#include "qihex_global.hpp"

namespace	Fossa
{
	namespace QiHex
	{
		/**
		 * @brief Possible modes for Intel HEX. Mode defines allowed records set.
		 */
		enum QIHEXSHARED_EXPORT iHexAddressingMode
		{
			Mode8bit,
			Mode16bit,
			Mode32bit,
		};
	}
}

#endif // QIHEXTYPES_HPP
