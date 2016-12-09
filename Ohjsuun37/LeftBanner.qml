import QtQuick 2.0
import QtQuick.Layouts 1.3

//vasemman laidan infobanneri -MS

Item{
    width: 150
    property bool aktiivinen: false
    visible: true
    anchors{ bottomMargin: 20;   topMargin: 20 }


    Column {
        spacing: 15
        objectName: "sivuPalkkirivi"
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors { horizontalCenter: parent.horizontalCenter }

        LauraTiedot{

        }

        Repeater{
            objectName: "repeater"
            model: ["lime", "magenta", "royalblue"]
            Tiedot{
                tunniste: "kyborgi" + (index + 1)
                kuvapolku: "qrc:graphics/kyborg_" + modelData + ".png"
                Layout.row: index + 1
                painettavissa: aktiivinen
            }
        }
    }
}

