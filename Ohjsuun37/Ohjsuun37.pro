TEMPLATE = app

QT += qml quick
QT += xml
QT += network

CONFIG += c++11 \
          -no-openssl

SOURCES += main.cpp \
    toimija.cpp \
    laura.cpp \
    ammus.cpp \
    kyborgi.cpp \
    vihollinen.cpp \
    sijainti.cpp \
    logiikka.cpp \
    tekoalylliset.cpp \
    parkkihallinrakentaja.cpp \
    tieto.cpp \
    kauppa.cpp \
    xmllukija.cpp \
    haeapidata.cpp \

RESOURCES += qml.qrc

OTHER_FILES += xml.xml

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    xml.xml

HEADERS += \
    toimija.h \
    laura.h \
    ammus.h \
    tekoalylliset.h \
    kyborgi.h \
    vihollinen.h \
    sijainti.h \
    logiikka.h \
    parkkihallinrakentaja.h \
    tieto.h \
    kauppa.h \
    xmllukija.h \
    haeapidata.h

