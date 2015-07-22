#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T19:39:29
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
    gamewindow.cpp \
    tile.cpp \
    chessfigure.cpp \
    pawn.cpp \
    rook.cpp \
    knight.cpp \
    bishop.cpp \
    queen.cpp \
    king.cpp \
    move.cpp \
    figuretranformation.cpp \
    handler.cpp

HEADERS  += \
    gamewindow.h \
    tile.h \
    chessfigure.h \
    pawn.h \
    rook.h \
    knight.h \
    bishop.h \
    queen.h \
    king.h \
    move.h \
    figuretranformation.h \
    handler.h

FORMS    += \
    gamewindow.ui \
    figuretranformation.ui

RESOURCES += \
    sprites.qrc
