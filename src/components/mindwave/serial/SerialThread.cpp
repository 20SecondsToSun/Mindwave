#include "SerialThread.h"
#include <QDebug>
#include <QSerialPortInfo>

SerialThread::SerialThread(QObject *parent): QObject(parent)
{
    serialPort = new QSerialPort();
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(onReadError(QSerialPort::SerialPortError)));

    reconnectTimer = new QTimer(this);
    connect(reconnectTimer, SIGNAL(timeout()), this, SLOT(onReconnectHandle()));

    noDataTimer = new QTimer(this);
    connect(noDataTimer, SIGNAL(timeout()), this, SLOT(onNoDataTimerHandle()));
}

SerialThread::~SerialThread()
{
    serialPort->close();

    if(serialPort)
    {
        disconnect(serialPort, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        disconnect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(onReadError(QSerialPort::SerialPortError)));
        delete serialPort;
    }

    if(reconnectTimer)
    {
        disconnect(reconnectTimer, SIGNAL(timeout()), this, SLOT(onReconnectHandle()));
        delete reconnectTimer;
    }

    if(noDataTimer)
    {
        disconnect(noDataTimer, SIGNAL(timeout()), this, SLOT(onNoDataTimerHandle()));
        delete noDataTimer;
    }
}

void SerialThread::initThread(QThread* thread)
{
    serialPort->moveToThread(thread);
    moveToThread(thread);
}

void SerialThread::setPortName(const QString& value)
{
    portName = value;
    serialPort->setPortName(portName);
}

void SerialThread::setNoDataTimeoutMills(int value)
{
    noDataTimeoutMills = value;
}

void SerialThread::setReconnectionMills(int value)
{
    reconnectionMills = value;
}

void SerialThread::startReading()
{
    auto serialPortBaudRate = QSerialPort::Baud9600;
    serialPort->setBaudRate(serialPortBaudRate);
    //serialPort->setFlowControl(QSerialPort::HardwareControl);

    qDebug()<<"try open"<<serialPort->portName();

    if (!serialPort->open(QIODevice::ReadWrite))
    {
        emit disconnected();
        tryReconnect();
    }
    else
    {
        emit connected();
    }

    noDataTimer->start(noDataTimeoutMills);
}

void SerialThread::onReadyRead()
{
    noDataTimer->stop();
    noDataTimer->start(noDataTimeoutMills);
    QByteArray bytes = serialPort->readAll();
    emit dataRecieve(bytes);
}

void SerialThread::onReadError(QSerialPort::SerialPortError serialPortError)
{
    //qDebug()<<"serialPortError "<< serialPortError;
}

void SerialThread::onNoDataTimerHandle()
{
    emit noDataTimeout();
    noDataTimer->stop();
    tryReconnect();
}

void SerialThread::tryReconnect()
{
    if(serialPort->isOpen())
    {
        serialPort->close();
    }

    reconnectTimer->stop();
    reconnectTimer->start(reconnectionMills);
}

void SerialThread::onReconnectHandle()
{
    reconnectTimer->stop();
    startReading();
}
