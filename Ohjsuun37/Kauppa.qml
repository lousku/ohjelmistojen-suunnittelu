import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 100; anchors.topMargin: 100;

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
        spacing: 5
        x:50
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(0);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 85
            text: "Nopea lataus"
            onClicked: {
                //kohde 0 = laura
                kauppa.ammusTiheyttaLisaa();
            }
        }
    }
    //Kyborgi1 ostopainikkeet -MS
    Column{
        spacing: 5
        x:130
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(0);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(0);
            }
        }
    }
    //kyborgi2 painikkeet
    Column{
        spacing: 5
        x:230
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(0);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(0);
            }
        }
    }
    //kyborgi3 painikkeet
    Column{
        spacing: 5
        x:320
        y:250
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(0);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(0);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(0);
            }
        }
    }



}
