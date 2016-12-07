import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    height: 100

    property alias palkkinakyvissa: palkkirivi.visible  //tarvitaanko? -IH

    GridLayout {
        id: palkkirivi
        objectName: "palkkirivi"
        visible: true
        anchors.left: parent.left; anchors.top: parent.top;
        anchors.leftMargin: 20; anchors.topMargin: 20;

        Elamamittari{
            objectName: "lauranElamaBar"
            vari: "orange" //TODO parempi vari?
            Layout.row: 1
            Layout.column: 0
        }

        Elamamittari{
            objectName: "kyborgi1"
            vari: "lime"
            property int paikka: 1
            Layout.column: paikka
            Layout.row: 1
        }

        Elamamittari{
            objectName: "kyborgi2"
            vari: "magenta"
            property int paikka: 2
            Layout.column: paikka
            Layout.row: 1
        }
        Elamamittari{
            objectName: "kyborgi3"
            vari: "royalblue"
            property int paikka: 3
            Layout.column: paikka
            Layout.row: 1
        }

        Image {
            id: lauraKuva
            source: "qrc:graphics/Laura.png"
            Layout.column: 0
        }

        Image {
            id: tunnuskuva1
            source: "qrc:graphics/kyborg_lime.png"
            Layout.column: 1
            //TODO ANKKURIT?
        }

        Image {
            id: tunnuskuva2
            source: "qrc:graphics/kyborg_magenta.png"
            Layout.column: 2
        }

        Image {
            id: tunnuskuva3
            source: "qrc:graphics/kyborg_royalblue.png"
            Layout.column: 3
        }


    }
}
