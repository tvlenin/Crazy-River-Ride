#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T21:39:15
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Prueba3
TEMPLATE = app
QMAKE_CXXFLAGS += -std=gnu++0x -pthread
QMAKE_CFLAGS += -std=gnu++0x -pthread

SOURCES += main.cpp \
    GameGUI.cpp \
    GameLogic.cpp \
    GUIScore.cpp \
    GUIHealth.cpp \
    GUIPlayer.cpp \
    GUIEnemy.cpp \
    GUIBullet.cpp \
    QTDriver.cpp \
    UI.cpp \
    QT.cpp \
    LogicPlayer.cpp


HEADERS  += \
    GameLogic.h \
    GameGUI.h \
    GUIBullet.h \
    GUIEnemy.h \
    GUIHealth.h \
    GUIScore.h \
    GUIPlayer.h \
    QTDriver.h \
    UI.h \
    QT.h \
    LogicPlayer.h \
    EDlista.h \
    EDnodo.h


RESOURCES += \
    res.qrc
