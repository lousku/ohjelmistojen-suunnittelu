import QtQuick 2.0

//Ylälaidan infobanneri -MS
Rectangle {
    height: 100
    color: "green"
    Text {
        id: topBannerText
        text: qsTr("TopBanner")
        anchors.centerIn: parent
    }
}
