#include "backend.h"
#include "qjsonobject.h"

Backend::Backend(QObject *parent)
    : QObject{parent}
{
    _loaded = true;
    emit loadedChanged();
    loadData();

    _watcherFile = new QFileSystemWatcher();
    _watcherFile->addPath("./Tariffs.json");
    connect(_watcherFile, &QFileSystemWatcher::fileChanged, this, &Backend::loadData);

    connect(this, &Backend::needMMSChanged, this, &Backend::sorting);
    connect(this, &Backend::needSMSChanged, this, &Backend::sorting);
    connect(this, &Backend::needWAPChanged, this, &Backend::sorting);
    connect(this, &Backend::maxCostChanged, this, &Backend::sorting);
    connect(this, &Backend::minCostChanged, this, &Backend::sorting);
    connect(this, &Backend::maxTariffPlanChanged, this, &Backend::sorting);
    connect(this, &Backend::minTariffPlanChanged, this, &Backend::sorting);
}

void Backend::loadData()
{
    _listTarifs.clear();
    auto file = QFile("./Tariffs.json");

    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }
    json = QJsonDocument::fromJson(file.readAll());

    for (auto object : json.array()) {
        auto obj = object.toObject();
        _listTarifs.append(new Tarif(obj, this));
    }
    file.close();
    sorting();
}

double Backend::calculateRaiting(Tarif *tarif)
{
    return tarif->tariffPlan
           + tarif->costRoaming
                 / (tarif->zone * (tarif->sms ? 1.1 : 1) * (tarif->mms ? 1.1 : 1)
                    * (tarif->wap ? 1.1 : 1));
}

QList<Tarif *> Backend::listTarifs() const
{
    return _subSorting;
}

void Backend::setListTarifs(const QList<Tarif *> &newListTarifs)
{
    if (_listTarifs == newListTarifs)
        return;
    _listTarifs = newListTarifs;
    emit listTarifsChanged();
}
double Backend::maxCost() const
{
    return m_maxCost;
}

void Backend::setMaxCost(double newMaxCost)
{
    if (qFuzzyCompare(m_maxCost, newMaxCost))
        return;
    m_maxCost = newMaxCost;
    emit maxCostChanged();
}

double Backend::minCost() const
{
    return m_minCost;
}

void Backend::setMinCost(double newMinCost)
{
    if (qFuzzyCompare(m_minCost, newMinCost))
        return;
    m_minCost = newMinCost;
    emit minCostChanged();
}

double Backend::maxTariffPlan() const
{
    return m_maxTariffPlan;
}

void Backend::setMaxTariffPlan(double newMaxTariffPlan)
{
    if (qFuzzyCompare(m_maxTariffPlan, newMaxTariffPlan))
        return;
    m_maxTariffPlan = newMaxTariffPlan;
    emit maxTariffPlanChanged();
}

double Backend::minTariffPlan() const
{
    return m_minTariffPlan;
}

void Backend::setMinTariffPlan(double newMinTariffPlan)
{
    if (qFuzzyCompare(m_minTariffPlan, newMinTariffPlan))
        return;
    m_minTariffPlan = newMinTariffPlan;
    emit minTariffPlanChanged();
}

void Backend::sorting()
{
    _subSorting = filterList();
    _loaded = false;
    emit loadedChanged();
    std::sort(_subSorting.begin(), _subSorting.end(), [this](Tarif *left, Tarif *right) {
        // Соотношение цена/уровень приема

        //double leftRaiting = left->tariffPlan * left->costRoaming / (left->zone);
        //double rightRaiting = right->tariffPlan * right->costRoaming / (right->zone);

        double leftRaiting = calculateRaiting(left);
        double rightRaiting = calculateRaiting(right);

        return leftRaiting < rightRaiting;
    });
    emit listTarifsChanged();
}

QList<Tarif *> Backend::filterList()
{
    QList<Tarif *> filtredList;

    for (auto item : _listTarifs) {
        if (item->tariffPlan > m_maxTariffPlan || item->tariffPlan < m_minTariffPlan)
            continue;
        if (item->costRoaming > m_maxCost || item->costRoaming < m_minCost)
            continue;

        if (_needMMS && _needMMS != item->mms)
            continue;

        if (_needSMS && _needSMS != item->sms)
            continue;

        if (_needWAP && _needWAP != item->wap)
            continue;
        filtredList.append(item);
    }

    return filtredList;
}

void Backend::setneedWAP(bool newNeedWAP)
{
    if (_needWAP == newNeedWAP)
        return;
    _needWAP = newNeedWAP;
    emit needWAPChanged();
}

void Backend::setneedMMS(bool newNeedMMS)
{
    if (_needMMS == newNeedMMS)
        return;
    _needMMS = newNeedMMS;
    emit needMMSChanged();
}

void Backend::setneedSMS(bool newNeedSMS)
{
    if (_needSMS == newNeedSMS)
        return;
    _needSMS = newNeedSMS;
    emit needSMSChanged();
}

void Backend::setLoaded(bool newLoaded)
{
    if (_loaded == newLoaded)
        return;
    _loaded = newLoaded;
    emit loadedChanged();
}

bool Backend::needWAP() const
{
    return _needWAP;
}

bool Backend::needMMS() const
{
    return _needMMS;
}

bool Backend::needSMS() const
{
    return _needSMS;
}

bool Backend::loaded() const
{
    return _loaded;
}
