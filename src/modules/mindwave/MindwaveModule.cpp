#include "MindwaveModule.h"
#include "src/tools/MathTools.h"

#include "src/components/mindwave/BaseMindwaveComponent.h"
#include "src/components/mindwave/BaseMindwaveParser.h"
#include "src/components/mindwave/BaseMindwaveReader.h"
#include "src/components/mindwave/serial/MindwaveComponentSerial.h"
#include "src/components/mindwave/tcp/MindwaveComponentTCP.h"
#include "src/components/mindwave/simulation/MindwaveComponentSimulation.h"
#include "src/components/mindwave/mindwaveconfig.h"

MindwaveModule::MindwaveModule(QObject *parent) : BaseModule(parent)
{
    name = "mindwave";
}

MindwaveModule::~MindwaveModule()
{

}

template <class MindwaveComponentT>
void MindwaveModule::inject()
{
    mindwave.reset(new MindwaveComponentT());
}

void MindwaveModule::init()
{
    MindwaveConfig config;
    if(provider == MindwaveProvider::TCP)
    {
        config.serialPortName = "COM5";
        config.noDataTimeoutMills = 6000;
        config.reconnectionMills = 1000;

        inject<MindwaveComponentSerial>();
    }
    else if(provider == MindwaveProvider::TCP)
    {
        MindwaveConfig config;
        config.ip = "127.0.0.1";
        config.port = 13854;

        inject<MindwaveComponentTCP>();
    }
    else if(provider == MindwaveProvider::Simulation)
    {
        inject<MindwaveComponentSimulation>();
    }

    mindwave->setConfig(config);

    connect(mindwave.data(), SIGNAL(meditationChanged()), this, SLOT(onMeditationChanged()));
    connect(mindwave.data(), SIGNAL(attentionChanged()), this, SLOT(onAttentionChanged()));
    connect(mindwave.data(), SIGNAL(poorSignalLevelChanged()), this, SLOT(onPoorSignalLevelChanged()));
}

void MindwaveModule::start()
{
    mindwave->start();
}

void MindwaveModule::stop()
{

}

void MindwaveModule::onMeditationChanged()
{
    emit meditationChanged(mindwave->meditation());
}

void MindwaveModule::onAttentionChanged()
{
    emit attentionChanged(mindwave->attention());
}

void MindwaveModule::onPoorSignalLevelChanged()
{
    emit poorSignalLevelChanged(mindwave->poorSignalLevel());
}

void MindwaveModule::onDeviceStateChanged(int value)
{
    emit deviceStateChanged(value);
}
