import QtQuick 2.0

Rectangle {
    id: laura //tarvitseeko edes?
    width: 20
    height: 20
    color: "purple"

    property alias angle: suunta.angle

    transform: Rotation {
        id:suunta
        origin.x:10
        origin.y:10
        angle:0
    }

    //radius: width*0.5  //muutin lauran lapalla palloksi -IH

    property alias text: teksti.text

    Text {
        id: teksti
        text: qsTr("")
    }
}
