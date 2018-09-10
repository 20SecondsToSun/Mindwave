QT += qml quick serialport

CONFIG += c++11

SOURCES += src/main.cpp \
    src/modules/BaseModule.cpp \
    src/modules/mindwave/MindwaveModule.cpp \
    src/tools/MathTools.cpp \
    src/components/mindwave/serial/MindwaveComponentSerial.cpp \
    src/components/mindwave/serial/MindwaveParserSerial.cpp \
    src/components/mindwave/serial/MindwaveReaderSerial.cpp \
    src/components/mindwave/serial/SerialThread.cpp \
    src/components/mindwave/tcp/MindwaveComponentTCP.cpp \
    src/components/mindwave/tcp/MindwaveParserTCP.cpp \
    src/components/mindwave/tcp/MindwaveReaderTCP.cpp \
    src/components/BaseComponent.cpp \
    src/components/mindwave/BaseMindwaveComponent.cpp \
    src/components/mindwave/BaseMindwaveParser.cpp \
    src/components/mindwave/BaseMindwaveReader.cpp \
    src/network/socketClient/TCPSocketClient.cpp \
    src/components/mindwave/simulation/MindwaveComponentSimulation.cpp \
    src/components/logging/LoggerComponent.cpp \
    src/components/mindwave/serial/MindwaveComponentSerial.cpp \
    src/components/mindwave/serial/MindwaveParserSerial.cpp \
    src/components/mindwave/serial/MindwaveReaderSerial.cpp \
    src/components/mindwave/serial/SerialThread.cpp \
    src/components/mindwave/simulation/MindwaveComponentSimulation.cpp \
    src/components/mindwave/tcp/MindwaveComponentTCP.cpp \
    src/components/mindwave/tcp/MindwaveParserTCP.cpp \
    src/components/mindwave/tcp/MindwaveReaderTCP.cpp \
    src/components/mindwave/BaseMindwaveComponent.cpp \
    src/components/mindwave/BaseMindwaveParser.cpp \
    src/components/mindwave/BaseMindwaveReader.cpp \
    src/components/monitoring/MemoryChecker.cpp \
    src/components/monitoring/MonitoringComponent.cpp \
    src/components/slack/SlackComponent.cpp \
    src/components/BaseComponent.cpp \
    src/core/AppController.cpp \
    src/modules/mindwave/MindwaveModule.cpp \
    src/modules/BaseModule.cpp \
    src/network/http/HTTPClient.cpp \
    src/network/socketClient/TCPSocketClient.cpp \
    src/screens/BaseScreen.cpp \
    src/screens/GameScreen.cpp \
    src/tools/AppSettings.cpp \
    src/tools/FileReader.cpp \
    src/tools/MathTools.cpp \
    src/tools/StringTools.cpp \
    src/main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/modules/BaseModule.h \
    src/modules/mindwave/MindwaveModule.h \
    src/tools/MathTools.h \
    src/components/mindwave/serial/MindwaveComponentSerial.h \
    src/components/mindwave/serial/MindwaveParserSerial.h \
    src/components/mindwave/serial/MindwaveReaderSerial.h \
    src/components/mindwave/serial/SerialThread.h \
    src/components/mindwave/tcp/MindwaveComponentTCP.h \
    src/components/mindwave/tcp/MindwaveParserTCP.h \
    src/components/mindwave/tcp/MindwaveReaderTCP.h \
    src/tools/MathTools.h \
    src/components/BaseComponent.h \
    src/components/mindwave/BaseMindwaveComponent.h \
    src/components/mindwave/BaseMindwaveParser.h \
    src/components/mindwave/BaseMindwaveReader.h \
    src/components/mindwave/serial/MindwaveSerialData.h \
    src/components/mindwave/MindwaveConfig.h \
    src/components/mindwave/serial/SerialThread.h \
    src/network/socketClient/TCPSocketClient.h \
    src/components/mindwave/simulation/MindwaveComponentSimulation.h \
    src/components/logging/LoggerComponent.h \
    src/components/mindwave/serial/MindwaveComponentSerial.h \
    src/components/mindwave/serial/MindwaveParserSerial.h \
    src/components/mindwave/serial/MindwaveReaderSerial.h \
    src/components/mindwave/serial/MindwaveSerialData.h \
    src/components/mindwave/serial/SerialThread.h \
    src/components/mindwave/simulation/MindwaveComponentSimulation.h \
    src/components/mindwave/tcp/MindwaveComponentTCP.h \
    src/components/mindwave/tcp/MindwaveParserTCP.h \
    src/components/mindwave/tcp/MindwaveReaderTCP.h \
    src/components/mindwave/BaseMindwaveComponent.h \
    src/components/mindwave/BaseMindwaveParser.h \
    src/components/mindwave/BaseMindwaveReader.h \
    src/components/mindwave/MindwaveConfig.h \
    src/components/monitoring/MemoryChecker.h \
    src/components/monitoring/MonitoringComponent.h \
    src/components/slack/SlackComponent.h \
    src/components/BaseComponent.h \
    src/core/AppController.h \
    src/modules/mindwave/MindwaveModule.h \
    src/modules/BaseModule.h \
    src/network/http/HTTPClient.h \
    src/network/socketClient/TCPSocketClient.h \
    src/screens/BaseScreen.h \
    src/screens/Gamescreen.h \
    src/tools/AppSettings.h \
    src/tools/FileReader.h \
    src/tools/MathTools.h \
    src/tools/StringTools.h
