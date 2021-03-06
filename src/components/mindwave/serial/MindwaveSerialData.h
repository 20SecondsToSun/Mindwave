#ifndef MINDWAVESERIALDATA_H
#define MINDWAVESERIALDATA_H

#include <QObject>

typedef unsigned char uchar;
Q_DECLARE_METATYPE(uchar)

// Parser types
#define PARSER_TYPE_NULL       0x00
#define PARSER_TYPE_PACKETS    0x01    // Stream bytes as ThinkGear Packets
#define PARSER_TYPE_2BYTERAW   0x02    // Stream bytes as 2-byte raw data

// Data CODE definitions
#define PARSER_CODE_BATTERY            0x01
#define PARSER_CODE_POOR_QUALITY       0x02
#define PARSER_CODE_ATTENTION          0x04
#define PARSER_CODE_MEDITATION         0x05
#define PARSER_CODE_8BITRAW_SIGNAL     0x06
#define PARSER_CODE_RAW_MARKER         0x07

#define PARSER_CODE_RAW_SIGNAL         0x80
#define PARSER_CODE_EEG_POWERS         0x81
#define PARSER_CODE_ASIC_EEG_POWER_INT 0x83

// Decoder states (Packet decoding)
#define PARSER_STATE_NULL           0x00  // NULL state
#define PARSER_STATE_SYNC           0x01  // Waiting for SYNC byte
#define PARSER_STATE_SYNC_CHECK     0x02  // Waiting for second SYNC byte
#define PARSER_STATE_PAYLOAD_LENGTH 0x03  // Waiting for payload[] length
#define PARSER_STATE_PAYLOAD        0x04  // Waiting for next payload[] byte
#define PARSER_STATE_CHKSUM         0x05  // Waiting for chksum byte

// Decoder states (2-byte raw decoding) */
#define PARSER_STATE_WAIT_HIGH      0x06  // Waiting for high byte
#define PARSER_STATE_WAIT_LOW       0x07  // High r'cvd.  Expecting low part

/// Other constants
#define PARSER_SYNC_BYTE            0xAA  // Syncronization byte
#define PARSER_EXCODE_BYTE          0x55  // EXtended CODE level byte


// The Parser is a state machine that manages the parsing state.
typedef struct _ThinkGearStreamParser
{
    uchar   type;
    uchar   state;
    uchar   lastByte;
    uchar payloadLength;
    uchar payloadBytesReceived;
    uchar payload[256];
    uchar payloadSum;
    uchar chksum;

    void  *customData;

}
ThinkGearStreamParser;
Q_DECLARE_METATYPE(ThinkGearStreamParser)

#endif // MINDWAVESERIALDATA_H
