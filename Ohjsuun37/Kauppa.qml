import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    color: "blue"
    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 100; anchors.topMargin: 100;

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
            kauppa.elamaaLisaa();
        }
    }
    Button{
        x:220
        y:380
        height: 30
        width: 70
        text: "kantamaa"
        onClicked: {
            kauppa.kantamaaLisaa();
        }
    }
    Button{
        x:70
        y:380
        height: 30
        width: 70
        text: "nopeutta"
        onClicked: {
            kauppa.nopeuttaLisaa();
        }
    }

}
