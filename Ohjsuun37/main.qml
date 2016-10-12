import QtQuick 2.5
import QtQuick.Window 2.2

Item {
    width: 400
    height: 400
    Rectangle{
        anchors.fill:parent
        color: "red"
    }

    Rectangle{
        width: 200
        height: 200
        anchors.centerIn: parent
        color: "blue"
    }
}
