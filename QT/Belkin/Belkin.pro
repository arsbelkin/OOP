QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++23

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    group.cpp \
    groupLeader.cpp \
    main.cpp \
    belkin.cpp \
    menu.cpp \
    student.cpp \
    utils.cpp

HEADERS += \
    belkin.h \
    group.h \
    groupLeader.h \
    menu.h \
    student.h \
    utils.h

FORMS += \
    belkin.ui


# INCLUDEPATH += "/opt/homebrew/include"

# LIBS += "/opt/homebrew/lib" -lboost_serialization


macx {
    # Получаем путь к Boost через Homebrew
    BOOST_PREFIX = $$system(brew --prefix boost)
    isEmpty(BOOST_PREFIX) {
        BOOST_PREFIX = /opt/homebrew/opt/boost
    }

    INCLUDEPATH += $${BOOST_PREFIX}/include
    LIBS += -L$${BOOST_PREFIX}/lib
    LIBS += -lboost_serialization
}


CONFIG+=sdk_no_version_check

QMAKE_APPLE_DEVICE_ARCHS = arm64


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
