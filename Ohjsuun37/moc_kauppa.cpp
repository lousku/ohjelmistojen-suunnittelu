/****************************************************************************
** Meta object code from reading C++ file 'kauppa.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kauppa.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kauppa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Kauppa_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Kauppa_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Kauppa_t qt_meta_stringdata_Kauppa = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Kauppa"
QT_MOC_LITERAL(1, 7, 11), // "elamaaLisaa"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "kohde"
QT_MOC_LITERAL(4, 26, 13), // "kantamaaLisaa"
QT_MOC_LITERAL(5, 40, 13), // "nopeuttaLisaa"
QT_MOC_LITERAL(6, 54, 10), // "tehoaLisaa"
QT_MOC_LITERAL(7, 65, 18) // "ammustiheyttaLisaa"

    },
    "Kauppa\0elamaaLisaa\0\0kohde\0kantamaaLisaa\0"
    "nopeuttaLisaa\0tehoaLisaa\0ammustiheyttaLisaa"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kauppa[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x02 /* Public */,
       4,    1,   42,    2, 0x02 /* Public */,
       5,    1,   45,    2, 0x02 /* Public */,
       6,    1,   48,    2, 0x02 /* Public */,
       7,    0,   51,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Bool,

       0        // eod
};

void Kauppa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Kauppa *_t = static_cast<Kauppa *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->elamaaLisaa((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->kantamaaLisaa((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->nopeuttaLisaa((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->tehoaLisaa((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->ammustiheyttaLisaa();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Kauppa::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Kauppa.data,
      qt_meta_data_Kauppa,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Kauppa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kauppa::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Kauppa.stringdata0))
        return static_cast<void*>(const_cast< Kauppa*>(this));
    return QObject::qt_metacast(_clname);
}

int Kauppa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
