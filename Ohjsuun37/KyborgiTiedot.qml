import QtQuick 2.0

Column {
    property alias kuvapolku: kyborgi.kuvapolku
    property alias tunniste: kyborgi.tunniste
    property alias painettavissa: kyborgi.painettavissa

    property alias teho: teho.text
    property alias nopeus: nopeus.text
    property alias kantama: kantama.text
    property alias elama: elama.text

    Kyborgi{
        id: kyborgi
        width: 60
        height: 60
        painettavissa: aktiivinen
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
