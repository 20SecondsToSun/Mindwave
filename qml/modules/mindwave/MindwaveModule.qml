import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Item
{
    ColumnLayout
    {
        x: 50;
        y: 50;
        spacing: 10;

        Text
        {
            text: "Mindwave module";
            font.family: "Helvetica";
            font.pixelSize: 17;
            color: "#008800";
        }

        Item
        {
            height: 10;
        }

        ColumnLayout
        {
            spacing: 10;

            ProgressBlock
            {
                id: signalLevel;
                title: "Signal level";

            }

            ProgressBlock
            {
                id: attentionLevel;
                title: "Attention level";
            }

            ProgressBlock
            {
                id: meditationLevel;
                title: "Meditation level";
            }
        }
    }

    Connections
    {
        target:mindwave;

        onPoorSignalLevelChanged:
        {
            signalLevel.setPercent(value / 100.);
        }

        onDeviceStateChanged:
        {

        }

        onAttentionChanged:
        {
            attentionLevel.setPercent(value / 100.);
        }

        onMeditationChanged:
        {
            meditationLevel.setPercent(value / 100.);
        }
    }
}
