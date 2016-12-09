import QtQuick 2.0

Item {
    width: 20
    height: 20

    property bool painettavissa: true
    property alias text: teksti.text
    property string kuvapolku: "qrc:graphics/kyborg.png"
    property string tunniste: ""

    Image {
        source: kuvapolku
        anchors.fill: parent
    }

    Text {
        id: teksti
        anchors.top: parent.bottom
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (painettavissa){
                logiikka.asetaKaskettava(tunniste);
            }
        }
    }
}
