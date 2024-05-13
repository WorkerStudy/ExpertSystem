#include "tarif.h"

Tarif::Tarif(QObject *parent)
    : QObject{parent}
{}

Tarif::Tarif(QJsonObject doc, QObject *parent)
    : QObject{parent}
{
    name = doc["name"].toString();
    zone = doc["zone"].toDouble();
    costRoaming = doc["costRoaming"].toDouble();
    tariffPlan = doc["tariffPlan"].toDouble();
    sms = doc["sms"].toBool();
    mms = doc["mms"].toBool();
    wap = doc["wap"].toBool();
}
