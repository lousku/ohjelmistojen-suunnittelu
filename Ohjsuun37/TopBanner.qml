import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    height: 100
    color: "green"

    property alias palkkinakyvissa: palkkirivi.visible
    property alias barValue1: bar1.value
    property alias barValue2: bar2.value
    property alias barValue3: bar3.value

    property alias barBorderWidth1: bar1.reunanleveys
    property alias barBorderWidth2: bar2.reunanleveys
    property alias barBorderWidth3: bar3.reunanleveys

    property int barPosition1: 0
    property int barPosition2: 1
    property int barPosition3: 2

    GridLayout {
        id: palkkirivi
        visible: false
        //spacing: 10
        Elamamittari{
            id: bar1
            vari: "darkorange"
            Layout.column: barPosition1
        }

        Elamamittari{
            id: bar2
            vari: "salmon"
            Layout.column: barPosition2
        }
        Elamamittari{
            id: bar3
            vari: "gold"
            Layout.column: barPosition3
        }
    }
}
