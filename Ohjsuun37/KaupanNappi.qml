import QtQuick 2.0
import QtQuick.Controls 1.4

Button{
    property int tunniste: -1
    property string kyseessa: kenenNappi()
    property string ostos: ""
    text: ostos

    function kenenNappi()
    {
        var kyseessa = "Laura"
        if(tunniste != 0)
        {
            kyseessa = "Kyborgi"+tunniste
        }
        return kyseessa
    }
    anchors.horizontalCenter: parent.horizontalCenter
    height: 20
    width: 70
}
