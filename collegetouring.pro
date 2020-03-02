#-------------------------------------------------
#
# Project created by QtCreator 2020-02-10T16:06:38
#
#-------------------------------------------------

QT       += core sql gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
CONFIG += console c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        database.cpp \
        doublylinkedlist.cpp \
        linkedlistiterator.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        database.h \
        doublylinkedlist.h \
        header.h \
        linkedlistiterator.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
