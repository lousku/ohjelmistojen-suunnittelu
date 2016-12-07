import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4  //jos halutaan muokata progress baria

ProgressBar {

    property string vari: "blue"
    property int reunanleveys: 4
    minimumValue: 0
    maximumValue: 1000

    style: ProgressBarStyle {
        background: Rectangle {
            id: sisalto
            radius: 2
            color: "white"
            border.color: vari
            border.width: reunanleveys
            implicitWidth: 100
            implicitHeight: 18

        }

    }
}
