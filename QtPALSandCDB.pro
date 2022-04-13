macx:include(/usr/local/qwt-6.2.0/features/qwt.prf);
win32:include(c:/qwt-6.2.0/features/qwt.prf);
linux:include(/usr/local/qwt-6.2.0/features/qwt.prf);

win32: LIBS += -L$$PWD/lib/x64/ -llibusb-1.0
win32: PRE_TARGETDEPS += $$PWD/lib/x64/libusb-1.0.lib

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += qwt
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

GIT_VERSION = $$system(git --git-dir $$PWD/.git --work-tree $$PWD describe --always --tags)

VERSTR = '\\"$${GIT_VERSION}\\"'
DEFINES += GIT_VERSION=\"$${VERSTR}\"
DEFINES+= HAVE_USB
DEFINES+= HAVE_LIBUSB10
DEFINES += NOMINMAX
unix:DEFINES+= OS_LINUX
win32:DEFINES+= QWT_DLL
win32:DEFINES+= NOLR

SOURCES += \
    DRS/DRS.cpp \
    DRS/averager.cpp \
    DRS/musbstd.c \
    DRS/mxml.c \
    DRS/strlcpy.c \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DRS/DRS.h \
    DRS/averager.h \
    DRS/bitutils.h \
    DRS/musbstd.h \
    DRS/mxml.h \
    DRS/strlcpy.h \
    include/drs4header.h \
    include/libusb-1.0/libusb.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
INCLUDEPATH += $$PWD/
INCLUDEPATH += $$PWD/DRS
DEPENDPATH += $$PWD/
DEPENDPATH += $$PWD/DRS


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lib/x64/libusb-1.0.lib

