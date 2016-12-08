import QtQuick 2.0
import QtQuick.Layouts 1.3

//vasemman laidan infobanneri -MS

Item{
    width: 150
    property bool sivuPalkkinakyvissa: true
    property bool aktiivinen: false
    visible: true

    GridLayout {
        id: sivuPalkkirivi
        objectName: "sivuPalkkirivi"

        visible: sivuPalkkinakyvissa
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

        Kyborgi{
            width: 60
            height: 60
            painettavissa: aktiivinen
            tunniste: "kyborgi1"
            kuvapolku: "qrc:graphics/kyborg_lime.png"
            Layout.row: 1
        }

        Kyborgi{
            width: 60
            height: 60
            painettavissa: aktiivinen
            tunniste: "kyborgi2"
            kuvapolku: "qrc:graphics/kyborg_magenta.png"
            Layout.row: 2
        }

        Kyborgi{
            width: 60
            height: 60
            painettavissa: aktiivinen
            tunniste: "kyborgi3"
            kuvapolku: "qrc:graphics/kyborg_royalblue.png"
            Layout.row: 3
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

