import QtQuick 2.7
import QtQuick.Window 2.2

Item {
    id: paaNakyma
    width: 700
    height: 650
    state: "ALOITUS"

    Image {
        height: 10
        width:  10
        id: esteKuva
        source: "qrc:graphics/esteLaatta.png"
        fillMode: Image.Tile
        //horizontalAlignment: Image.AlignLeft  //onko turhia?
        //verticalAlignment: Image.AlignTop
        anchors.fill: parent
    }

    states: [
        State {
            name: "ALOITUS"
            //piilotetaan muut paitsi karttaikkuna -MS
            PropertyChanges { target: aloitusnaytto; visible: true}
            PropertyChanges { target: leftBanner; visible: false}

        },
        State {
            name: "NORMAL"
            //piilotetaan muut paitsi karttaikkuna -MS
            PropertyChanges { target: mapWindow; visible: true}

        },
        State {
            name: "HAVITTY"
            PropertyChanges { target: peliHavittyTeksti; visible: true }
        },
        State {
            name: "VOITETTU"
            PropertyChanges { target: peliVoitettuTeksti; visible: true }
        },
        State {
            name: "KAUPPA"
            //piilotetaan muut paitsi kauppaikkuna -MS
            PropertyChanges { target: kauppaIkkuna; visible: true}
            PropertyChanges { target: kauppaIkkuna; ostosTeksti: "" }


        },
        State {
            name: "PELI"
            //piilotetaan muut paitsi peliikkuna -MS
            PropertyChanges { target: gameWindow; visible: true}
            PropertyChanges { target: topBanner;  visible: true}

            PropertyChanges { target: gameWindow; focus: true }
            PropertyChanges { target: leftBanner; aktiivinen: true }



        }
    ]

    //omat tiedostot reunabannerille, sisältää toistaiseksi sekä id että objName -MS
    Aloitusnaytto{
        id:aloitusnaytto
        anchors.fill: parent
        visible:false
    }

    LeftBanner{
        id:leftBanner
        objectName: "leftBanner"
        anchors.left: parent.left;anchors.top: parent.top
        anchors.bottom: parent.bottom
    }

    TopBanner{
        id:topBanner
        objectName: "topBanner"
        anchors.left: leftBanner.right; anchors.top: parent.top; anchors.right: parent.right
        visible: false
    }

    GameWindow{
        id: gameWindow
        objectName: "gameWindow"
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        anchors.right: parent.right; anchors.bottom: parent.bottom
        focus: false
        visible: false

    }

    MapView{
        id:mapWindow
        visible:false
    }
    Kauppa{
        id: kauppaIkkuna
        visible:false
    }

    property alias lopputeksti: peliHavittyTeksti.text

    PeliHavitty{
        id: peliHavittyTeksti
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        visible: false
    }

    property alias voittoteksti: peliVoitettuTeksti.text

    PeliVoitettu{
        id: peliVoitettuTeksti
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        visible: false
    }

    property alias pisteet: pisteTeksti.text

    Row{
        x: 500
        y: 610
        z: 100
        Text {
            text: qsTr("Pisteita: ")
            color: "white"
            font.pointSize: 20
        }

        Text {
            id: pisteTeksti
            text: "0"
            color: "white"
            font.pointSize: 20
        }
    }


}
