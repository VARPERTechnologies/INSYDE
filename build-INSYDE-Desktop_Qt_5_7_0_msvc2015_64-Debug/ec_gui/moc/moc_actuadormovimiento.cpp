/****************************************************************************
** Meta object code from reading C++ file 'actuadormovimiento.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/ec_gui/actuadormovimiento.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'actuadormovimiento.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MovingActuator_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MovingActuator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MovingActuator_t qt_meta_stringdata_MovingActuator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MovingActuator"
QT_MOC_LITERAL(1, 15, 18), // "llegoADestinoFinal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "point"
QT_MOC_LITERAL(4, 41, 17), // "checkPointReached"
QT_MOC_LITERAL(5, 59, 15), // "positionChanged"
QT_MOC_LITERAL(6, 75, 24), // "checkPointHasBeenReached"
QT_MOC_LITERAL(7, 100, 10), // "posChanged"
QT_MOC_LITERAL(8, 111, 5) // "valor"

    },
    "MovingActuator\0llegoADestinoFinal\0\0"
    "point\0checkPointReached\0positionChanged\0"
    "checkPointHasBeenReached\0posChanged\0"
    "valor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MovingActuator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x09 /* Protected */,
       7,    1,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    8,

       0        // eod
};

void MovingActuator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MovingActuator *_t = static_cast<MovingActuator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->llegoADestinoFinal((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->checkPointReached((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->positionChanged((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 3: _t->checkPointHasBeenReached(); break;
        case 4: _t->posChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MovingActuator::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MovingActuator::llegoADestinoFinal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MovingActuator::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MovingActuator::checkPointReached)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MovingActuator::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MovingActuator::positionChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MovingActuator::staticMetaObject = {
    { &Actuator::staticMetaObject, qt_meta_stringdata_MovingActuator.data,
      qt_meta_data_MovingActuator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MovingActuator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MovingActuator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MovingActuator.stringdata0))
        return static_cast<void*>(const_cast< MovingActuator*>(this));
    return Actuator::qt_metacast(_clname);
}

int MovingActuator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Actuator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MovingActuator::llegoADestinoFinal(const QPointF & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MovingActuator::checkPointReached(const QPointF & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MovingActuator::positionChanged(const QPointF & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE