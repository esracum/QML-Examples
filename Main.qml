import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import Elipse

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Integration Example")

    footer: Button {
        text: qsTr("Call Q_INVOKABLE method to reset ellipse's properties")
        onClicked:{
            slider.value = 25
            elipse.setProperties(slider.value,"blue")
        }
    }

    header: Column {
        width: parent.width

        Button{
            width: parent.width
            text: qsTr("Select ellipses's color")


            onClicked: colorDialog.visible = true



        }

        Label {
            width: parent.width
            text: qsTr("Resize ellipses's border")

        }


        Slider{
            id: slider

            width: parent.width
            value: 25
            from:0
            to: Math.min(elipse.width,elipse.height)/2
        }



    }
    Elipse{
        id: elipse

        anchors.centerIn:parent
        width: 200
        height: 200
        color: "blue"
        border: slider.value

        onColorChanged:{elipseInfo()}


    }

    ColorDialog{
        id: colorDialog

        selectedColor: elipse.color

        onAccepted: {elipse.color = selectedColor}
    }

}
