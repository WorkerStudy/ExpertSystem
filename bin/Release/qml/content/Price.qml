import QtQuick 6.2
import QtQuick.Controls.Material
import QtQuick.Layouts

Column {
    property string name: ""
    property alias firstValue: firstField.text
    property alias secondValue: secondField.text
    Text {
        text: name
    }
    RangeSlider {
        id: slider
        stepSize: 100
        first.onMoved: {
            firstField.text = (first.value * 1000).toFixed()
        }
        second.onMoved: {
            secondField.text = (second.value * 1000).toFixed()
        }
    }
    RowLayout {
        anchors.horizontalCenter: slider.horizontalCenter
        width: slider.width - 20
        TextField {
            id: firstField
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight: 35
            Layout.preferredWidth: 70
            validator: IntValidator {}
            text: "0"
            placeholderText: "от"
            maximumLength: 4
            onEditingFinished: {
                slider.first.value = Number(text) / 1000
            }
        }
        TextField {
            id: secondField
            Layout.alignment: Qt.AlignRight
            Layout.preferredHeight: 35
            Layout.preferredWidth: 70
            text: "1000"
            placeholderText: "до"
            maximumLength: 4
            validator: IntValidator {}
            onEditingFinished: {
                slider.second.value = Number(text) / 1000
            }
        }
    }
}
