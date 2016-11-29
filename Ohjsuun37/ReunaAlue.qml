import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    height: 550
    width: 550
    color: "green"

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


    property alias palkkinakyvissa: palkkirivi.visible
    property alias lauranElama: lauranElamaBar.value

    GridLayout {
        id: palkkirivi
        objectName: "palkkirivi"
        visible: false

        Elamamittari{
            //id: kyborgi1 //tata ei valttamatta tarvita -IH
            objectName: "kyborgi1"
            vari: "darkorange"
            property int paikka: 0
            Layout.column: paikka
        }

        Elamamittari{
            id: kyborgi2
            objectName: "kyborgi2"
            vari: "salmon"
            property int paikka: 1
            Layout.column: paikka
        }
        Elamamittari{
            id: kyborgi3
            objectName: "kyborgi3"
            vari: "gold"
            property int paikka: 2
            Layout.column: paikka
        }

        Elamamittari{
            id: lauranElamaBar
            vari: "purple"
            Layout.row: 1
            implicitHeight: 25
        }
    }
}
