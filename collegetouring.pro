#-------------------------------------------------
#
# Project created by QtCreator 2020-02-10T16:06:38
#
#-------------------------------------------------

QT       += core sql gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
CONFIG += console c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        addsouvenirs.cpp \
        database.cpp \
        main.cpp \
        mainwindow.cpp \
        plantrips.cpp

HEADERS += \
        addsouvenirs.h \
        database.h \
        header.h \
        mainwindow.h \
        plantrips.h

FORMS += \
    addsouvenirs.ui \
    mainwindow.ui \
    plantrips.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
