import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4  //jos halutaan muokata progress baria

Rectangle {
    height: 100
    color: "green"

    property alias barValue1: bar1.value
    property alias barValue2: bar2.value
    property alias barValue3: bar3.value


    Row {

        spacing: 10
        ProgressBar {
            id : bar1
            value: 1

            style: ProgressBarStyle {
                background: Rectangle {
                    radius: 2
                    color: "white"
                    border.color: "steelblue"
                    border.width: 1
                    implicitWidth: 100
                    implicitHeight: 16

                }

            }
        }
        ProgressBar {
            id : bar2
            value: 1

            style: ProgressBarStyle {
                background: Rectangle {
                    radius: 2
                    color: "white"
                    border.color: "steelblue"
                    border.width: 1
                    implicitWidth: 100
                    implicitHeight: 16

                }

            }
        }
        ProgressBar {
            id : bar3
            value: 1

            style: ProgressBarStyle {
                background: Rectangle {
                    radius: 2
                    color: "white"
                    border.color: "steelblue"
                    border.width: 1
                    implicitWidth: 100
                    implicitHeight: 16

                }

            }
        }
    }
}
