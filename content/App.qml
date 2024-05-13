// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
import QtQuick 6.2
import ExpertSystem

Window {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    visible: true
    title: "ExpertSystem"

    // Screen01 {
    //     id: mainScreen
    // }
    ScreenExpert {
        anchors.fill: parent
        anchors.margins: 5
    }
}
