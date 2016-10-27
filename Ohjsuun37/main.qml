import QtQuick 2.5
import QtQuick.Window 2.2

Item {
    objectName: "parkkihalli"
    id:parkkihalliId
    width: 600
    height: 600
    focus: true  //Ratkaiseva, jotta painallus huomataan -IH
    state: "NORMAL"
    //TODO valittaa jotain mika kertoo painalluksen -IH
    Keys.onLeftPressed: {
        logiikka.kaannaLauraa("vasen");
    }
    Keys.onRightPressed: {
        logiikka.kaannaLauraa("oikea");
    }
    Keys.onUpPressed: {
        logiikka.liikutaLauraa();
    }
    Keys.onSpacePressed: {
        logiikka.luoAmmus();
    }

    states: [
            State {
                name: "NORMAL"
                PropertyChanges { target: mapWindow; visible:true}
                PropertyChanges { target: gameWindow; visible:false}
                //lisatty, jottei karttanakymassa nappaimilla voi viela kaataa! -IH
                PropertyChanges { target: parkkihalliId; focus: false}
            },
            State {
                name: "PELI"
                PropertyChanges { target: mapWindow; visible:false}
                PropertyChanges { target: gameWindow; visible:true}
                PropertyChanges { target: parkkihalliId; focus: true}
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
        }

    MapView{
        id:mapWindow
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        anchors.right: parent.right; anchors.bottom: parent.bottom
        visible:true
            Rectangle{
                width: 60
                height: 60
                x:20
                y:20
                color: "white"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(parkkihalliId.state == "NORMAL"){
                            parkkihalliId.state = "PELI";
                        }
                        else{
                            parkkihalliId.state = "NORMAL";
                        }

                        logiikka.luoPeli();
                    }
                }
            }
    }
}
