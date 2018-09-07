#ifndef MINDWAVEPARSERTCP_H
#define MINDWAVEPARSERTCP_H

#include "src/components/mindwave/BaseMindwaveParser.h"

struct MindwaveConfig;

class MindwaveParserTCP : public BaseMindwaveParser
{
    Q_OBJECT
public:
    explicit MindwaveParserTCP(QObject *parent = nullptr);
    ~MindwaveParserTCP();

    virtual void parse(const QByteArray& data) override;
    virtual void setConfig(const MindwaveConfig& value) override;

protected:
    void parseOneDataChunck(const QString& data);

private:
    QString delimeter;

};

#endif // MINDWAVEPARSERTCP_H
