#ifndef MINDWAVEREADERSERIAL_H
#define MINDWAVEREADERSERIAL_H

#include <QSerialPort>
#include <QThread>
#include "SerialThread.h"
#include "src/components/mindwave/BaseMindwaveReader.h"

class MindwaveReaderSerial : public BaseMindwaveReader
{
    Q_OBJECT
public:
    explicit MindwaveReaderSerial(QObject *parent = nullptr);
    virtual ~MindwaveReaderSerial();

    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;
    virtual void setConfig(const MindwaveConfig& value) override;

private:
    QByteArray readData;
    SerialThread* serialThread = nullptr;
    QThread* thread = nullptr;

protected slots:
    void onSerialDataRecieve(const QByteArray& dataReady);
    void onSerialError();
    void onNoDataFromSerialTimeout();
};

#endif // MINDWAVEREADERSERIAL_H
