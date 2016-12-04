import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    //Alkunaytto joka esitetaan vain peli avauksen yhteydessa

    Button{
        anchors.horizontalCenter: parent.horizontalCenter
        y:500
        width: 100
        height: 50
        text: "Aloita peli"
        onClicked: {
            if(parkkihalliId.state == "ALOITUS"){
                parkkihalliId.state = "NORMAL";
            }            }
    }

    Column{
        spacing: 5
        anchors.horizontalCenter: parent.horizontalCenter
        y:10
        Text {
            id: pelinNimi
            color: "white"
            font.pointSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("PYSÄKÖINTIPEIJAISET 3")
        }
        Text {
            id: pelinAlaNimi
            color: "white"
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Parkkipirkon kosto")
        }
        Text {
            id: tarinaTeksti
            color: "white"
            font.pointSize: 16
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("
Ulkoavaruudesta saapuneet virheät, autoja syövät hirviöt
ovat vallannet tampereen pysäköintitalot. Automaatiotekniikkaa
opiskeleva, sivutyönään pysäköintivalvojan tehtäviä toimittava
Laura on saanut tarpeekseen näistä virheistä tuholaisista ja
lähtee sotajalalle. Mitä enemmän autoja hirviöt ovat saaneet
syödäkseen, sitä viheliäisempiä ne ovat. Ole siis varuillasi!")
        }
    }




    //lauran esittely
    Row{
        spacing: 10
        x:20
        y:240
        Image {
            id: alkuLaura
            source: "qrc:graphics/Laura.png"
            width: 60
            height: 60
        }

        Text {
            id: alkuLauraTexti
            color: "white"
            font.pointSize: 17
            font.bold: true
            text: qsTr("Tämä on Laura, pelin suuri sankaritar, joka on tullut
pelastamaan Tampereen pysäköintihallit virheiltä hirviöiltä.
Laura käyttää futuristista asettaan tehtävää suorittaessaan.")
        }

    }

    Row{
        spacing: 10
        x:20
        y:320
        Image {
            id: alkuKyborgi
            source: "qrc:graphics/kyborg_lime.png"
            width: 60
            height: 60
        }

        Text {
            id: alkuKyborgiTeksti
            color: "white"
            font.pointSize: 17
            font.bold: true
            text: qsTr("Lauralla on apunaan kolme kyborgia.
Kyborgeja pääset käskyttämään klikkaamalla niitä ja
klikkaamalla kartan kohtaa, jonne haluat kyborgin liikkuvan")
        }

    }
    Row{
        spacing: 10
        x:20
        y:400
        Image {
            id: alkuVihollinen
            source: "qrc:graphics/vihollinen.png"
            width: 60
            height: 60
        }

        Text {
            id: alkuVihollinenTeksti
            color: "white"
            font.pointSize: 17
            font.bold: true
            text: qsTr("Vihreät hirviöt parveilevat pysäköintihalleissa, tuhoa
ne Lauran asestta hyväksikäyttäen tai käskyttämällä
kyborgi niiden kimppuun! ")
        }

    }



}
