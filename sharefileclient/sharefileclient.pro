#-------------------------------------------------
#
# Project created by QtCreator 2014-11-21T17:13:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sharefileclient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientcommand.cpp

HEADERS  += mainwindow.h \
    clientcommand.h

FORMS    += mainwindow.ui \
    signupform.ui \
    signup_warning_dialog.ui \
    filemanager.ui
