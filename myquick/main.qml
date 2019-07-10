import QtQuick 2.0

Rectangle{
    width: 300
    height: 250
    Text {
        id: id1
        text: qsTr("hello world")
        anchors.centerIn: parent
        MouseArea{
            anchors.fill:parent
            onClicked: {
                Qt.quit()
            }
        }
    }
}
