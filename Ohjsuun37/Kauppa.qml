import QtQuick 2.0
import QtQuick.Controls 1.4

//yksi kolmesta päänäkymästä -MS
Rectangle {
    anchors.left: parent.left; anchors.top: parent.top;
    anchors.right: parent.right; anchors.bottom: parent.bottom;
    anchors.rightMargin: 50; anchors.bottomMargin: 50;
    anchors.leftMargin: 150; anchors.topMargin: 100;

    property alias ostosTeksti: kauppaTeksti.text

    Image {
        id: kauppaKuva
        source: "qrc:graphics/Kauppa2.0.png"
        anchors.fill: parent
    }
    Button{
        x:15
        y:15
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

    Text {
        x: 275
        y: 15
        id: pisteet
        text: qsTr("Kymppitiistai, kaikki\nmaksaa 16 pistettä")
        color: "white"
        font.pointSize: 20
    }

    Repeater{
        model: 4
        Column{
            spacing: 5
            x:50 + index * 105
            y:280
            width: 80

            KaupanNappi{
                tunniste: index
                text: "Tehoa"
                onClicked: {
                    if (kauppa.tehoaLisaa(index)){
                        console.log(kyseessa + "lle ostettu tehoa")
                    }else{
                        console.log(kyseessa + "n teho on jo täynnä")
                    }
                }
            }

            KaupanNappi{
                tunniste: index
                text: "Nopeutta"
                onClicked: {
                    if (kauppa.nopeuttaLisaa(index)){
                        console.log(kyseessa + "lle ostettu nopeutta")
                    }else{
                        console.log(kyseessa + "n on jo nopein mahdollinen")
                    }
                }
            }
            KaupanNappi{
                tunniste: index
                text: "Kantamaa"
                onClicked: {
                    if (kauppa.kantamaaLisaa(index)){
                        console.log(kyseessa + "lle ostettu kantamaa")
                    }else{
                        console.log(kyseessa + "n kantama on maksimissa")
                    }
                }
            }
            KaupanNappi{
                tunniste: index
                text: "Elämää"
                onClicked: {
                    if (kauppa.elamaaLisaa(index)){
                        kauppaTeksti.text = kyseessa + "lle ostettu lisää elamää"
                    }else{
                        kauppaTeksti.text = kyseessa + "n elämötaso on jo maksimi"
                    }
                }
            }

        }
    }



    Button{
        x:55
        y:380
        height: 37
        width: 70
        text: "Lataus\nnopeutta"
        onClicked: {
            if (kauppa.ammustiheyttaLisaa()){
                kauppaTeksti.text = "Lauralle ostettu nopeutta"
            }else{
                kauppaTeksti.text = "Lauran nopeus on jo maksimissaan"
            }
        }
    }

    Text{
        y: 450
        id: kauppaTeksti
        text: qsTr("")
        anchors.horizontalCenter: parent.horizontalCenter
    }


}
