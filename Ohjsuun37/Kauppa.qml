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
            if(paaNakyma.state == "KAUPPA"){
                paaNakyma.state = "NORMAL";
            }
            else{
                paaNakyma.state = "KAUPPA";
            }
        }
    }

    Repeater{
        model: 4
        Column{
            spacing: 5
            x:50 + index * 105
            y:280
            width: 80
        Repeater{
            model: ["fe","fef","vev","gegeg"]
            KaupanNappi{
                ostos: modelData
                tunniste: index

            }

        }


            /*Button{
                anchors.horizontalCenter: parent.horizontalCenter
                height: 20
                width: 70
                text: "Nopeutta"
                onClicked: {
                    kauppa.nopeuttaLisaa(index);
                }
            }
            Button{
                anchors.horizontalCenter: parent.horizontalCenter
                height: 20
                width: 70
                text: "Kantamaa"
                onClicked: {
                    kauppa.kantamaaLisaa(index);
                }
             }
            Button{
                anchors.horizontalCenter: parent.horizontalCenter
                height: 20
                width: 70
                text: "Elämää"
                onClicked: {
                    kauppa.elamaaLisaa(index);
                }
            }*/

        }
    }




    Button{
        x:55
        y:380
        height: 37
        width: 70
        text: "Lataus\nnopeutta"
        onClicked: {
            kauppa.ammustiheyttaLisaa();
        }
    }

    Text{
        y: 450
        id: kauppaTeksti
        text: qsTr("ostit paskaa")
        anchors.horizontalCenter: parent.horizontalCenter
    }


}
