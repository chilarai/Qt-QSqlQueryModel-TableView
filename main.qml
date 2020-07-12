import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QSqlQueryModel - TableView")

    // Uncomment this, if you want to call query from qml

    //    Component.onCompleted: {
    //        MysqlModel.callSql("SELECT * FROM users")
    //    }

    TableView {
        id: tableView

        columnWidthProvider: function (column) { return 100; }
        rowHeightProvider: function (column) { return 60; }
        anchors.fill: parent

        ScrollBar.horizontal: ScrollBar{}
        ScrollBar.vertical: ScrollBar{}
        clip: true

        model: MysqlModel

        // Table Body

        delegate: Rectangle {
            Text {
                text: display // This is set in C++
                anchors.fill: parent
                anchors.margins: 10
                color: 'black'
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
            }
        }


        // Table Header

        Row {
            id: columnsHeader
            y: tableView.contentY
            z: 2
            Repeater {
                model: tableView.columns > 0 ? tableView.columns : 1
                Label {
                    width: tableView.columnWidthProvider(modelData)
                    height: 35
                    text: MysqlModel.headerData(modelData, Qt.Horizontal)
                    font.pixelSize: 15
                    padding: 10
                    verticalAlignment: Text.AlignVCenter

                    background: Rectangle { color: "#ccc" }
                }
            }
        }


        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}
