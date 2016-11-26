import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    color: "blue"
    anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
    anchors.right: parent.right; anchors.bottom: parent.bottom

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
        x:5
        y:150
        height: 30
        width: 150
        text: "paranna asetta"
        onClicked: {
            //TODO klikkauksen kutsuva asefunktio
        }
    }
    Button{
        x:5
        y:215
        height: 30
        width: 180
        text: "paranna Lauran nopeutta"
        onClicked: {
            //TODO klikkauksen kutsuva asefunktio
        }
    }
    Button{
        x:5
        y:300
        height: 30
        width: 200
        text: "osta täydet elämät"
        onClicked: {
            //TODO klikkauksen kutsuva funktio
        }
    }
    Text{
        id: kauppaTeksi
        anchors.centerIn: parent
        text: "Kauppa"
    }

}
