#ifndef MINDWAVEREADER_H
#define MINDWAVEREADER_H

#include <QObject>

struct MindwaveConfig;

class BaseMindwaveReader : public QObject
{
    Q_OBJECT
public:
    explicit BaseMindwaveReader(QObject *parent = nullptr);
    virtual ~BaseMindwaveReader();

    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setConfig(const MindwaveConfig& value) = 0;

protected:
    void setConnected(bool value);
    bool _connected = false;

signals:
    void connected();
    void disconnected();
    void dataRecieve(const QByteArray&);

protected slots:
    void onDataRecieve(const QByteArray& data);
    virtual void onConnected();
    virtual void onDisconnected();

};

#endif // MINDWAVEREADER_H
