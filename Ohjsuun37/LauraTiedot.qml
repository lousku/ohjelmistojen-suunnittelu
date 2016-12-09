import QtQuick 2.0

Column{

    property alias teho: teho.text
    property alias nopeus: nopeus.text
    property alias kantama: kantama.text
    property alias elama: elama.text
    property alias ammustiheys: ammustiheys.text

    Image {
        id: lauraImage
        width: 60
        height: 60
        source: "qrc:graphics/Laura.png"
    }

    Text {
        id: ammustiheys
        color: "white"
        font.pointSize: 15
    }

    Text {
        id: teho
        color: "white"
        font.pointSize: 15
    }
    Text {
        id: nopeus
        color: "white"
        font.pointSize: 15
    }
    Text {
        id: kantama
        color: "white"
        font.pointSize: 15
    }
    Text {
        id: elama
        color: "white"
        font.pointSize: 15
    }
}
