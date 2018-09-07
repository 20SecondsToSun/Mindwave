#include "MindwaveReaderSerial.h"
#include "../MindwaveConfig.h"
#include <QDebug>

MindwaveReaderSerial::MindwaveReaderSerial(QObject *parent) : BaseMindwaveReader(parent)
{  
    thread = new QThread(this);
    serialThread = new SerialThread();

    connect(thread, SIGNAL(started()), serialThread, SLOT(startReading()));
    connect(thread, SIGNAL(finished()), serialThread, SLOT(deleteLater()));

    connect(serialThread, SIGNAL(dataRecieve(const QByteArray&)), this, SLOT(onSerialDataRecieve(const QByteArray&)));
    connect(serialThread, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(serialThread, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(serialThread, SIGNAL(serialError()), this, SLOT(onSerialError()));
    connect(serialThread, SIGNAL(noDataTimeout()), this, SLOT(onNoDataFromSerialTimeout()));

    serialThread->initThread(thread);
}

MindwaveReaderSerial::~MindwaveReaderSerial()
{
    qDebug()<<"Destroy MindwaveReaderSerial";

    disconnect(thread, SIGNAL(started()), serialThread, SLOT(startReading()));
    disconnect(thread, SIGNAL(finished()), serialThread, SLOT(deleteLater()));

    disconnect(serialThread, SIGNAL(dataRecieve(const QByteArray&)), this, SLOT(onSerialDataRecieve(const QByteArray&)));
    disconnect(serialThread, SIGNAL(connected()), this, SLOT(onConnected()));
    disconnect(serialThread, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    disconnect(serialThread, SIGNAL(serialError()), this, SLOT(onSerialError()));
    disconnect(serialThread, SIGNAL(noDataTimeout()), this, SLOT(onNoDataFromSerialTimeout()));

    thread->quit();
    thread->wait();

    serialThread->deleteLater();

    qDebug()<<"Destroy serialWorkerThread";
}

void MindwaveReaderSerial::setConfig(const MindwaveConfig& value)
{
    serialThread->setPortName(value.serialPortName);
    serialThread->setNoDataTimeoutMills(value.noDataTimeoutMills);
    serialThread->setReconnectionMills(value.reconnectionMills);
}

void MindwaveReaderSerial::init()
{

}

void MindwaveReaderSerial::start()
{
    if(!thread->isRunning())
    {
        thread->start();
    }
}

void MindwaveReaderSerial::stop()
{

}

void MindwaveReaderSerial::onSerialError()
{
    onDisconnected();
}

void MindwaveReaderSerial::onNoDataFromSerialTimeout()
{
    onDisconnected();
}

void MindwaveReaderSerial::onSerialDataRecieve(const QByteArray& bytes)
{  
    onDataRecieve(bytes);
}
