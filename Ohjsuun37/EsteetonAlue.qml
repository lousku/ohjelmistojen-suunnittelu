import QtQuick 2.0

Rectangle{
    id: esteeton
    width: 20
    height: 20
    color: "white"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKyborginPaamaara(esteeton.x+ mouseX, esteeton.y + mouseY);
        }
    }
}


