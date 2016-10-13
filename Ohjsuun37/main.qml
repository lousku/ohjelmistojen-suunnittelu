import QtQuick 2.5
import QtQuick.Window 2.2

Item {
    width: 600
    height: 600
    //omat tiedostot reunabannerille, sisältää toistaiseksi sekä id että objName -MS
    LeftBanner{
        id:leftBanner
        objectName: leftBanner

        anchors.left: parent.left;anchors.top: parent.top
        anchors.bottom: parent.bottom
    }
    TopBanner{
        id:topBanner
        objectName: topBanner
        anchors.left: leftBanner.right; anchors.top: parent.top; anchors.right: parent.right
    }
    GameWindow{
        id: gameWindow
        objectName: gameWindow
        anchors.left: leftBanner.right; anchors.top: topBanner.bottom;
        anchors.right: parent.right; anchors.bottom: parent.bottom
    }


}
