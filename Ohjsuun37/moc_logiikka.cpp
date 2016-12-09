/****************************************************************************
** Meta object code from reading C++ file 'logiikka.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logiikka.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logiikka.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Logiikka_t {
    QByteArrayData data[11];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logiikka_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logiikka_t qt_meta_stringdata_Logiikka = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Logiikka"
QT_MOC_LITERAL(1, 9, 14), // "suoritaTekoaly"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "asetaKyborginPaamaara"
QT_MOC_LITERAL(4, 47, 1), // "x"
QT_MOC_LITERAL(5, 49, 1), // "y"
QT_MOC_LITERAL(6, 51, 15), // "asetaKaskettava"
QT_MOC_LITERAL(7, 67, 8), // "tunniste"
QT_MOC_LITERAL(8, 76, 8), // "luoAmmus"
QT_MOC_LITERAL(9, 85, 7), // "luoPeli"
QT_MOC_LITERAL(10, 93, 6) // "numero"

    },
    "Logiikka\0suoritaTekoaly\0\0asetaKyborginPaamaara\0"
    "x\0y\0asetaKaskettava\0tunniste\0luoAmmus\0"
    "luoPeli\0numero"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logiikka[] = {

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

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       3,    2,   40,    2, 0x02 /* Public */,
       6,    1,   45,    2, 0x02 /* Public */,
       8,    0,   48,    2, 0x02 /* Public */,
       9,    1,   49,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void Logiikka::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Logiikka *_t = static_cast<Logiikka *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->suoritaTekoaly(); break;
        case 1: _t->asetaKyborginPaamaara((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->asetaKaskettava((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->luoAmmus(); break;
        case 4: _t->luoPeli((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Logiikka::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Logiikka.data,
      qt_meta_data_Logiikka,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Logiikka::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logiikka::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Logiikka.stringdata0))
        return static_cast<void*>(const_cast< Logiikka*>(this));
    return QObject::qt_metacast(_clname);
}

int Logiikka::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
