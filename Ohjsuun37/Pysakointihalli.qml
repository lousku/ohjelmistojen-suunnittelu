import QtQuick 2.0

//kartalla näkyvä pysäköintihallilogo joka käynnistää pelin -MS
//TODO kuinka eri kentät erotellaan?

Rectangle{
    width: 30
    height: 30
    color: "white" //tarviiko? -IH

    property int hallinNumero: 0

    Image {
        id: parkkihalliLogo
        source: "qrc:graphics/pysakointihalliLogo.jpg"
        anchors.fill: parent
    }

    MouseArea{
        //jos klikataan uusi peli on syytä alustaa
        //kutsutaan jotain ISONLOGIIKAN alustajaa c++ puolella
        anchors.fill: parent
        onClicked: {
            if(parkkihalliId.state == "NORMAL"){
                parkkihalliId.state = "PELI";
            }
            else{
                parkkihalliId.state = "NORMAL";
            }

            //KUTSUMINEN TAPAHTUU TÄSSÄ -IH
            logiikka.luoPeli(hallinNumero);
        }
    }
}
