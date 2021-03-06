#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T16:42:13
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = libqihexTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

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
				libqihexTests.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += -lqihex

INCLUDEPATH += ../../library/qihex

RESOURCES += \
    resources.qrc

DISTFILES += \
    resources/8bit_sequential.hex \
    resources/crc_error.hex \
    resources/even_characters_error.hex \
    resources/no_colon_error.hex \
    resources/wrong_characters_error.hex \
    resources/wrong_reclen_error.hex \
    resources/wrong_rectype_error.hex \
    resources/eof_wrong_offset.hex
