/****************************************************************************
** Meta object code from reading C++ file 'graphicobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/graphicobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicObject_t {
    QByteArrayData data[18];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicObject_t qt_meta_stringdata_GraphicObject = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GraphicObject"
QT_MOC_LITERAL(1, 14, 19), // "openOnWindowRequest"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "GraphicObject*"
QT_MOC_LITERAL(4, 50, 3), // "obj"
QT_MOC_LITERAL(5, 54, 13), // "objectRemoved"
QT_MOC_LITERAL(6, 68, 17), // "inputsSizeChanged"
QT_MOC_LITERAL(7, 86, 4), // "size"
QT_MOC_LITERAL(8, 91, 13), // "setInputsSize"
QT_MOC_LITERAL(9, 105, 15), // "setObjectLocked"
QT_MOC_LITERAL(10, 121, 6), // "locked"
QT_MOC_LITERAL(11, 128, 9), // "copyClick"
QT_MOC_LITERAL(12, 138, 8), // "cutClick"
QT_MOC_LITERAL(13, 147, 10), // "pasteClick"
QT_MOC_LITERAL(14, 158, 13), // "propertyClick"
QT_MOC_LITERAL(15, 172, 11), // "removeClick"
QT_MOC_LITERAL(16, 184, 9), // "saveClick"
QT_MOC_LITERAL(17, 194, 17) // "openOnWindowClick"

    },
    "GraphicObject\0openOnWindowRequest\0\0"
    "GraphicObject*\0obj\0objectRemoved\0"
    "inputsSizeChanged\0size\0setInputsSize\0"
    "setObjectLocked\0locked\0copyClick\0"
    "cutClick\0pasteClick\0propertyClick\0"
    "removeClick\0saveClick\0openOnWindowClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   83,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x09 /* Protected */,
      12,    0,   90,    2, 0x09 /* Protected */,
      13,    0,   91,    2, 0x09 /* Protected */,
      14,    0,   92,    2, 0x09 /* Protected */,
      15,    0,   93,    2, 0x09 /* Protected */,
      16,    0,   94,    2, 0x09 /* Protected */,
      17,    0,   95,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicObject *_t = static_cast<GraphicObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openOnWindowRequest((*reinterpret_cast< GraphicObject*(*)>(_a[1]))); break;
        case 1: _t->objectRemoved((*reinterpret_cast< GraphicObject*(*)>(_a[1]))); break;
        case 2: _t->inputsSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setInputsSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setObjectLocked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->copyClick(); break;
        case 6: _t->cutClick(); break;
        case 7: _t->pasteClick(); break;
        case 8: _t->propertyClick(); break;
        case 9: _t->removeClick(); break;
        case 10: _t->saveClick(); break;
        case 11: _t->openOnWindowClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphicObject* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphicObject* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicObject::*_t)(GraphicObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicObject::openOnWindowRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphicObject::*_t)(GraphicObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicObject::objectRemoved)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphicObject::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicObject::inputsSizeChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GraphicObject::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_GraphicObject.data,
      qt_meta_data_GraphicObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphicObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicObject.stringdata0))
        return static_cast<void*>(const_cast< GraphicObject*>(this));
    if (!strcmp(_clname, "ClipboardInterface"))
        return static_cast< ClipboardInterface*>(const_cast< GraphicObject*>(this));
    if (!strcmp(_clname, "ResizableF"))
        return static_cast< ResizableF*>(const_cast< GraphicObject*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int GraphicObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GraphicObject::openOnWindowRequest(GraphicObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicObject::objectRemoved(GraphicObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicObject::inputsSizeChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
