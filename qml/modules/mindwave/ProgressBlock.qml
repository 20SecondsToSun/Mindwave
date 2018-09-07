import QtQuick 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


RowLayout
{
    property alias title: textTitle.text;

    spacing: 10;

    Text
    {
        id: textTitle;
        text: "signalLevel";
        font.family: "Helvetica";
        font.pixelSize: 15;
        color: "#999999";
    }

    ProgressBar
    {
        id:progressBar;
        opacity:0.2
        value: 0.;

        style: ProgressBarStyle
        {
            background: Rectangle
            {
                radius: 2;
                color: "lightgray";
                border.color: "gray";
                border.width: 1;
                implicitWidth: 300;
                implicitHeight: 24;
            }
            progress: Rectangle
            {
                id: bg;
                color:  "#009900";
                border.color: "steelblue";
            }
        }
    }

    PropertyAnimation
    {
        id: signalAnim;
        target: progressBar;
        property: "value";
        to: 100;
        duration: 500;
    }

    function setPercent(percent)
    {
        progressBar.value = percent;
    }
}
