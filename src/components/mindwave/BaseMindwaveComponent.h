#ifndef MINDWAVECOMPONENT_H
#define MINDWAVECOMPONENT_H

#include <QSharedPointer>
#include <QObject>
#include "src/components/BaseComponent.h"
#include "MindwaveConfig.h"

class BaseMindwaveReader;
class BaseMindwaveParser;

class BaseMindwaveComponent : public BaseComponent
{    
    Q_OBJECT

    Q_PROPERTY(DeviceState deviceState READ deviceState WRITE setDeviceState NOTIFY deviceStateChanged)
    Q_PROPERTY(int attention READ attention WRITE setAttention NOTIFY attentionChanged)
    Q_PROPERTY(int meditation READ meditation WRITE setMeditation NOTIFY meditationChanged)
    Q_PROPERTY(int poorSignalLevel READ poorSignalLevel WRITE setPoorSignalLevel NOTIFY poorSignalLevelChanged)

public:
    explicit BaseMindwaveComponent(QObject *parent = nullptr);
    virtual ~BaseMindwaveComponent();

    enum class DeviceState
    {
        None,
        Scanning,
        NotScanning,
        Reading
    };
    Q_ENUMS(DeviceState)

    QString poorSignalColor() const;
    bool isSignalLevelMax() const;

    virtual void start() = 0;
    virtual void stop() = 0;

    virtual void setConfig(const MindwaveConfig& config);

public:
    void setAttention(int value);
    int attention() const;

    void setMeditation(int value);
    int meditation() const;

    void setPoorSignalLevel(int value);
    int poorSignalLevel() const;

    void setConnected(bool value);
    bool connected() const;

    void setDeviceState(DeviceState value);
    DeviceState deviceState() const;

protected:
    QSharedPointer<BaseMindwaveReader> mindwaveReader;
    QSharedPointer<BaseMindwaveParser> mindwaveParser;

    DeviceState _deviceState = DeviceState::None;
    int _attention = 0;
    int _meditation = 0;
    int _poorSignalLevel = 0;
    bool _connected = false;
    QString _poorSignalColor = "black";

    //void parse(const QString& data);

    static QString getPoorSignalColor(int value);
    static int remapPoorSignalLevel(int signalValue);

    static const int MAX_SIGNAL_VALUE = 100;

    struct SignalData
    {
        int maxPoorSignalLevel = 0;
        int minPoorSignalLevel = 200;

        int maxSignalLevel = MAX_SIGNAL_VALUE;
        int minSignalLevel = 0;
    };

    MindwaveConfig config;

signals:
    void attentionChanged();
    void meditationChanged();
    void poorSignalLevelChanged();
    void mindwaveConfigChanged();
    void deviceStateChanged();

private slots:
    void onSignalLevelParsed(int value);
    void onMeditationParsed(int value);
    void onAttentionParsed(int value);

    void onConnected();
    void onDisconnected();
};

#endif // MINDWAVECOMPONENT_H
