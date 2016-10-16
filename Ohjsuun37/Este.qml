import QtQuick 2.0

Rectangle {
    id: este //tarvitseeko edes?
    width: 20
    height: 20
    color: "white"
    //sijainnit klikkauksen tietojen valittamiseen
    property int sijaintiY: 0
    property int sijaintiX: 0

    MouseArea {
        anchors.fill: parent
        onClicked: {
            //koordinaatti, jonka tama valittaa on aina 20 kerrroin, +mouseX peraan ja tarkentuu? -IH
            logiikka.liikutaKyborgeja(sijaintiX, sijaintiY);
            console.log(sijaintiX, "  " , sijaintiY);    //debug esimerkki IH

        }
    }
}


