#include "BaseMindwaveReader.h"

BaseMindwaveReader::BaseMindwaveReader(QObject *parent) : QObject(parent)
{

}

BaseMindwaveReader::~BaseMindwaveReader()
{

}

void BaseMindwaveReader::onConnected()
{
    setConnected(true);
    emit connected();
}

void BaseMindwaveReader::onDisconnected()
{
    setConnected(false);
    emit disconnected();
}

void BaseMindwaveReader::onDataRecieve(const QByteArray& data)
{
    emit dataRecieve(data);
}

void BaseMindwaveReader::setConnected(bool value)
{
    _connected = value;
}
