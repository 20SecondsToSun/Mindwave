#ifndef MINDWAVECOMPONENTSIMULATION_H
#define MINDWAVECOMPONENTSIMULATION_H

#include <QObject>
#include <QTimer>
#include  "src/components/mindwave/BaseMindwaveComponent.h"

class MindwaveComponentSimulation : public BaseMindwaveComponent
{
    Q_OBJECT
public:
    explicit MindwaveComponentSimulation(QObject *parent = nullptr);
    virtual ~MindwaveComponentSimulation();

    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;


private:
    QTimer* timer;
    const int simulateMills = 1000;

private slots:
    void simulateMindwaveRead();

};

#endif // MINDWAVECOMPONENTSIMULATION_H
