import QtQuick 2.0

Rectangle {

    Image {
        height: 10
        width:  10
        id: esteKuva
        source: "qrc:graphics/esteLaatta.png"
        fillMode: Image.Tile
        horizontalAlignment: Image.AlignLeft
        verticalAlignment: Image.AlignTop
        anchors.fill: parent
    }


    property bool lauraLiikkuuOikealle: false
    property bool lauraLiikkuuVasemmalle: false
    property bool lauraLiikkuuYlos: false
    property bool lauraLiikkuuAlas: false

    //TODO liikkuminen vinottain kahdella napilla
    Keys.onPressed: {
        if (event.key == Qt.Key_W){
            if(event.isAutoRepeat) return
            lauraLiikkuuYlos = true;
        }
         if (event.key === Qt.Key_S){
            if(event.isAutoRepeat) return
            lauraLiikkuuAlas = true;
        }
         if (event.key === Qt.Key_A){
            if(event.isAutoRepeat) return
            lauraLiikkuuVasemmalle = true;
        }
         if (event.key === Qt.Key_D){
            if(event.isAutoRepeat) return
            lauraLiikkuuOikealle = true ;
        }
         if (event.key === Qt.Key_Space){
            logiikka.luoAmmus();
            console.log("ammu");
         }
       }

    Keys.onReleased: {
      if(event.isAutoRepeat) return
      if (event.key === Qt.Key_W)lauraLiikkuuYlos = false;
      if (event.key === Qt.Key_S)lauraLiikkuuAlas = false;
      if (event.key === Qt.Key_A)lauraLiikkuuVasemmalle = false;
      if (event.key === Qt.Key_D)lauraLiikkuuOikealle = false ;
    }

    //property valietaan hiiren sijainti c++:lle
    property double hiiriX: 0
    property double hiiriY: 0

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onMouseXChanged: {
            parent.hiiriX = mouseX;
        }
        onMouseYChanged: {
            parent.hiiriY = mouseY;
        }
    }

}
