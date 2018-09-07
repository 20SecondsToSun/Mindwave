#ifndef MINDWAVEPARSERSERIAL_H
#define MINDWAVEPARSERSERIAL_H

#include <QVariantMap>
#include "src/components/mindwave/BaseMindwaveParser.h"
#include "MindwaveSerialData.h"

struct MindwaveConfig;

class MindwaveParserSerial : public BaseMindwaveParser
{
    Q_OBJECT
public:
    explicit MindwaveParserSerial(QObject *parent = nullptr);
    virtual ~MindwaveParserSerial();

    virtual void parse(const QByteArray& data) override;
    virtual void setConfig(const MindwaveConfig& value) override;

private:
    ThinkGearStreamParser parser;
    int initParser(uchar parserType, void *customData);
    int parseByte(uchar byte);
    int parsePacketPayload();
    void parseSerialData(uchar extendedCodeLevel,
                         uchar code,
                         uchar valueLength,
                         const uchar *value,
                         void* /* Custom Data */);

    QVariantMap eegPowerDataMap;
    QVariantMap asicEegDataMap;

    uint16_t batteryData    = 0;
    uint16_t signalData     = 0;

    uint16_t heartRateData  = 0;
    uint16_t attentionData  = 0;
    uint16_t meditationData = 0;
    uint16_t raw8BitData    = 0;
    uint16_t raw16BitData   = 0;
    uint16_t rrIntervalData = 0;
};

#endif // MINDWAVEPARSERSERIAL_H
