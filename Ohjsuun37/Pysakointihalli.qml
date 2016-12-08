import QtQuick 2.0

//kartalla näkyvä pysäköintihallilogo joka käynnistää pelin -MS

Rectangle{
    width: 30
    height: 30

    property int hallinNumero: 0

    Image {
        source: "qrc:graphics/pysakointihalliLogo.jpg"
        anchors.fill: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            if(paaNakyma.state == "NORMAL"){
                paaNakyma.state = "PELI";
            }
            else{
                paaNakyma.state = "NORMAL";
                console.log("taa kannattaa pitaa taalla")   //testailua, etta onko else haara turha.
            }
            logiikka.luoPeli(hallinNumero);
        }
    }
}
