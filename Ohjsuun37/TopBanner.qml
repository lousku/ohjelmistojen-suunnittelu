import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    height: 100

    GridLayout {
        objectName: "palkkirivi"
        visible: true
        anchors.left: parent.left; anchors.top: parent.top;
        anchors.leftMargin: 40; anchors.topMargin: 25;

        Elamamittari{
            objectName: "lauranElamaBar"
            vari: "orange"
            Layout.row: 1
            Layout.column: 0
        }

        Elamamittari{
            objectName: "kyborgi1"
            vari: "lime"
            Layout.column: 1
            Layout.row: 1
        }

        Elamamittari{
            objectName: "kyborgi2"
            vari: "magenta"
            Layout.column: 2
            Layout.row: 1
        }

        Elamamittari{
            objectName: "kyborgi3"
            vari: "royalblue"
            Layout.column: 3
            Layout.row: 1
        }

        Image {
            source: "qrc:graphics/Laura.png"
            Layout.column: 0
        }

        Image {
            source: "qrc:graphics/kyborg_lime.png"
            Layout.column: 1
        }

        Image {
            source: "qrc:graphics/kyborg_magenta.png"
            Layout.column: 2
        }

        Image {
            source: "qrc:graphics/kyborg_royalblue.png"
            Layout.column: 3
        }
    }
}
