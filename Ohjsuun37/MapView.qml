import QtQuick 2.0
 import QtQuick.Controls 1.4

Rectangle {
    width: 500
    height: 500

    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 150; anchors.topMargin: 100;

    Image {
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
            if(paaNakyma.state == "NORMAL"){
                paaNakyma.state = "KAUPPA";
            }
            else{
                paaNakyma.state = "NORMAL";
            }

        }
    }
    //TODO hallien sijoittelu oikeille paikoille!!
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
