import QtQuick 2.0

Rectangle {
    id: este //tarvitseeko edes?
    width: 20
    height: 20
    color: "white"
    //sijainnit klikkauksen tietojen valittamiseen
    //NÄITÄ EI TARVITSE. MouseArean sisällä näihin pääsee käsiksi este.x ja este.y komennoilla
    //property int sijaintiY: 0
    //property int sijaintiX: 0


    MouseArea {
        anchors.fill: parent
        onClicked: {
            //koordinaatti, jonka tama valittaa on aina 20 kerrroin, +mouseX peraan ja tarkentuu? -IH
            logiikka.liikutaKyborgeja(este.x+ mouseX, este.y + mouseY);
            //console.log(sijaintiX, "  " , sijaintiY);    //debug esimerkki IH
            console.log(este.x+ mouseX, "  " , este.y+ mouseY);
        }
    }
}


