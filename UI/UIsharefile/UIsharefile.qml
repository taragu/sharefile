import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        id: login
        width: 58
        height: 26
        text: qsTr("Login")
        anchors.verticalCenterOffset: -123
        anchors.horizontalCenterOffset: -128
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    TextInput {
        id: usernameinput
        x: 235
        y: 45
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Text {
        id: text1
        x: 163
        y: 44
        width: 66
        height: 20
        text: qsTr("User:")
        wrapMode: Text.NoWrap
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 163
        y: 70
        width: 66
        height: 21
        text: qsTr("Password:")
        font.pixelSize: 12
    }

    TextInput {
        id: passwordinput
        x: 235
        y: 71
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Button {
        id: register
        x: 237
        y: 104
        width: 78
        height: 26
        text: qsTr("Register")
    }
}
