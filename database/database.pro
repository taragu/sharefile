#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T13:06:55
#
#-------------------------------------------------

QT       += core
QT       += sql #sqlite

QT       -= gui

TARGET = database
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ../DatabasePrint.cpp \
    ../sqlite-amalgamation-3080702/sqlite3.c \
    user_db_editor.cpp \
    main.cpp

HEADERS += \
    ../DbAddUser.h \
    ../DbInitialize.h \
    ../UserDbEditor.h \
    ../sqlite-amalgamation-3080702/sqlite3.h \
    ../sqlite-amalgamation-3080702/sqlite3ext.h \
    user_db_editor.h \
    sqlite3.h

#INCLUDEPATH += $$quote(D:/libs/libsqlite3x-2007.10.18) $$quote(D:/libs/sqlite-amalgamation-3071502)
#INCLUDEPATH += $$quote(E:/551/sqlite-amalgamation-3080702) $$quote(E:/551/)
INCLUDEPATH += E:/551/
