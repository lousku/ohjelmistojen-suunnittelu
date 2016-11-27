import QtQuick 2.0

//vasemman laidan infobanneri -MS
Rectangle {
    width: 100
    color: "red"
    Image {
        height: 10
        width:  10
        id: ylaBanneriKuva
        source: "qrc:graphics/esteLaatta.png"
        fillMode: Image.Tile
        horizontalAlignment: Image.AlignLeft
        verticalAlignment: Image.AlignTop
        anchors.fill: parent
    }

}
