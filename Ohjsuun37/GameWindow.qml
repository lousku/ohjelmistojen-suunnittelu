import QtQuick 2.0

Item {

    property bool lauraLiikkuuOikealle: false
    property bool lauraLiikkuuVasemmalle: false
    property bool lauraLiikkuuYlos: false
    property bool lauraLiikkuuAlas: false

    Keys.onPressed: {
        if (event.key === Qt.Key_W){
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
         }
       }

    Keys.onReleased: {
      if(event.isAutoRepeat) return
      if (event.key === Qt.Key_W)lauraLiikkuuYlos = false;
      if (event.key === Qt.Key_S)lauraLiikkuuAlas = false;
      if (event.key === Qt.Key_A)lauraLiikkuuVasemmalle = false;
      if (event.key === Qt.Key_D)lauraLiikkuuOikealle = false ;
    }

    //propertyt, milla valitetaan hiiren sijainti c++:lle
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
