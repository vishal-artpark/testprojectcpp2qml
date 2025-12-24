import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Model View Controller")

    property var dateTimeProvider: controller.dateTimeProvider
    property var dataProvider: controller.dataProvider


    Rectangle
    {
        anchors.fill: parent
        anchors.margins: 20

        color: "white"

        radius: 9

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 20

            spacing: 10

            Rectangle{
                    Layout.fillWidth: true
                    Layout.minimumHeight: parent.width*0.1
                    Layout.alignment: Qt.AlignTop|Qt.AlignHCenter
                    color: "#55345689"
                    radius: 9
                    Text
                    {
                        id:header

                        font.pixelSize: 32
                        text:dataProvider.header
                        anchors.centerIn: parent
                    }
            }


            Rectangle{
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "#55000000"

                Flickable {
                    anchors.fill: parent
                    anchors.margins: 20
                    contentHeight: scrollText.height
                    clip: true

                    Text {
                        id: scrollText
                        width: parent.width
                        text: dataProvider.description
                        font.pixelSize: 14
                        wrapMode: Text.WordWrap
                    }
                }

                radius: 9
            }

            RowLayout
            {
                Layout.minimumHeight: parent.height*0.1
                Layout.fillWidth: true
                spacing: 10
                Rectangle
                {
                    Layout.preferredHeight: 40
                    width: 120
                    color: "black"
                    radius: 9
                    Text {
                        id: text
                        text: qsTr("Refresh")
                        anchors.centerIn: parent
                        color: "white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            dataProvider.callMe()
                            dateTimeProvider.callMe()
                            controller.refresh()
                        }
                    }
                }

                Text
                {
                    id:status
                    font.pixelSize: 18
                    text:controller.status
                    color: "red"
                    verticalAlignment: Text.AlignVCenter
                    Layout.fillWidth: true
                }
                Column{
                    Layout.alignment: Qt.AlignRight
                    Text{
                        text:dateTimeProvider.date
                        font.bold: true
                    }
                    Text{
                        text:dateTimeProvider.time
                        font.bold: true
                    }
                }
            }

        }

    }
}
