import QtQuick 2.0


Item {
    id: laura //tarvitseeko edes?
    objectName: "laura"
    width: 20
    height: 20
    z: 100  //tällä lauran saa jäämään päällimmäiseksi

    property alias angle: suunta.angle

    transform: Rotation {
        id:suunta
        origin.x:10
        origin.y:10
        angle:0
    }
//Lauran hahmon kuva -MS
    Image {
        id: lauraImage
        source: "qrc:graphics/Laura.png"
        anchors.fill: parent
    }

    //radius: width*0.5  //muutin lauran lapalla palloksi -IH

    property alias text: teksti.text

        //elämäteksti piilotettu -MS

    Text {
        id: teksti
        text: qsTr("")
        anchors.top: parent.bottom
    }
}
