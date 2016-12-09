import QtQuick 2.0

Column {
    property alias kuvapolku: kyborgi.kuvapolku
    property alias tunniste: kyborgi.tunniste
    property alias painettavissa: kyborgi.painettavissa

    Kyborgi{
        id: kyborgi
        width: 60
        height: 60
        painettavissa: aktiivinen
    }

    Text {
        text: qsTr("Teho")
        color: "white"
        font.pointSize: 15
    }
    Text {
        text: qsTr("Nopeus")
        color: "white"
        font.pointSize: 15
    }
    Text {
        text: qsTr("Kantama")
        color: "white"
        font.pointSize: 15
    }
    Text {
        text: qsTr("Elämä")
        color: "white"
        font.pointSize: 15
    }
}
