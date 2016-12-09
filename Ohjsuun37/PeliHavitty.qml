import QtQuick 2.0

Text {
    //property alias name: text
    id: tekstiKentta
    color: "white"
    font.pointSize: 16
    font.bold: true
    anchors.centerIn: parent.horizontalCenter
    anchors.topMargin: 150
    text: qsTr("
Ulkoavaruudesta saapuneet virheät, autoja syövät hirviöt
olivat sinulle liikaa. Edes automaatiotekniikkaa opiskeleva,
sivutyönään pysäköintivalvojan tehtäviä toimittava Laura ei
voinut heille mitään. Pisteitä kerrytit kuitenkin huimat ")
}
