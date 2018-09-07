#include "MindwaveComponentTCP.h"
#include "MindwaveReaderTCP.h"
#include "MindwaveParserTCP.h"
#include <QDebug>

MindwaveComponentTCP::MindwaveComponentTCP(QObject *parent) : BaseMindwaveComponent(parent)
{
    mindwaveReader.reset(new MindwaveReaderTCP(parent));
    connect(mindwaveReader.data(), SIGNAL(connected()), this, SLOT(onConnected()));
    connect(mindwaveReader.data(), SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    mindwaveParser.reset(new MindwaveParserTCP());
    connect(mindwaveParser.data(), SIGNAL(signalLevelParsed(int)), this, SLOT(onSignalLevelParsed(int)));
    connect(mindwaveParser.data(), SIGNAL(meditationParsed(int)), this, SLOT(onMeditationParsed(int)));
    connect(mindwaveParser.data(), SIGNAL(attentionParsed(int)), this, SLOT(onAttentionParsed(int)));
    connect(mindwaveReader.data(), SIGNAL(dataRecieve(const QByteArray&)), mindwaveParser.data(), SLOT(onDataRecieve(const QByteArray&)));
}

MindwaveComponentTCP::~MindwaveComponentTCP()
{
    disconnect(mindwaveReader.data(), SIGNAL(connected()), this, SLOT(onConnected()));
    disconnect(mindwaveReader.data(), SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    disconnect(mindwaveParser.data(), SIGNAL(signalLevelParsed(int)), this, SLOT(onSignalLevelParsed(int)));
    disconnect(mindwaveParser.data(), SIGNAL(meditationParsed(int)), this, SLOT(onMeditationParsed(int)));
    disconnect(mindwaveParser.data(), SIGNAL(attentionParsed(int)), this, SLOT(onAttentionParsed(int)));
    disconnect(mindwaveReader.data(), SIGNAL(dataRecieve(const QByteArray&)), mindwaveParser.data(), SLOT(onDataRecieve(const QByteArray&)));
}

void MindwaveComponentTCP::setConfig(const MindwaveConfig& value)
{
    BaseMindwaveComponent::setConfig(value);

    mindwaveReader->setConfig(config);
    mindwaveParser->setConfig(config);
}

void MindwaveComponentTCP::start()
{
    qDebug()<<"------------------- mindwave tcp component start -------------------";
    mindwaveReader->start();
}

void MindwaveComponentTCP::stop()
{
    qDebug()<<"------------------- mindwave tcp component stop -------------------";
    mindwaveReader->stop();
}
