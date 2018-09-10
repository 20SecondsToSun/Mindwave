#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <QSharedPointer>

class BaseModule;
class BaseComponent;
class SlackComponent;
class LoggerComponent;
class MonitoringComponent;

class BaseScreen;
class GameScreen;

class MindwaveModule;

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);

    void init();
    void start();
    void stop();

    void setQmlContext(QQmlContext* qmlContext);
    QUrl getStartQML() const;

private:
    QList<QSharedPointer<BaseModule>> modules;
    QList<QSharedPointer<BaseComponent>> components;
    QList<QSharedPointer<BaseScreen>> screens;

    QSharedPointer<SlackComponent> slackComponent;
    QSharedPointer<LoggerComponent> loggerComponent;
    QSharedPointer<MonitoringComponent> monitoringComponent;

    QSharedPointer<GameScreen> gameScreen;

    QSharedPointer<MindwaveModule> mindwaveModule;

};

#endif // APPCONTROLLER_H
