#ifndef MINDWAVECONFIG_H
#define MINDWAVECONFIG_H

#include <QString>

struct MindwaveConfig
{
    QString serialPortName = "COM1";
    int noDataTimeoutMills = 6000;
    int reconnectionMills = 1000;

    QString ip = "127.0.0.1";
    int port = 13854;
    QString delimeter = "\r";
    bool autoConnect = true;
    QString initialCommand = "{\"enableRawOutput\": true, \"format\": \"Json\"}\\r";
};

#endif // MINDWAVECONFIG_H
