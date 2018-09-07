#include "MindwaveReaderTCP.h"
#include "../MindwaveConfig.h"
#include "src/network/socketClient/TCPSocketClient.h"

MindwaveReaderTCP::MindwaveReaderTCP(QObject *parent) : BaseMindwaveReader(parent)
{
    client.reset(new TCPSocketClient);
    connect(client.data(), SIGNAL(socketDataRecieve(const QByteArray&)), this, SLOT(onDataRecieve(const QByteArray&)));
    connect(client.data(), SIGNAL(socketConnected()), this, SLOT(onConnected()));
    connect(client.data(), SIGNAL(socketDisonnected()), this, SLOT(onDisconnected()));
}

MindwaveReaderTCP::~MindwaveReaderTCP()
{
    disconnect(client.data(), SIGNAL(socketDataRecieve(const QByteArray&)), this, SLOT(onDataRecieve(const QByteArray&)));
    disconnect(client.data(), SIGNAL(socketConnected()), this, SLOT(onConnected()));
    disconnect(client.data(), SIGNAL(socketDisonnected()), this, SLOT(onDisconnected()));
}

void MindwaveReaderTCP::setConfig(const MindwaveConfig& value)
{
    initialCommand = value.initialCommand;
    client->setIp(value.ip);
    client->setPort(value.port);
    client->setAutoConnect(value.autoConnect);
    client->setDelimeter(value.delimeter);
}

void MindwaveReaderTCP::init()
{

}

void MindwaveReaderTCP::start()
{
     client->start();
}

void MindwaveReaderTCP::stop()
{

}

void MindwaveReaderTCP::onConnected()
{
    BaseMindwaveReader::onConnected();
    client->sendData(initialCommand);
}
