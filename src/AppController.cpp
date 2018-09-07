#include "AppController.h"
#include "modules/mindwave/MindwaveModule.h"
#include "modules/BaseModule.h"

AppController::AppController(QObject *parent) : QObject(parent)
{

}

void AppController::setQmlContext(QQmlContext* qmlContext)
{
    mindwaveModule->setQmlContext(qmlContext);
}

void AppController::init()
{
    mindwaveModule.reset(new MindwaveModule());
    modules.push_back(mindwaveModule);

    for(auto module : modules)
    {
        module->init();
    }
}

void AppController::start()
{
    for(auto module : modules)
    {
        module->start();
    }
}

void AppController::stop()
{
    for(auto module : modules)
    {
        module->stop();
    }
}
