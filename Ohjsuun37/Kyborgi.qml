import QtQuick 2.0

Rectangle {
    id: kyborgi //tarvitseeko edes?
    width: 20
    height: 20
    color: "yellow"

    property alias text: teksti.text

    Text {
        id: teksti
        text: qsTr("")
    }
}
