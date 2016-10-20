import QtQuick 2.0

Rectangle {
    id: kyborgi //tarvitseeko edes?
    width: 20
    height: 20
    color: "yellow"

    property alias text: teksti.text
    property int tunniste: -1

    Text {
        id: teksti
        text: qsTr("")
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKaskettava(tunniste);
            console.log("este.x+ mouseX, ");
        }
    }
}
