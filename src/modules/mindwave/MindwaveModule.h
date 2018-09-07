#ifndef MINDWAVEMODULE_H
#define MINDWAVEMODULE_H

#include <QObject>
#include <QQmlContext>
#include <QSharedPointer>

#include "src/modules/BaseModule.h"

class BaseMindwaveComponent;

class MindwaveModule : public BaseModule
{
    Q_OBJECT

public:
    explicit MindwaveModule(QObject *parent = nullptr);
    ~MindwaveModule();

    enum class MindwaveProvider
    {
        Serial,
        TCP,
        Simulation
    };
    Q_ENUMS(MindwaveProvider)


    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;

    template <class MindwaveComponentT>
    void inject();

private:
    QSharedPointer<BaseMindwaveComponent> mindwave;
    MindwaveProvider provider = MindwaveProvider::Simulation;

signals:
    void meditationChanged(int value);
    void attentionChanged(int value);
    void poorSignalLevelChanged(int value);
    void deviceStateChanged(int value);

private slots:
    void onDeviceStateChanged(int);
    void onMeditationChanged();
    void onAttentionChanged();
    void onPoorSignalLevelChanged();

};

#endif // MINDWAVEMODULE_H
