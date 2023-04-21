QT += core gui
QT += core network

#LIBS += -lGLESv2
#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ftproject.cpp \
    myhelper.cpp

HEADERS += \
    ../build-QFTP-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/ui_ftproject.h \
    ftproject.h \
    myhelper.h \
    ui_ftproject.h

FORMS += \
    ftproject.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc


