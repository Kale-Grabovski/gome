#-------------------------------------------------
#
# Project created by QtCreator 2017-05-20T20:07:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tictactoe
TEMPLATE = app


SOURCES += main.cpp\
        tictactoewidget.cpp \
    configurationdialog.cpp \
    mainwindow.cpp

HEADERS  += tictactoewidget.h \
    configurationdialog.h \
    mainwindow.h

FORMS    += tictactoewidget.ui \
    configurationdialog.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc
