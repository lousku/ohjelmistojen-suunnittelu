import QtQuick 2.0

Rectangle {
    id: vihollinen //tarvitseeko edes?
    width: 20
    height: 20
    color: "orange"


    property alias text: teksti.text

    Text {
        id: teksti
        text: qsTr("")
    }
}
