TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    toimija.cpp \
    laura.cpp \
    ammus.cpp \
    kyborgi.cpp \
    vihollinen.cpp \
    sijainti.cpp \
    logiikka.cpp \
    tekoalylliset.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    toimija.h \
    laura.h \
    ammus.h \
    tekoalylliset.h \
    kyborgi.h \
    vihollinen.h \
    sijainti.h \
    logiikka.h
