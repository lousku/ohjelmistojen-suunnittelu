import QtQuick 2.0

Rectangle {
    id: este //tarvitseeko edes?
    width: 20
    height: 20
    color: "white"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            //koordinaatti, jonka tama valittaa ei viela toimi?
            logiikka.liikutaKyborgeja(mouseX+ x, mouseY+ y);
            console.log(mouseX, "  " , mouseY);    //debug esimerkki IH
        }
    }
}


