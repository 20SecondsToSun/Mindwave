#ifndef MINDWAVECOMPONENTTCP_H
#define MINDWAVECOMPONENTTCP_H

#include  "src/components/mindwave/BaseMindwaveComponent.h"
#include  "src/components/mindwave/MindwaveConfig.h"

class MindwaveComponentTCP : public BaseMindwaveComponent
{
    Q_OBJECT
public:
    explicit MindwaveComponentTCP(QObject *parent = nullptr);
    virtual ~MindwaveComponentTCP();

    virtual void setConfig(const MindwaveConfig& value) override;

    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;
};

#endif // MINDWAVECOMPONENTTCP_H
