import QtQuick 2.5
import QtQuick.Window 2.2

Item {
    objectName: "jee"
    width: 600
    height: 600
    focus: true  //Ratkaiseva, jotta painallus huomataan IH

    Keys.onLeftPressed: {
        logiikka.liikutaLauraa();
    }
    Keys.onRightPressed: {
    }

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

        MouseArea {
                anchors.fill: parent
                onClicked: {
                    logiikka.liikutaKyborgeja(mouseX, mouseY);
                    //console.log(mouseX, "  " , mouseY);    //debug esimerkki IH
                }
            }
    }


}
