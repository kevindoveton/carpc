#-------------------------------------------------
#
# Project created by QtCreator 2015-07-10T08:02:43
#
#-------------------------------------------------

QT  += core \
    gui     \
    dbus    \
    opengl  \
    network \
    multimedia

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
    ClassMusicPlayer.cpp \
    ClassSystemVolume.cpp \
    dbus/OfonoCallVolume.cpp \
    dbus/OfonoHandsFree.cpp \
    dbus/OfonoModem.cpp \
    dbus/OfonoNetworkRegistration.cpp \
    dbus/OfonoSiri.cpp \
    dbus/OfonoVoiceCallManager.cpp \
    ClassOfono.cpp \
    dbus/OfonoManager.cpp \
    dbus/OfonoVoiceCall.cpp \
    ClassContactDB.cpp \
    ClassVoicecall.cpp \
    ClassMapData.cpp \
    QGLWidgetMapWindow.cpp \
    ClassAudioPlayerQT.cpp \
    ClassAirplay.cpp



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
    ClassMusicDB.h \
    ClassMusicPlayer.h \
    ClassSystemVolume.h \
    dbus/OfonoCallVolume.h \
    dbus/OfonoHandsFree.h \
    dbus/OfonoModem.h \
    dbus/OfonoNetworkRegistration.h \
    dbus/OfonoSiri.h \
    dbus/OfonoVoiceCallManager.h \
    ClassOfono.h \
    dbus/OfonoManager.h \
    dbus/OfonoVoiceCall.h \
    ClassContactDB.h \
    ClassVoicecall.h \
    ClassMapData.h \
    QGLWidgetMapWindow.h \
    ListViewMusicDelegateGrid.h \
    ListViewMusicDelegateList.h \
    ClassAudioPlayerQT.h \
    ClassAirplay.h


RESOURCES += resources/resources.qrc


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
unix: PKGCONFIG += sqlite3

unix:!macx: LIBS += -L$$PWD/libraries/qmapbox/ -lqmapboxgl

INCLUDEPATH += $$PWD/libraries/qmapbox/include
DEPENDPATH += $$PWD/libraries/qmapbox/include
