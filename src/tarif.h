#ifndef TARIF_H
#define TARIF_H

#include <QJsonDocument>
#include <QObject>
#include "qjsonobject.h"
class Tarif : public QObject
{
    Q_OBJECT
public:
    explicit Tarif(QObject *parent = nullptr);
    Tarif(QJsonObject doc, QObject *parent = nullptr);

    QString name;
    double zone = 0;
    double tariffPlan = 0;
    double costRoaming = 0;
    bool sms = false;
    bool mms = false;
    bool wap = false;

    Q_PROPERTY(QString name MEMBER name CONSTANT FINAL)
    Q_PROPERTY(double tariffPlan MEMBER tariffPlan CONSTANT FINAL)
    Q_PROPERTY(double costRoaming MEMBER costRoaming CONSTANT FINAL)
    Q_PROPERTY(double zone MEMBER zone CONSTANT FINAL)
    Q_PROPERTY(bool sms MEMBER sms CONSTANT FINAL)
    Q_PROPERTY(bool mms MEMBER mms CONSTANT FINAL)
    Q_PROPERTY(bool wap MEMBER wap CONSTANT FINAL)
};

#endif // TARIF_H
