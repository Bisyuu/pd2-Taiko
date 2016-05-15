#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T00:54:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    countdown.cpp \
    note.cpp \
    score.cpp \
    restart.cpp \
    gameover.cpp

HEADERS  += mainwindow.h \
    countdown.h \
    note.h \
    score.h \
    restart.h \
    gameover.h

FORMS    += mainwindow.ui
