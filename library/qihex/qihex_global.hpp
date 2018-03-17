#ifndef QIHEX_GLOBAL_HPP
#define QIHEX_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(QIHEX_LIBRARY)
#  define QIHEXSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QIHEXSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QIHEX_GLOBAL_HPP
