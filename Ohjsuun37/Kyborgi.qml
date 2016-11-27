import QtQuick 2.0

Item {
    id: kyborgi //tarvitseeko edes?
    width: 20
    height: 20

    property alias text: teksti.text
    property string tunniste: ""
   // property int reunanpaksuus: 0

    // nyt kyborgi kasvaa hieman kun se on valittu -MS

   // border.color: "black"
   // border.width: reunanpaksuus

    Image {
        id: lauraImage
        source: "qrc:graphics/kyborg.png"
        anchors.fill: parent
    }

    Text {
        id: teksti
        text: qsTr("")
        anchors.top: parent.bottom
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKaskettava(tunniste);
        }
    }
}
