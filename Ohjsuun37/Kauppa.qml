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
        spacing: 5
        x:50
        y:280
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
                kauppa.ammustiheyttaLisaa();
            }
        }
    }
    //Kyborgi1 ostopainikkeet -MS
    Column{
        spacing: 5
        x:150
        y:280
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(1);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(1);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(1);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(1);
            }
        }
    }
    //kyborgi2 painikkeet
    Column{
        spacing: 5
        x:260
        y:280
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(2);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(2);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(2);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //kohde 0 = laura
                kauppa.elamaaLisaa(2);
            }
        }
    }
    //kyborgi3 painikkeet
    Column{
        spacing: 5
        x:360
        y:280
        width: 80
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "Tehoa"
            onClicked: {
                kauppa.tehoaLisaa(3);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "nopeutta"
            onClicked: {
                kauppa.nopeuttaLisaa(3);
            }
        }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 70
            text: "kantamaa"
            onClicked: {
                kauppa.kantamaaLisaa(3);
            }
         }
        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            height: 20
            width: 50
            text: "elämää"
            onClicked: {
                //TODO samaan tyyliin OPASTETEKSTIT
                if(kauppa.elamaaLisaa(3)){
                    kauppaTeksti.text = "Ostit kyborgille 3 elamää"
                }else{
                    kauppaTeksti.text = "Kyborgin 3 elämät täynnä"
                }

            }
        }
    }

    Text{
        y: 450
        id: kauppaTeksti
        text: qsTr("ostit paskaa")
        anchors.horizontalCenter: parent.horizontalCenter
    }


}
