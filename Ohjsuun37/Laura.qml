import QtQuick 2.0


Item {
    id: laura //tarvitseeko edes?
    objectName: "laura"
    width: 20
    height: 20
    z: 100  //tällä laura jää aina päällimmäiseksi

    property alias angle: suunta.angle
    property alias text: teksti.text


//Lauran hahmon kuva -MS
    Image {
        id: lauraImage
        source: "qrc:graphics/Laura.png"
        anchors.fill: parent

        transform: Rotation {
            id:suunta
            origin.x:10
            origin.y:10
            angle:0
        }
    }

    Text {
        id: teksti
        anchors.top: parent.bottom
    }
}
