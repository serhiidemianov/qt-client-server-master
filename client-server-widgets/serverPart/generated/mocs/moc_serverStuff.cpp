/****************************************************************************
** Meta object code from reading C++ file 'serverStuff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serverStuff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverStuff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerStuff_t {
    QByteArrayData data[12];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerStuff_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerStuff_t qt_meta_stringdata_ServerStuff = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ServerStuff"
QT_MOC_LITERAL(1, 12, 14), // "gotNewMesssage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "msg"
QT_MOC_LITERAL(4, 32, 15), // "smbDisconnected"
QT_MOC_LITERAL(5, 48, 13), // "newConnection"
QT_MOC_LITERAL(6, 62, 10), // "readClient"
QT_MOC_LITERAL(7, 73, 16), // "gotDisconnection"
QT_MOC_LITERAL(8, 90, 12), // "sendToClient"
QT_MOC_LITERAL(9, 103, 11), // "QTcpSocket*"
QT_MOC_LITERAL(10, 115, 6), // "socket"
QT_MOC_LITERAL(11, 122, 3) // "str"

    },
    "ServerStuff\0gotNewMesssage\0\0msg\0"
    "smbDisconnected\0newConnection\0readClient\0"
    "gotDisconnection\0sendToClient\0QTcpSocket*\0"
    "socket\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerStuff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::LongLong, 0x80000000 | 9, QMetaType::QString,   10,   11,

       0        // eod
};

void ServerStuff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerStuff *_t = static_cast<ServerStuff *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotNewMesssage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->smbDisconnected(); break;
        case 2: _t->newConnection(); break;
        case 3: _t->readClient(); break;
        case 4: _t->gotDisconnection(); break;
        case 5: { qint64 _r = _t->sendToClient((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerStuff::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStuff::gotNewMesssage)) {
                *result = 0;
            }
        }
        {
            typedef void (ServerStuff::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStuff::smbDisconnected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ServerStuff::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerStuff.data,
      qt_meta_data_ServerStuff,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerStuff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerStuff::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerStuff.stringdata0))
        return static_cast<void*>(const_cast< ServerStuff*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerStuff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ServerStuff::gotNewMesssage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerStuff::smbDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
