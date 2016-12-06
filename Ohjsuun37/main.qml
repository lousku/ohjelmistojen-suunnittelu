import QtQuick 2.7
import QtQuick.Window 2.2

Item {
    objectName: "parkkihalli"
    id:parkkihalliId
    width: 600
    height: 600
    focus: false  //Ratkaiseva, jotta painallus huomataan -IH
    state: "ALOITUS"

    Image {
        height: 10
        width:  10
        id: esteKuva
        source: "qrc:graphics/esteLaatta.png"
        fillMode: Image.Tile
        horizontalAlignment: Image.AlignLeft
        verticalAlignment: Image.AlignTop
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
                PropertyChanges { target: mapWindow; visible:true}



            },
            State {
                name: "KAUPPA"
                //piilotetaan muut paitsi kauppaikkuna -MS
                PropertyChanges { target: kauppaIkkuna; visible:true}

            },
            State {
                name: "PELI"
                //piilotetaan muut paitsi peliikkuna -MS
                PropertyChanges { target: gameWindow; visible:true}
                PropertyChanges { target: topBanner; visible: true}

                //PropertyChanges { target: topBanner; palkkinakyvissa: true}

                //huomioidaan painallukset vain peliikkunassa -MS
                PropertyChanges { target: gameWindow; focus: true}


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
        //laitoin hipsuihin, koska tuli herjaa, muuten siis koittaa sijoittaa Rectanglea objectNameen -IH
        objectName: "leftBanner"

        anchors.left: parent.left;anchors.top: parent.top
        anchors.bottom: parent.bottom
    }

    TopBanner{
        id:topBanner
        objectName: "topBanner"
        anchors.left: leftBanner.right; anchors.top: parent.top; anchors.right: parent.right
        visible:false
    }

    GameWindow{
        id: gameWindow
        objectName: "gameWindow"
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        anchors.right: parent.right; anchors.bottom: parent.bottom
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
}
