#ifndef MINDWAVEPARSER_H
#define MINDWAVEPARSER_H

#include <QObject>

struct MindwaveConfig;

class BaseMindwaveParser : public QObject
{
    Q_OBJECT
public:
    explicit BaseMindwaveParser(QObject *parent = nullptr);
    virtual ~BaseMindwaveParser();

    virtual void parse(const QByteArray& data);
    virtual void setConfig(const MindwaveConfig& value) = 0;


public slots:
    virtual void onDataRecieve(const QByteArray& data);

signals:
    void signalLevelParsed(int value);
    void meditationParsed(int value);
    void attentionParsed(int value);

};

#endif // MINDWAVEPARSER_H
