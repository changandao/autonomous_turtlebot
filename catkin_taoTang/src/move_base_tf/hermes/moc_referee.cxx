/****************************************************************************
** Meta object code from reading C++ file 'referee.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "referee.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'referee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Referee[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      24,    8,    8,    8, 0x05,
      41,    8,    8,    8, 0x05,
      53,    8,    8,    8, 0x05,
      68,   64,    8,    8, 0x05,
      98,   92,    8,    8, 0x05,
     125,    8,    8,    8, 0x05,
     140,    8,    8,    8, 0x05,
     152,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     168,    8,    8,    8, 0x08,
     179,    8,    8,    8, 0x08,
     195,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Referee[] = {
    "Referee\0\0disconnected()\0detectionStart()\0"
    "gameStart()\0gameOver()\0a,b\0"
    "abValues(double,double)\0color\0"
    "trueColorOfTeam(TeamColor)\0stopMovement()\0"
    "connected()\0connectFailed()\0slotRead()\0"
    "slotConnected()\0slotDisconnected()\0"
};

void Referee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Referee *_t = static_cast<Referee *>(_o);
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->detectionStart(); break;
        case 2: _t->gameStart(); break;
        case 3: _t->gameOver(); break;
        case 4: _t->abValues((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->trueColorOfTeam((*reinterpret_cast< TeamColor(*)>(_a[1]))); break;
        case 6: _t->stopMovement(); break;
        case 7: _t->connected(); break;
        case 8: _t->connectFailed(); break;
        case 9: _t->slotRead(); break;
        case 10: _t->slotConnected(); break;
        case 11: _t->slotDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Referee::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Referee::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Referee,
      qt_meta_data_Referee, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Referee::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Referee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Referee::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Referee))
        return static_cast<void*>(const_cast< Referee*>(this));
    return QObject::qt_metacast(_clname);
}

int Referee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Referee::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Referee::detectionStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Referee::gameStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Referee::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Referee::abValues(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Referee::trueColorOfTeam(TeamColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Referee::stopMovement()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Referee::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Referee::connectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
