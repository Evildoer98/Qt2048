#-------------------------------------------------
#
# Project created by Shicheng Xu 2019-07-5T00:30:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamelogic.cpp \
    bg2048.cpp

HEADERS  += mainwindow.h \
    gamelogic.h \
    bg2048.h

FORMS    += mainwindow.ui \
    bg2048.ui
