import QtQuick 2.0

Item {
    id: kyborgi //tarvitseeko edes?
    width: 20
    height: 20

    property alias text: teksti.text
    property string kuvapolku: "qrc:graphics/kyborg.png"
    property string tunniste: ""

    // nyt kyborgi kasvaa hieman kun se on valittu -MS

    Image {
        id: kyborgiImage  //muutin LauraImagesta kun tais olla typo -IH
        source: kuvapolku
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
