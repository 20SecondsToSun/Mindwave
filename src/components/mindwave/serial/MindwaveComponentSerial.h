#ifndef MINDWAVECOMPONENTSERIAL_H
#define MINDWAVECOMPONENTSERIAL_H

#include  "src/components/mindwave/BaseMindwaveComponent.h"
#include  "src/components/mindwave/MindwaveConfig.h"

class MindwaveComponentSerial  : public BaseMindwaveComponent
{
    Q_OBJECT
public:
    explicit MindwaveComponentSerial(QObject *parent = nullptr);    
    virtual ~MindwaveComponentSerial();

    virtual void setConfig(const MindwaveConfig& value) override;
    virtual void start() override;
    virtual void stop() override;
};

#endif // MINDWAVECOMPONENTSERIAL_H
