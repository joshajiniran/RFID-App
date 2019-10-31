#-------------------------------------------------
#
# Project created by QtCreator 2017-07-31T11:44:09
#
#-------------------------------------------------

QT       += core gui multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RFID_App
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    rfidmain.cpp \
    adminpanel.cpp \
    loginpanel.cpp

HEADERS  += rfidmain.h \
    adminpanel.h \
    loginpanel.h

FORMS    += rfidmain.ui \
    adminpanel.ui

RESOURCES += \
    rfid.qrc

DISTFILES += \
    voice-accepted.wav \
    voice-access-denied.wav \
    voice-piy.wav \
    voice-system-activated.wav \
    voice-welcome.wav \
    addButton.png \
    database.png \
    history.png \
    left.png \
    locked.png \
    market_icon.png \
    menuButton.png \
    notification.png \
    price_tag.png \
    removeButton.png \
    search.png \
    system.png \
    transact.png \
    user_female.png \
    user_male.png \
    users.png
