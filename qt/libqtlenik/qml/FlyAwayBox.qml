import QtQuick 1.0

Rectangle {
    property real speed: 5
    property real displacement: parent.height * 0.5
    property real y0: 0

    signal appeared
    signal disappeared

    id: box
    y: y0

    states: [
        State {
            name: "coming"
            PropertyChanges {
                target: box
                y: y0 + displacement
            }
            PropertyChanges {
                target: box
                opacity: 0
            }
        },
        State {
            name: "away"
            PropertyChanges {
                target: box
                y: y0 - displacement
            }
            PropertyChanges {
                target: box
                opacity: 0
            }
        }
    ]

    transitions: [
        Transition {
            from: "coming"
            SequentialAnimation {
                NumberAnimation {
                    target: box
                    properties: "y, opacity"
                    duration: 5000 / box.speed
                    easing.type: Easing.OutCubic
                }
                ScriptAction { script: box.appeared() }
            }
        },
        Transition {
            to: "away"
            SequentialAnimation {
                NumberAnimation {
                    target: box
                    properties: "y, opacity"
                    duration: 5000 / box.speed
                    easing.type: Easing.OutCubic
                }
                ScriptAction { script: box.disappeared() }
            }
        }
    ]

}
