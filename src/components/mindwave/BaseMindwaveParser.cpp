#include "BaseMindwaveParser.h"

BaseMindwaveParser::BaseMindwaveParser(QObject *parent) : QObject(parent)
{

}

BaseMindwaveParser::~BaseMindwaveParser()
{

}

void BaseMindwaveParser::onDataRecieve(const QByteArray& data)
{
    parse(data);
}

void BaseMindwaveParser::parse(const QByteArray& data)
{

}

