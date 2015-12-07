#-------------------------------------------------
#
# Project created by QtCreator 2015-07-10T08:02:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = carpc
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    ClassMusic.cpp \
    libraries/SQLiteCpp/Column.cpp \
    libraries/SQLiteCpp/Database.cpp \
    libraries/SQLiteCpp/Statement.cpp \
    libraries/SQLiteCpp/Transaction.cpp \
    ClassMusicDB.cpp \
    ClassMusicPlayer.cpp


HEADERS  += mainwindow.h \
    libraries/bass/bass.h \
    libraries/SQLiteCpp/Assertion.h \
    libraries/SQLiteCpp/Column.h \
    libraries/SQLiteCpp/Database.h \
    libraries/SQLiteCpp/Exception.h \
    libraries/SQLiteCpp/SQLiteCpp.h \
    libraries/SQLiteCpp/Statement.h \
    libraries/SQLiteCpp/Transaction.h \
    ClassMusic.h \
    ui_mainwindow.h \
    listviewmusicdelegate.h \
    ClassMusicDB.h \
    Constants.h \
    ClassMusicPlayer.h


#FORMS    += mainwindow.ui


# bass support
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/bass/release/ -lbass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/bass/debug/ -lbass
else:unix: LIBS += -L$$PWD/libraries/bass/ -lbass

INCLUDEPATH += $$PWD/libraries/bass
DEPENDPATH += $$PWD/libraries/bass

# c++ 11 support
CONFIG += c++11
CONFIG += console

OUTPUT +=Console

# pkgconfig include
unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += alsa
unix: PKGCONFIG += taglib
#unix: PKGCONFIG += tinyxml
unix: PKGCONFIG += sqlite3
