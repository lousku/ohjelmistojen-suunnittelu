import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 150; anchors.topMargin: 100;

    Image {
        id: kauppaKuva
        source: "qrc:graphics/Kauppa2.0.png"
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



    //lauran ostopainikkeet -MS
    Column{
        spacing: 10
        x:50
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa();
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa();
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 50
            text: "elämää"
            onClicked: {
                kauppa.elamaaLisaa();
            }
        }
    }
    //Kyborgi1 ostopainikkeet -MS
    Column{
        spacing: 10
        x:130
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa();
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.kantamaaLisaa();
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 50
            text: "elämää"
            onClicked: {
                kauppa.elamaaLisaa();
            }
        }
    }
    //kyborgi2 painikkeet
    Column{
        spacing: 10
        x:230
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa();
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.kantamaaLisaa();
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 50
            text: "elämää"
            onClicked: {
                kauppa.elamaaLisaa();
            }
        }
    }
    //kyborgi3 painikkeet
    Column{
        spacing: 10
        x:320
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa();
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.kantamaaLisaa();
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            width: 50
            text: "elämää"
            onClicked: {
                kauppa.elamaaLisaa();
            }
        }
    }



}
