import QtQuick 2.0

//vasemman laidan infobanneri -MS
Item {
    width: 100

    //TODO jotain vähän fiksumpaa ulkoasua tänne
    Text {
        x: 20
        y: 50
        id: pisteet
        text: qsTr("Pisteitä: ")
        color: "red"
        font.pointSize: 20
    }
}
