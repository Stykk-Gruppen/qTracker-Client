import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12

Rectangle {
    id: root
    width: 1366
    height: 768
    color: "#141414"

    Text {
        id: title
        x: 612
        y: 50
        color: "#ffffff"
        text: qsTr("qTracker")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50
        font.pixelSize: 36
        MouseArea {
            id: maTitle
            hoverEnabled: true
            anchors.fill: parent
            onClicked: changePage("home")
        }
    }

    Row {
        x: 341
        y: 138
        spacing: 32
        anchors.verticalCenterOffset: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: title.verticalCenter

        Label {
            id: profileLabel
            color: "#ffffff"
            text: qsTr("Profile")
        }

        Label {
            id: ratioLabel
            color: "#ffffff"
            text: (getRatio() > 1) ? "Ratio: " + "<font color=\"#00e940\">" + getRatio() + "</font>"
                                   : "Ratio: " + "<font color=\"#e90000\">" + getRatio() + "</font>"
        }

        Label {
            id: upLabel
            color: "#ffffff"
            text: "Up: " + getUpload()
        }

        Label {
            id: downLabel
            color: "#ffffff"
            text: "Down: " + getDownload()
        }

        Label {
            id: hnrsLabel
            color: "#ffffff"
            text: qsTr("HnRs: ")
        }

        Label {
            id: donateLabel
            color: "#ffffff"
            text: qsTr("Donate")
        }

        Label {
            id: rulesLabel
            color: "#ffffff"
            text: qsTr("Rules")
        }

        Label {
            id: torrentsLabel
            color: "#ffffff"
            text: qsTr("Torrents")
        }

        Label {
            id: inviteLabel
            color: maInviteLabel.containsMouse ? "#d0d046" : "#ffffff"
            text: qsTr("Invite")
            MouseArea {
                id: maInviteLabel
                hoverEnabled: true
                anchors.fill: parent
                onClicked: changePage("invite");
            }
        }

        Label {
            id: pointsLabel
            color: "#ffffff"
            text: "Points: "
        }
    }
}

