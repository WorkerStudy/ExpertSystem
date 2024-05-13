#ifndef BACKEND_H
#define BACKEND_H

#include <QFile>
#include <QFileSystemWatcher>
#include <QJsonArray>
#include <QObject>
#include "qjsondocument.h"
#include "src/tarif.h"
class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Tarif *> listTarifs READ listTarifs WRITE setListTarifs NOTIFY
                   listTarifsChanged FINAL)
    Q_PROPERTY(bool needWAP READ needWAP WRITE setneedWAP NOTIFY needWAPChanged)
    Q_PROPERTY(bool needMMS READ needMMS WRITE setneedMMS NOTIFY needMMSChanged)
    Q_PROPERTY(bool needSMS READ needSMS WRITE setneedSMS NOTIFY needSMSChanged)
    Q_PROPERTY(double maxCost READ maxCost WRITE setMaxCost NOTIFY maxCostChanged)
    Q_PROPERTY(double minCost READ minCost WRITE setMinCost NOTIFY minCostChanged)
    Q_PROPERTY(
        double maxTariffPlan READ maxTariffPlan WRITE setMaxTariffPlan NOTIFY maxTariffPlanChanged)
    Q_PROPERTY(
        double minTariffPlan READ minTariffPlan WRITE setMinTariffPlan NOTIFY minTariffPlanChanged)
    Q_PROPERTY(bool loaded READ loaded WRITE setLoaded NOTIFY loadedChanged)

public:
    explicit Backend(QObject *parent = nullptr);
    QList<Tarif *> listTarifs() const;

    void setListTarifs(const QList<Tarif *> &newListTarifs);

    double maxCost() const;
    void setMaxCost(double newMaxCost);

    double minCost() const;
    void setMinCost(double newMinCost);

    double maxTariffPlan() const;
    void setMaxTariffPlan(double newMaxTariffPlan);

    double minTariffPlan() const;
    void setMinTariffPlan(double newMinTariffPlan);

    void setneedWAP(bool newNeedWAP);

    void setneedMMS(bool newNeedMMS);

    void setneedSMS(bool newNeedSMS);

    void setLoaded(bool newLoaded);

    bool needWAP() const;

    bool needMMS() const;

    bool needSMS() const;

    bool loaded() const;

public slots:
    void sorting();
    void loadData();
signals:
    void listTarifsChanged();

    void needWAPChanged();

    void needMMSChanged();

    void needSMSChanged();

    void maxCostChanged();

    void minCostChanged();

    void maxTariffPlanChanged();

    void minTariffPlanChanged();

    void loadedChanged();

private:
    double calculateRaiting(Tarif *tarif);
    QFileSystemWatcher *_watcherFile;
    QList<Tarif *> filterList();

    QList<Tarif *> _listTarifs;
    QList<Tarif *> _subSorting;
    QJsonDocument json;
    bool _needWAP = false;
    bool _needMMS = false;
    bool _needSMS = false;
    double m_maxCost = 1000;
    double m_minCost = 0;
    double m_maxTariffPlan = 1000;
    double m_minTariffPlan = 0;
    bool _loaded = false;
};

#endif // BACKEND_H
