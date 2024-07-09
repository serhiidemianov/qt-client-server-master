/****************************************************************************
** Meta object code from reading C++ file 'clientStuff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientStuff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientStuff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientStuff_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientStuff_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientStuff_t qt_meta_stringdata_ClientStuff = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClientStuff"
QT_MOC_LITERAL(1, 12, 13), // "statusChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "hasReadSome"
QT_MOC_LITERAL(4, 39, 3), // "msg"
QT_MOC_LITERAL(5, 43, 15), // "closeConnection"
QT_MOC_LITERAL(6, 59, 12), // "connect2host"
QT_MOC_LITERAL(7, 72, 11), // "sendMessage"
QT_MOC_LITERAL(8, 84, 9), // "readyRead"
QT_MOC_LITERAL(9, 94, 9), // "connected"
QT_MOC_LITERAL(10, 104, 17) // "connectionTimeout"

    },
    "ClientStuff\0statusChanged\0\0hasReadSome\0"
    "msg\0closeConnection\0connect2host\0"
    "sendMessage\0readyRead\0connected\0"
    "connectionTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientStuff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   60,    2, 0x0a /* Public */,
       6,    0,   61,    2, 0x0a /* Public */,
       7,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientStuff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientStuff *_t = static_cast<ClientStuff *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->hasReadSome((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->closeConnection(); break;
        case 3: _t->connect2host(); break;
        case 4: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->readyRead(); break;
        case 6: _t->connected(); break;
        case 7: _t->connectionTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientStuff::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientStuff::statusChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientStuff::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientStuff::hasReadSome)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ClientStuff::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientStuff.data,
      qt_meta_data_ClientStuff,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientStuff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientStuff::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientStuff.stringdata0))
        return static_cast<void*>(const_cast< ClientStuff*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientStuff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ClientStuff::statusChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientStuff::hasReadSome(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
