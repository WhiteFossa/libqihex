#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T16:26:46
#
#-------------------------------------------------

QT       -= gui

TARGET = qihex
TEMPLATE = lib

DEFINES += QIHEX_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
		QiHex.cpp \
    Implementations/iHexReader.cpp \
    Implementations/iHexRecord.cpp \
    Implementations/HexToStringCodec.cpp \
    Implementations/ChecksumCheckerGenerator.cpp

HEADERS += \
				qihex_global.hpp \
		QiHex.hpp \
		qihex_global.hpp \
		Interfaces/IiHexReader.hpp \
		Interfaces/IiHexReadonlyDataset.hpp \
    Implementations/iHexReader.hpp \
    QiHexTypes.hpp \
    Interfaces/IiHexRecord.hpp \
    Implementations/iHexRecord.hpp \
    Auxilliary.hpp \
    Interfaces/IHexToStringCodec.hpp \
    Implementations/HexToStringCodec.hpp \
    Interfaces/IChecksumCheckerGenerator.hpp \
    Implementations/ChecksumCheckerGenerator.hpp

unix {
		target.path = /usr/lib
		INSTALLS += target
}
