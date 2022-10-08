#-------------------------------------------------
#
# Project created by QtCreator 2022-10-08T22:32:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webCrawler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx|win32: LIBS += -L$$PWD/lib/curl/ -lcurl
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/curl/curl.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/curl/libcurl.a

unix:!macx|win32: LIBS += -L$$PWD/lib/zlib/ -lz
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/zlib/z.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/zlib/libz.a

unix:!macx|win32: LIBS += -L$$PWD/lib/openssl/ -lcrypto
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/openssl/crypto.lib
#else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/openssl/libcrypto.a

unix:!macx|win32: LIBS += -L$$PWD/lib/openssl/ -lssl
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/openssl/ssl.lib
#else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/openssl/libssl.a

unix:!macx|win32: LIBS += -L$$PWD/lib/ldap/ -llber
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/ldap/lber.lib
#else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/ldap/liblber.a

unix:!macx|win32: LIBS += -L$$PWD/lib/ldap/ -lldap
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/ldap/ldap.lib
#else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/lib/ldap/libldap.a

