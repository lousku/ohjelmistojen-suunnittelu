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
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:false}
                PropertyChanges { target: kauppaIkkuna; visible:false}
                PropertyChanges { target: topBanner; palkkinakyvissa: false}
                PropertyChanges { target: aloitusnaytto; visible: true}


                //huomioidaan painallukset vain karttaikkunassa -MS
                PropertyChanges { target: parkkihalliId; focus: false}
                PropertyChanges { target: kauppaIkkuna; focus: false}
                PropertyChanges { target: gameWindow; focus: false}
                PropertyChanges { target: aloitusnaytto; focus: false}
                PropertyChanges { target: mapWindow; focus: false}


            },
            State {
                name: "NORMAL"
                //piilotetaan muut paitsi karttaikkuna -MS
                PropertyChanges { target: mapWindow; visible:true}
                PropertyChanges { target: gameWindow; visible:false}
                PropertyChanges { target: kauppaIkkuna; visible:false}
                PropertyChanges { target: topBanner; visible: true}
                PropertyChanges { target: aloitusnaytto; visible: false}


                //huomioidaan painallukset vain karttaikkunassa -MS
                PropertyChanges { target: parkkihalliId; focus: false}
                PropertyChanges { target: mapWindow; focus: true}
                PropertyChanges { target: kauppaIkkuna; focus: false}
                PropertyChanges {target: gameWindow; focus: false}
                PropertyChanges { target: aloitusnaytto; focus: false}


            },
            State {
                name: "KAUPPA"
                //piilotetaan muut paitsi kauppaikkuna -MS
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:false}
                PropertyChanges { target: kauppaIkkuna; visible:true}
                PropertyChanges { target: topBanner; palkkinakyvissa: false}
                PropertyChanges { target: aloitusnaytto; visible: false}


                //huomioidaan painallukset vain kauppaikkunassa -MS
                PropertyChanges { target: mapWindow; focus: false}
                PropertyChanges { target: parkkihalliId; focus: false}
                PropertyChanges { target: kauppaIkkuna; focus: true}
                PropertyChanges { target: aloitusnaytto; focus: false}
                PropertyChanges { target: gameWindow; focus: false}




            },
            State {
                name: "PELI"
                //piilotetaan muut paitsi peliikkuna -MS
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:true}
                PropertyChanges { target: kauppaIkkuna; visible:false}
                PropertyChanges { target: topBanner; palkkinakyvissa: true}
                PropertyChanges { target: aloitusnaytto; visible: false}

                //huomioidaan painallukset vain peliikkunassa -MS
                PropertyChanges { target: mapWindow; focus: false}
                PropertyChanges { target: gameWindow; focus: true}
                PropertyChanges { target: kauppaIkkuna; focus: false}
                PropertyChanges { target: aloitusnaytto; focus: false}
                PropertyChanges { target: parkkihalliId; focus: false}

        }
    ]

    //omat tiedostot reunabannerille, sisältää toistaiseksi sekä id että objName -MS
    Aloitusnaytto{
        id:aloitusnaytto
        anchors.fill: parent
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
    }

    GameWindow{
        id: gameWindow
        objectName: "gameWindow"
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        anchors.right: parent.right; anchors.bottom: parent.bottom
        visible: false


        //WASD liikkuminen -MS


        property bool lauraLiikkuuOikealle: false
        property bool lauraLiikkuuVasemmalle: false
        property bool lauraLiikkuuYlos: false
        property bool lauraLiikkuuAlas: false

        //TODO liikkuminen vinottain kahdella napilla
        Keys.onPressed: {
            if (event.key == Qt.Key_W){
                if(event.isAutoRepeat) return
                lauraLiikkuuYlos = true;
            }
             if (event.key == Qt.Key_S){
                if(event.isAutoRepeat) return
                lauraLiikkuuAlas = true;
            }
             if (event.key == Qt.Key_A){
                if(event.isAutoRepeat) return
                lauraLiikkuuVasemmalle = true;
            }
             if (event.key == Qt.Key_D){
                if(event.isAutoRepeat) return
                lauraLiikkuuOikealle = true ;
            }
             if (event.key == Qt.Key_Space){
                logiikka.luoAmmus();
             }

             console.log("ylos: " + lauraLiikkuuYlos + " oikea: " + lauraLiikkuuOikealle);

           }

        Keys.onReleased: {
          if(event.isAutoRepeat) return
          if (event.key == Qt.Key_W)lauraLiikkuuYlos = false;
          if (event.key == Qt.Key_S)lauraLiikkuuAlas = false;
          if (event.key == Qt.Key_A)lauraLiikkuuVasemmalle = false;
          if (event.key == Qt.Key_D)lauraLiikkuuOikealle = false ;
        }

        //property valietaan hiiren sijainti c++:lle
        property double hiiriX: 0
        property double hiiriY: 0

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onMouseXChanged: {
                parent.hiiriX = mouseX;
            }
            onMouseYChanged: {
                parent.hiiriY = mouseY;
            }
        }
    }

    MapView{
        id:mapWindow
        visible:true
    }
    Kauppa{
        id: kauppaIkkuna
        visible:false
    }
}
