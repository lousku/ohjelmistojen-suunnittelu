import QtQuick 2.7
import QtQuick.Window 2.2

Item {
    objectName: "parkkihalli"
    id:parkkihalliId
    width: 600
    height: 600
    state: "NORMAL"

    states: [
            State {
                name: "NORMAL"
                //piilotetaan muut paitsi karttaikkuna -MS
                PropertyChanges { target: mapWindow; visible:true}
                PropertyChanges { target: gameWindow; visible:false}
                PropertyChanges { target: kauppaIkkuna; visible:false}
                PropertyChanges { target: topBanner; palkkinakyvissa: false}


                //huomioidaan painallukset vain karttaikkunassa -MS
                PropertyChanges { target: parkkihalliId; focus: true}
                PropertyChanges { target: kauppaIkkuna; focus: false}
                PropertyChanges { target: gameWindow; focus: true}


            },
            State {
                name: "KAUPPA"
                //piilotetaan muut paitsi kauppaikkuna -MS
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:false}
                PropertyChanges { target: kauppaIkkuna; visible:true}
                PropertyChanges { target: topBanner; palkkinakyvissa: false}


                //huomioidaan painallukset vain kauppaikkunassa -MS
                PropertyChanges { target: mapWindow; focus: false}
                PropertyChanges { target: parkkihalliId; focus: false}
                PropertyChanges { target: kauppaIkkuna; focus: true}


            },
            State {
                name: "PELI"
                //piilotetaan muut paitsi peliikkuna -MS
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:true}
                PropertyChanges { target: kauppaIkkuna; visible:false}
                PropertyChanges { target: topBanner; palkkinakyvissa: true}

                //huomioidaan painallukset vain peliikkunassa -MS
                PropertyChanges { target: mapWindow; focus: false}
                PropertyChanges { target: gameWindow; focus: true}
                PropertyChanges { target: kauppaIkkuna; focus: false}

        }
    ]

    //omat tiedostot reunabannerille, sisältää toistaiseksi sekä id että objName -MS
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

             //console.log("ylos: " + lauraLiikkuuYlos + " oikea: " + lauraLiikkuuOikealle);
           }

        Keys.onSpacePressed: {
            logiikka.luoAmmus();
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
