#include "MindwaveComponentSerial.h"
#include "MindwaveReaderSerial.h"
#include "MindwaveParserSerial.h"
#include <QDebug>

MindwaveComponentSerial::MindwaveComponentSerial(QObject *parent) : BaseMindwaveComponent(parent)
{
    mindwaveReader.reset(new MindwaveReaderSerial(parent));
    connect(mindwaveReader.data(), SIGNAL(connected()), this, SLOT(onConnected()));
    connect(mindwaveReader.data(), SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    mindwaveParser.reset(new MindwaveParserSerial());
    connect(mindwaveParser.data(), SIGNAL(signalLevelParsed(int)), this, SLOT(onSignalLevelParsed(int)));
    connect(mindwaveParser.data(), SIGNAL(meditationParsed(int)), this, SLOT(onMeditationParsed(int)));
    connect(mindwaveParser.data(), SIGNAL(attentionParsed(int)), this, SLOT(onAttentionParsed(int)));
    connect(mindwaveReader.data(), SIGNAL(dataRecieve(const QByteArray&)), mindwaveParser.data(), SLOT(onDataRecieve(const QByteArray&)));
}

MindwaveComponentSerial::~MindwaveComponentSerial()
{
    disconnect(mindwaveReader.data(), SIGNAL(connected()), this, SLOT(onConnected()));
    disconnect(mindwaveReader.data(), SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    disconnect(mindwaveReader.data(), SIGNAL(dataRecieve(const QByteArray&)), mindwaveParser.data(), SLOT(onDataRecieve(const QByteArray&)));

    disconnect(mindwaveParser.data(), SIGNAL(signalLevelParsed(int)), this, SLOT(onSignalLevelParsed(int)));
    disconnect(mindwaveParser.data(), SIGNAL(meditationParsed(int)), this, SLOT(onMeditationParsed(int)));
    disconnect(mindwaveParser.data(), SIGNAL(attentionParsed(int)), this, SLOT(onAttentionParsed(int)));
}

void MindwaveComponentSerial::setConfig(const MindwaveConfig& value)
{
    BaseMindwaveComponent::setConfig(value);

    mindwaveReader->setConfig(config);
    mindwaveParser->setConfig(config);
}

void MindwaveComponentSerial::init()
{

}

void MindwaveComponentSerial::start()
{
    qDebug()<<"------------------- mindwave serial component start -------------------";
    mindwaveReader->start();
}

void MindwaveComponentSerial::stop()
{
    qDebug()<<"------------------- mindwave serial component stop -------------------";
    mindwaveReader->stop();
}




