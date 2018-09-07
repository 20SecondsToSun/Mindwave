#ifndef MINDWAVEREADERTCP_H
#define MINDWAVEREADERTCP_H

#include <QSharedPointer>
#include "src/components/mindwave/BaseMindwaveReader.h"

class TCPSocketClient;

class MindwaveReaderTCP : public BaseMindwaveReader
{
    Q_OBJECT
public:
    explicit MindwaveReaderTCP(QObject *parent = nullptr);
    virtual ~MindwaveReaderTCP();

    virtual void start() override;
    virtual void stop() override;
    virtual void init() override;
    virtual void setConfig(const MindwaveConfig& value) override;

private:
    QSharedPointer<TCPSocketClient> client;
    QString initialCommand;

protected slots:
    virtual void onConnected() override;

};

#endif // MINDWAVEREADERTCP_H
