import QtQuick 2.0

Rectangle {
    id: laura //tarvitseeko edes?
    width: 20
    height: 20
    color: "purple"

    property alias text: teksti.text

    Text {
        id: teksti
        text: qsTr("")
    }
}
