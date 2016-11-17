import QtQuick 2.0

Rectangle {
    id: kyborgi //tarvitseeko edes?
    width: 20
    height: 20

    property alias text: teksti.text
    property string tunniste: ""
    property int reunanpaksuus: 0

    border.color: "black"
    border.width: reunanpaksuus


    Text {
        id: teksti
        text: qsTr("")
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKaskettava(tunniste);
        }
    }
}
