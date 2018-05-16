#-------------------------------------------------
#
# Project created by QtCreator 2018-03-12T11:00:30
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets
QT       += winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LearnWithRobinMain
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
        robinmainwindow.cpp \
    mainmenu.cpp \
    calculmental.cpp \
    supersimon.cpp \
    modcalcul.cpp \
    modsimon.cpp \
    memory.cpp \
    flags.cpp \
    puzzle.cpp \
    pointandclick.cpp \
    modpuzzle.cpp \
    modmemory.cpp \
    modflags.cpp \
    modpointandclick.cpp \
    memoryaddons.cpp \
    parameterslwr.cpp \
    tools.cpp \
    player.cpp

HEADERS += \
        robinmainwindow.h \
    mainmenu.h \
    calculmental.h \
    supersimon.h \
    includeviews.h \
    commonlibs.h \
    modcalcul.h \
    modsimon.h \
    memory.h \
    flags.h \
    puzzle.h \
    pointandclick.h \
    modpuzzle.h \
    modmemory.h \
    modflags.h \
    modpointandclick.h \
    memoryaddons.h \
    parameterslwr.h \
    tools.h \
    player.h

FORMS += \
        robinmainwindow.ui \
    mainmenu.ui \
    calculmental.ui \
    supersimon.ui \
    memory.ui \
    flags.ui \
    puzzle.ui \
    pointandclick.ui

RESOURCES += \
    buttonrobin.qrc
