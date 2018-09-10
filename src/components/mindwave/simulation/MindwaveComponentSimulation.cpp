#include "MindwaveComponentSimulation.h"
#include <QDebug>
#include "src/tools/MathTools.h"

MindwaveComponentSimulation::MindwaveComponentSimulation(QObject *parent) : BaseMindwaveComponent(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulateMindwaveRead()));
}

MindwaveComponentSimulation::~MindwaveComponentSimulation()
{
    if(timer)
    {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(simulateMindwaveRead()));
        delete timer;
    }
}

void MindwaveComponentSimulation::init()
{

}

void MindwaveComponentSimulation::start()
{
    qDebug()<<"------------------- mindwave simulation component start -------------------";
    timer->start(simulateMills);
}

void MindwaveComponentSimulation::stop()
{
    qDebug()<<"------------------- mindwave simulation component stop -------------------";
     timer->stop();
}

void MindwaveComponentSimulation::simulateMindwaveRead()
{
    int min = 60;
    int max = 100;
    int RandAtten = qrand() % ((max + 1) - min) + min;
    setAttention(RandAtten);

    int  RandMed = qrand() % ((100 + 1) - 0) + 0;
    setMeditation(RandMed);

    int signalValue = 0;
    setPoorSignalLevel(signalValue);
}



