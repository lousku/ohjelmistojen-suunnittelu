import QtQuick 2.0


Item {
    id: vihollinen //tarvitseeko edes?
    width: 20
    height: 20
    property alias text: teksti.text

    Image {
        id: lauraImage
        source: "qrc:graphics/vihollinen.png"
        anchors.fill: parent
    }

    Text {
        id: teksti
        text: qsTr("")
        anchors.top: parent.bottom
    }
}

