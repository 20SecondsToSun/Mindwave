#include "MindwaveParserTCP.h"
#include "../MindwaveConfig.h"
#include <QJsonDocument.h>
#include <QJsonObject>
#include <QDebug>

MindwaveParserTCP::MindwaveParserTCP(QObject *parent) : BaseMindwaveParser(parent)
{

}

MindwaveParserTCP::~MindwaveParserTCP()
{

}

void MindwaveParserTCP::setConfig(const MindwaveConfig& value)
{
    delimeter = value.delimeter;
}

void MindwaveParserTCP::parse(const QByteArray& value)
{
    QString data = value;
    qDebug()<<"income data"<<data;

    QStringList json = data.split(delimeter);

    if(json.length() <= 0)
    {
        return;
    }

    for(int i = 0; i < json.length(); i++)
    {
        if(json[i].indexOf("eSense") != -1)
        {
            parseOneDataChunck(json[i]);
            break;
        }
    }
}

void MindwaveParserTCP::parseOneDataChunck(const QString& data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObj   = jsonDoc.object();
    QJsonObject eSenseJson = jsonObj.value("eSense").toObject();

    int attention = eSenseJson.value("attention").toInt();
    emit attentionParsed(attention);

    int meditation = eSenseJson.value("meditation").toInt();
    emit meditationParsed(meditation);

    int poorSignalLevel = jsonObj.value("poorSignalLevel").toInt();
    emit signalLevelParsed(poorSignalLevel);
}
