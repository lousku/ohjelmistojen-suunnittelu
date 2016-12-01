import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    height: 100

    property alias palkkinakyvissa: palkkirivi.visible
    property alias lauranElama: lauranElamaBar.value

    GridLayout {
        id: palkkirivi
        objectName: "palkkirivi"
        visible: false
        anchors.left: parent.left; anchors.top: parent.top;
        anchors.leftMargin: 20; anchors.topMargin: 20;

        Elamamittari{
            id: lauranElamaBar
            vari: "purple"
            //Layout.row: 1
            Layout.column: 0
            implicitHeight: 25
        }

        Elamamittari{
            //id: kyborgi1 //tata ei valttamatta tarvita -IH
            objectName: "kyborgi1"
            vari: "darkorange"
            property int paikka: 1
            Layout.column: paikka
        }

        Elamamittari{
            id: kyborgi2
            objectName: "kyborgi2"
            vari: "salmon"
            property int paikka: 2
            Layout.column: paikka
        }
        Elamamittari{
            id: kyborgi3
            objectName: "kyborgi3"
            vari: "gold"
            property int paikka: 3
            Layout.column: paikka
        }

        //TODO jotain vähän fiksumpaa ulkoasua tänne
        Text {
            id: pisteet
            text: qsTr("Pisteitä: ")
            Layout.column: 4
        }


    }
}
