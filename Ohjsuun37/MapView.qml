import QtQuick 2.0
 import QtQuick.Controls 1.4

Rectangle {
    color: "blue"
    anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
    anchors.right: parent.right; anchors.bottom: parent.bottom
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
    }

    Pysakointihalli{
        x:250
        y:150
    }


}
