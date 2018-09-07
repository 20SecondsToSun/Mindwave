#include "BaseMindwaveComponent.h"

#include <QDebug>
#include <QtMath>
#include <QTime>

#include "BaseMindwaveReader.h"
#include "BaseMindwaveParser.h"
#include "src/tools/MathTools.h"

BaseMindwaveComponent::BaseMindwaveComponent(QObject *parent) : BaseComponent(parent)
{
    setDeviceState(DeviceState::None);
}

BaseMindwaveComponent::~BaseMindwaveComponent()
{

}

void BaseMindwaveComponent::setConfig(const MindwaveConfig& value)
{
    config = value;
}

void BaseMindwaveComponent::onConnected()
{
    qDebug()<<"onConnected ";
}

void BaseMindwaveComponent::onDisconnected()
{
    qDebug()<<"onDisconnected ";

    setDeviceState(DeviceState::None);
    setPoorSignalLevel(200);
    setAttention(0);
    setMeditation(0);
}

void BaseMindwaveComponent::onSignalLevelParsed(int value)
{ 
    qDebug()<<"onSignalLevelParsed "<<value;
    setDeviceState(DeviceState::Reading);
    setPoorSignalLevel(value);
    _poorSignalColor = value;
}

void BaseMindwaveComponent::onMeditationParsed(int value)
{
    qDebug()<<"onMeditationParsed "<<value;
    setMeditation(value);
}

void BaseMindwaveComponent::onAttentionParsed(int value)
{
    qDebug()<<"onAttentionParsed "<<value;
    setAttention(value);
}

void BaseMindwaveComponent::setDeviceState(DeviceState value)
{
    _deviceState = value;
    emit deviceStateChanged();
}

BaseMindwaveComponent::DeviceState BaseMindwaveComponent::deviceState() const
{
    return _deviceState;
}

void BaseMindwaveComponent::setPoorSignalLevel(int value)
{
    _poorSignalLevel = remapPoorSignalLevel(value);
    _poorSignalColor = getPoorSignalColor(_poorSignalLevel);
    emit poorSignalLevelChanged();
}

int BaseMindwaveComponent::poorSignalLevel() const
{
    return _poorSignalLevel;
}

bool BaseMindwaveComponent::isSignalLevelMax() const
{
    return _poorSignalLevel == MAX_SIGNAL_VALUE;
}

void BaseMindwaveComponent::setAttention(int value)
{
    _attention = value;
    emit attentionChanged();
}

int BaseMindwaveComponent::attention() const
{
    return _attention;
}

void BaseMindwaveComponent::setMeditation(int value)
{
    _meditation = value;
    emit meditationChanged();
}

int BaseMindwaveComponent::meditation() const
{
    return _meditation;
}

QString BaseMindwaveComponent::poorSignalColor() const
{
    return _poorSignalColor;
}

int BaseMindwaveComponent::remapPoorSignalLevel(int signalValue)
{
    return MathTools::map<float>(signalValue, 0,  200, 100,  0);
}

QString BaseMindwaveComponent::getPoorSignalColor(int value)
{
    if(value >= 66 && value <= 100)
    {
        return "#009900";
    }
    else if(value >= 30 && value <= 66)
    {
        return "#999900";
    }
    else if(value >= 0 && value <= 30)
    {
        return  "#999999";
    }

    return "#999999";
}
