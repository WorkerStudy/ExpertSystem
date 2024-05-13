import QtQuick 6.2
import QtQuick.Controls.Material
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects

Column {
    id: root
    spacing: 5
    Pane {
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width / 2
        Column {
            width: parent.width
            Text {
                text: "Предпочтения"
                font.pointSize: 12
            }

            Flow {
                width: parent.width
                Price {
                    id: tarrifCost
                    name: "Тарифный план"
                    onFirstValueChanged: backend.minTariffPlan = firstValue
                    onSecondValueChanged: backend.maxTariffPlan = secondValue
                }
                Price {
                    id: roumingCost
                    name: "Цена роуминга"
                    onFirstValueChanged: backend.minCost = firstValue
                    onSecondValueChanged: backend.maxCost = secondValue
                }
                Row {
                    spacing: 5
                    Repeater {
                        model: ListModel {
                            ListElement {
                                nameField: "SMS"
                                stateBackend: "needSMS"
                            }
                            ListElement {
                                nameField: "MMS"
                                stateBackend: "needMMS"
                            }
                            ListElement {
                                nameField: "WAP"
                                stateBackend: "needWAP"
                            }
                        }
                        delegate: CheckBox {
                            text: nameField
                            checked: stateBackend
                            onCheckedChanged: {
                                backend[stateBackend] = checked
                            }
                        }
                    }
                }
            }
        }
    }
    Text {
        text: "Рекомендуемый тариф"
        font.pointSize: 12
    }

    BusyIndicator {
        id: loadedAnim
        running: backend.loaded
        anchors {
            left: parent.left
            right: parent.right
        }

        ListView {
            id: listView
            visible: !loadedAnim.running
            anchors {
                left: parent.left
                right: parent.right
                margins: 10
            }
            clip: true
            height: 1000
            model: backend.listTarifs
            spacing: 10
            property double valueStepHSVA: 0.333 / (count - 1)
            delegate: Rectangle {
                id: delegItem
                required property var modelData
                required property int index
                radius: 10
                clip: true
                height: 100
                width: listView.width
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: Rectangle {
                        width: delegItem.width
                        height: delegItem.height
                        radius: delegItem.radius
                    }
                }
                RowLayout {
                    height: parent.height
                    width: parent.width
                    spacing: 5
                    Rectangle {
                        height: parent.height
                        width: 15
                        // Динамическое изменение цвета в зависимости от индекса
                        color: Qt.hsva(
                                   listView.valueStepHSVA * (listView.count - delegItem.index - 1),
                                   1, 1, 1)
                    }
                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignTop | Qt.AlignLeft

                        H1Text {
                            text: modelData.name
                        }
                        Text {
                            text: "уровень приема: " + modelData.zone
                            font.pointSize: 10
                            color: "grey"
                        }

                        Text {
                            visible: {
                                if (modelData.mms || modelData.sms
                                        || modelData.wap)
                                    return true
                                return false
                            }
                            text: "Включает в себя:"
                            font.pointSize: 12
                        }
                        Row {
                            spacing: 5
                            Repeater {
                                model: [["SMS", modelData.mms], ["MMS", modelData.sms], ["WAP", modelData.wap]]
                                delegate: Text {
                                    visible: modelData[1]
                                    font.pointSize: 10
                                    text: modelData[0]
                                }
                            }
                        }
                    }
                    Column {
                        Layout.alignment: Qt.AlignRight
                        Layout.rightMargin: 5
                        H1Text {
                            font.pointSize: 18
                            text: modelData.tariffPlan + "р./месяц"
                        }
                        Text {
                            text: "Роуминг: " + modelData.costRoaming + "р./месяц"
                            font.pointSize: 10
                            color: "grey"
                        }
                    }
                }
                ItemDelegate {
                    anchors.fill: parent
                }
            }

            H1Text {
                visible: listView.count === 0
                text: "Нет подходящих тарифов!"
                color: "grey"
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
