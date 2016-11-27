import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    color: "blue"
    anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
    anchors.right: parent.right; anchors.bottom: parent.bottom

    Image {
        id: kauppaKuva
        source: "qrc:graphics/kauppa.png"
        anchors.fill: parent
    }
    Button{
        x:5
        y:5
        height: 50
        width: 150
        text: "poistu kaupasta"
        onClicked: {
            if(parkkihalliId.state == "KAUPPA"){
                parkkihalliId.state = "NORMAL";
            }
            else{
                parkkihalliId.state = "KAUPPA";
            }
        }
    }
    Button{
        x:380
        y:380
        height: 30
        width: 50
        text: "elämää"
        onClicked: {
            //TODO klikkauksen kutsuva asefunktio
        }
    }
    Button{
        x:220
        y:380
        height: 30
        width: 70
        text: "kantamaa"
        onClicked: {
            //TODO klikkauksen kutsuva asefunktio
        }
    }
    Button{
        x:70
        y:380
        height: 30
        width: 70
        text: "nopeutta"
        onClicked: {
            //TODO klikkauksen kutsuva funktio
        }
    }

}
