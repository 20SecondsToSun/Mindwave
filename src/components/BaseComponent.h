#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <QObject>

class BaseComponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseComponent(QObject *parent = nullptr);
    virtual ~BaseComponent();

    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif // BASECOMPONENT_H
