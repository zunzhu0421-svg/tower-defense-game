QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    choosebutton.cpp \
    enemy.cpp \
    enemy2.cpp \
    enemyfly.cpp \
    enemyfly2.cpp \
    level.cpp \
    main.cpp \
    map.cpp \
    mypushbutton.cpp \
    remotepushbutton.cpp \
    road.cpp \
    soldier2.cpp \
    soldierbutton.cpp \
    soldiers.cpp \
    tower.cpp \
    tower2.cpp \
    tower3.cpp \
    widget.cpp

HEADERS += \
    bullet.h \
    choosebutton.h \
    enemy.h \
    enemy2.h \
    enemyfly.h \
    enemyfly2.h \
    level.h \
    map.h \
    mypushbutton.h \
    remotepushbutton.h \
    road.h \
    soldier2.h \
    soldierbutton.h \
    soldiers.h \
    tower.h \
    tower2.h \
    tower3.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Image.qrc \
    Mapfile.qrc
