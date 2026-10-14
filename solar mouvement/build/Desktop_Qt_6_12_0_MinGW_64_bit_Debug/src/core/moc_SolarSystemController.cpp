/****************************************************************************
** Meta object code from reading C++ file 'SolarSystemController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/core/SolarSystemController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SolarSystemController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
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
struct qt_meta_tag_ZN21SolarSystemControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto SolarSystemController::qt_create_metaobjectdata<qt_meta_tag_ZN21SolarSystemControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SolarSystemController",
        "changed",
        "",
        "tick",
        "setLatitude",
        "setLongitude",
        "setSpeed",
        "pauseResume",
        "advance",
        "setDateTime",
        "setMinuteOfDay",
        "realTime",
        "sunriseTime",
        "solarNoon",
        "sunsetTime",
        "sun",
        "Sun*",
        "dateTime",
        "latitude",
        "longitude",
        "speed",
        "running",
        "sunrise",
        "sunset",
        "minuteOfDay"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'tick'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setLatitude'
        QtMocHelpers::SlotData<void(double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'setLongitude'
        QtMocHelpers::SlotData<void(double)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(double)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Slot 'pauseResume'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'advance'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'setDateTime'
        QtMocHelpers::SlotData<void(QDateTime)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDateTime, 2 },
        }}),
        // Slot 'setMinuteOfDay'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'realTime'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sunriseTime'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'solarNoon'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sunsetTime'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'sun'
        QtMocHelpers::PropertyData<Sun*>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'dateTime'
        QtMocHelpers::PropertyData<QDateTime>(17, QMetaType::QDateTime, QMC::DefaultPropertyFlags, 0),
        // property 'latitude'
        QtMocHelpers::PropertyData<double>(18, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'longitude'
        QtMocHelpers::PropertyData<double>(19, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'speed'
        QtMocHelpers::PropertyData<double>(20, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'running'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'sunrise'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'sunset'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'minuteOfDay'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SolarSystemController, qt_meta_tag_ZN21SolarSystemControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SolarSystemController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21SolarSystemControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21SolarSystemControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21SolarSystemControllerE_t>.metaTypes,
    nullptr
} };

void SolarSystemController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SolarSystemController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->tick(); break;
        case 2: _t->setLatitude((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->setLongitude((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->setSpeed((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->pauseResume(); break;
        case 6: _t->advance((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setDateTime((*reinterpret_cast<std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 8: _t->setMinuteOfDay((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->realTime(); break;
        case 10: _t->sunriseTime(); break;
        case 11: _t->solarNoon(); break;
        case 12: _t->sunsetTime(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SolarSystemController::*)()>(_a, &SolarSystemController::changed, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sun* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Sun**>(_v) = _t->sun(); break;
        case 1: *reinterpret_cast<QDateTime*>(_v) = _t->dateTime(); break;
        case 2: *reinterpret_cast<double*>(_v) = _t->latitude(); break;
        case 3: *reinterpret_cast<double*>(_v) = _t->longitude(); break;
        case 4: *reinterpret_cast<double*>(_v) = _t->speed(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->running(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->sunrise(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->sunset(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->minuteOfDay(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setLatitude(*reinterpret_cast<double*>(_v)); break;
        case 3: _t->setLongitude(*reinterpret_cast<double*>(_v)); break;
        case 4: _t->setSpeed(*reinterpret_cast<double*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *SolarSystemController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SolarSystemController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21SolarSystemControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SolarSystemController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SolarSystemController::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
