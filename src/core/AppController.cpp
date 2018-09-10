#include "AppController.h"
#include "../modules/BaseModule.h"
#include "../components/slack/SlackComponent.h"
#include "../components/logging/LoggerComponent.h"
#include "../components/monitoring/MonitoringComponent.h"
#include "../screens/GameScreen.h"
#include "../modules/mindwave/MindwaveModule.h"
#include "../modules/BaseModule.h"

AppController::AppController(QObject *parent) : QObject(parent)
{

}

void AppController::setQmlContext(QQmlContext* qmlContext)
{
    mindwaveModule->setQmlContext(qmlContext);
}

void AppController::init()
{
    slackComponent.reset(new SlackComponent());
    components.push_back(slackComponent);

    loggerComponent.reset(new LoggerComponent());
    components.push_back(loggerComponent);

    monitoringComponent.reset(new MonitoringComponent());
    components.push_back(monitoringComponent);

    mindwaveModule.reset(new MindwaveModule());
    modules.push_back(mindwaveModule);

    gameScreen.reset(new GameScreen());
    screens.push_back(gameScreen);    


    for(auto comp : components)
    {
        comp->init();
    }

    for(auto module : modules)
    {
        module->init();
    }

    for(auto screen : screens)
    {
        screen->init();
    }
}

void AppController::start()
{
    for(auto comp : components)
    {
        comp->start();
    }

    for(auto module : modules)
    {
        module->start();
    }

    for(auto screen : screens)
    {
        screen->start();
    }
}

void AppController::stop()
{
    for(auto comp : components)
    {
        comp->stop();
    }

    for(auto module : modules)
    {
        module->stop();
    }

    for(auto screen : screens)
    {
        screen->stop();
    }
}

QUrl AppController::getStartQML() const
{
   return QUrl(QLatin1String("qrc:/qml/main.qml"));
}
