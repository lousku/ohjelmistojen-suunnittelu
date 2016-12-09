import QtQuick 2.0
import QtQuick.Layouts 1.3

//vasemman laidan infobanneri -MS


Column {
    width: 150
    property bool aktiivinen: false
    visible: true
    anchors{ bottomMargin: 20;   topMargin: 20; leftMargin: 40; }

    spacing: 15

    LauraTiedot{
        objectName: "LauranTiedot"

    }

    KyborgiTiedot{
        tunniste: "kyborgi1"
        objectName: "kyborgin1Tiedot"
        kuvapolku: "qrc:graphics/kyborg_lime.png"
        painettavissa: aktiivinen
    }

    KyborgiTiedot{
        tunniste: "kyborgi2"
        objectName: "kyborgin2Tiedot"
        kuvapolku: "qrc:graphics/kyborg_magenta.png"
        painettavissa: aktiivinen
    }

    KyborgiTiedot{
        tunniste: "kyborgi3"
        objectName: "kyborgin3Tiedot"
        kuvapolku: "qrc:graphics/kyborg_royalblue.png"
        painettavissa: aktiivinen
    }
}


