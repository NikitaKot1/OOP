QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    control.cpp \
    dot_funcs.cpp \
    frame_funcs.cpp \
    frame_tranform.cpp \
    input.cpp \
    main.cpp \
    mainwindow.cpp \
    output.cpp

HEADERS += \
    constants.h \
    control.h \
    dot_funcs.h \
    frame_funcs.h \
    frame_transform.h \
    input.h \
    mainwindow.h \
    output.h \
    structure.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    non-oop_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    frame.txt
