import QtQuick 2.0
import QtQuick.Layouts 1.3

//vasemman laidan infobanneri -MS

Item{
    width: 150
    property bool aktiivinen: false
    visible: true

    GridLayout {
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors { horizontalCenter: parent.horizontalCenter }

        Text {
            //x: 20
            //y: 50
            id: pisteet
            text: qsTr("Pisteitä: ")
            color: "red"
            font.pointSize: 20
            Layout.row: 0
        }

        Repeater{
            model: ["lime", "magenta", "royalblue"]
            Kyborgi{
                width: 60
                height: 60

                property int nro: index + 1
                painettavissa: aktiivinen
                tunniste: "kyborgi" + nro
                kuvapolku: "qrc:graphics/kyborg_" + modelData + ".png"
                Layout.row: nro
            }
        }


        Text {
            id: hp
            text: qsTr("MAX HP \n100 ")
            color: "red"
            font.pointSize: 20
            Layout.row: 4
            font.bold: true
        }
    }
}

