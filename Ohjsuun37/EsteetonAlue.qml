import QtQuick 2.0

//peli-ikkunan esteetön alue eli "lattia" -MS
Rectangle{
    id: esteeton
    width: 20
    height: 20
    color: "white"

    Image {
        id: lattiaKuva
        source: "qrc:graphics/lattiaLaatta.png"
        anchors.fill: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKyborginPaamaara(esteeton.x+ mouseX, esteeton.y + mouseY);
        }
    }
}


