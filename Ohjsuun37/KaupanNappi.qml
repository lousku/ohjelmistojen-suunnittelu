import QtQuick 2.0
import QtQuick.Controls 1.4

Button{
    property int tunniste: -1
    property string kyseessa: kenenNappi()
    property string ostos: ""
    text: ostos

    function kenenNappi()
    {
        if(tunniste != 0)
        {
            return "Kyborgi"+tunniste
        }
        return "Laura"
    }
    anchors.horizontalCenter: parent.horizontalCenter
    height: 20
    width: 70
}
