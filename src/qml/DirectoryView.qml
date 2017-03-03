import QtQml 2.2
import QtQuick 2.0
import QtQuick.Controls 1.2
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kamoso 3.0
import org.kde.kquickcontrols 2.0
import org.kde.kquickcontrolsaddons 2.0

ScrollView
{
    id: scrollView
    property alias header: view.header
    property alias mimeFilter: model.mimeFilter
    property alias nameFilter: model.nameFilter

    readonly property real delegateWidth: Kirigami.Units.gridUnit*4
    readonly property int columnCount: Math.floor(scrollView.viewport.width/delegateWidth)
    property var selection: []

    GridView
    {
        id: view
        cellWidth: scrollView.delegateWidth + (scrollView.viewport.width - columnCount*scrollView.delegateWidth)/columnCount
        cellHeight: cellWidth
        anchors.fill: parent

        model: DirModel {
            id: model
            url: config.saveUrl
        }
        onCountChanged: {
            scrollView.selection = []
        }

        delegate: MouseArea {
            id: delegateItem
            width: height
            height: scrollView.delegateWidth
            acceptedButtons: Qt.AllButtons

            onClicked: {
                var url = path.toString();
                var idx = scrollView.selection.indexOf(url);
                if (idx < 0) {
                    scrollView.selection.push(url)
                } else {
                    scrollView.selection.splice(idx, 1)
                }
                scrollView.selectionChanged(scrollView.selection);
            }

            Rectangle {
                anchors {
                    margins: -1
                    fill: parent
                }
                visible: scrollView.selection.indexOf(path.toString())>=0

                SystemPalette {
                    id: pal
                }
                opacity: 0.6
                color: "transparent"
                border.color: pal.highlight
                border.width: Kirigami.Units.smallSpacing * 2
                z: 1
            }

            ImageThumbnail {
                anchors {
                    fill: parent
                    margins: 1
                }
                path: model.path
                mime: model.mime
            }

            CheckBox {
                anchors {
                    right: parent.right
                    rightMargin: -width/3
                }
                checkedState: Qt.Checked
                enabled: false
                visible: scrollView.selection.indexOf(path.toString())>=0
            }
        }
    }
}
