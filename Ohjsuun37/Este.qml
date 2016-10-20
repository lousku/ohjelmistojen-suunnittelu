import QtQuick 2.0

Rectangle{
    id: este
    width: 20
    height: 20
    color: "white"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            logiikka.asetaKyborginPaamaara(este.x+ mouseX, este.y + mouseY);
            //console.log(sijaintiX, "  " , sijaintiY);    //debug esimerkki IH
            console.log(este.x+ mouseX, "  " , este.y+ mouseY);
        }
    }
}


