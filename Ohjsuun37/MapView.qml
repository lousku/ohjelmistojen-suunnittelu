import QtQuick 2.0
 import QtQuick.Controls 1.4

Rectangle {
    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 100; anchors.topMargin: 100;

    Image {
        id: karttaKuva
        source: "qrc:graphics/TampereMap"
        anchors.fill: parent
    }
    Button{
        x:5
        y:5
        height: 50
        width: 50
        text: "kauppa"
        onClicked: {
            if(parkkihalliId.state == "NORMAL"){
                parkkihalliId.state = "KAUPPA";
            }
            else{
                parkkihalliId.state = "NORMAL";
            }

        }
    }
    //TODO näiden lisäys c++ puolelle
    Pysakointihalli{
        x:150
        y:150
        hallinNumero: 0
    }

    Pysakointihalli{
        x:250
        y:150
        hallinNumero: 1
    }

    Pysakointihalli{
        x:250
        y:300
        hallinNumero: 2
    }

    Pysakointihalli{
        x:350
        y:100
        hallinNumero: 3
    }

    Pysakointihalli{
        x:230
        y:410
        hallinNumero: 4
    }


}
