#-------------------------------------------------
#
# Project created by QtCreator 2014-06-22T18:18:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpressionTrainer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    genexpr.cpp \
    resultwindow.cpp

HEADERS  += mainwindow.h \
    genexpr.h \
    resultwindow.h

FORMS    += mainwindow.ui \
    resultwindow.ui
