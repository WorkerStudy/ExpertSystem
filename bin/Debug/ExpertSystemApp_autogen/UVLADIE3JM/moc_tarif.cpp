/****************************************************************************
** Meta object code from reading C++ file 'tarif.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/tarif.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tarif.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTarifENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTarifENDCLASS = QtMocHelpers::stringData(
    "Tarif",
    "name",
    "tariffPlan",
    "costRoaming",
    "zone",
    "sms",
    "mms",
    "wap"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTarifENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[6];
    char stringdata1[5];
    char stringdata2[11];
    char stringdata3[12];
    char stringdata4[5];
    char stringdata5[4];
    char stringdata6[4];
    char stringdata7[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTarifENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTarifENDCLASS_t qt_meta_stringdata_CLASSTarifENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Tarif"
        QT_MOC_LITERAL(6, 4),  // "name"
        QT_MOC_LITERAL(11, 10),  // "tariffPlan"
        QT_MOC_LITERAL(22, 11),  // "costRoaming"
        QT_MOC_LITERAL(34, 4),  // "zone"
        QT_MOC_LITERAL(39, 3),  // "sms"
        QT_MOC_LITERAL(43, 3),  // "mms"
        QT_MOC_LITERAL(47, 3)   // "wap"
    },
    "Tarif",
    "name",
    "tariffPlan",
    "costRoaming",
    "zone",
    "sms",
    "mms",
    "wap"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTarifENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015c01, uint(-1), 0,
       2, QMetaType::Double, 0x00015c01, uint(-1), 0,
       3, QMetaType::Double, 0x00015c01, uint(-1), 0,
       4, QMetaType::Double, 0x00015c01, uint(-1), 0,
       5, QMetaType::Bool, 0x00015c01, uint(-1), 0,
       6, QMetaType::Bool, 0x00015c01, uint(-1), 0,
       7, QMetaType::Bool, 0x00015c01, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Tarif::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTarifENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTarifENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTarifENDCLASS_t,
        // property 'name'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'tariffPlan'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'costRoaming'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'zone'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'sms'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'mms'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'wap'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Tarif, std::true_type>
    >,
    nullptr
} };

void Tarif::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Tarif *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name; break;
        case 1: *reinterpret_cast< double*>(_v) = _t->tariffPlan; break;
        case 2: *reinterpret_cast< double*>(_v) = _t->costRoaming; break;
        case 3: *reinterpret_cast< double*>(_v) = _t->zone; break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->sms; break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->mms; break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->wap; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *Tarif::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tarif::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTarifENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tarif::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
