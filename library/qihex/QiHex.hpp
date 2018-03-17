#ifndef QIHEX_HPP
#define QIHEX_HPP

#include "qihex_global.hpp"

namespace	Fossa
{
	namespace QiHex
	{
		/**
		 * @brief Possible modes for Intel HEX. Mode defines allowed records set.
		 */
		enum FileMode
		{
			Mode8bit,
			Mode16bit,
			Mode32bit,
		};

		/**
		 * @brief Main class for QiHex library.
		 */
		class QIHEXSHARED_EXPORT QiHex
		{
			public:

				QiHex();

				/**
				 * @brief Just for test
				 */
				int Test(int a, int b);
		};
	}
}


#endif // QIHEX_HPP
