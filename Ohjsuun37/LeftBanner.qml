import QtQuick 2.0

//vasemman laidan infobanneri -MS
Rectangle {
    width: 100
    color: "red"
    Text {
        id: leftBanText
        text: qsTr("LeftBanner")
        anchors.centerIn: parent
    }
}
