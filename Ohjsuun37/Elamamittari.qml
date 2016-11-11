import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4  //jos halutaan muokata progress baria

ProgressBar {

    property string vari: "steelblue"
    property int reunanleveys: 3

    style: ProgressBarStyle {
        background: Rectangle {
            id: sisalto
            radius: 2
            color: "white"
            border.color: vari
            border.width: reunanleveys
            implicitWidth: 100
            implicitHeight: 16

        }

    }
}
