/****************************************************************************
** Meta object code from reading C++ file 'track.h'
**
** Created: Mon Sep 9 08:06:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "track.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'track.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_track[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      33,    6,    6,    6, 0x08,
      57,    6,    6,    6, 0x08,
      83,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_track[] = {
    "track\0\0on_pushButton_3_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_4_clicked()\0"
};

void track::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        track *_t = static_cast<track *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData track::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject track::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_track,
      qt_meta_data_track, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &track::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *track::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *track::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_track))
        return static_cast<void*>(const_cast< track*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int track::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
