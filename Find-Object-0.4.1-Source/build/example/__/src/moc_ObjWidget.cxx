/****************************************************************************
** Meta object code from reading C++ file 'ObjWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ObjWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ObjWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      40,   10,   10,   10, 0x05,
      59,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ObjWidget[] = {
    "ObjWidget\0\0removalTriggered(ObjWidget*)\0"
    "selectionChanged()\0roiChanged(QRect)\0"
};

void ObjWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjWidget *_t = static_cast<ObjWidget *>(_o);
        switch (_id) {
        case 0: _t->removalTriggered((*reinterpret_cast< ObjWidget*(*)>(_a[1]))); break;
        case 1: _t->selectionChanged(); break;
        case 2: _t->roiChanged((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ObjWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ObjWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ObjWidget,
      qt_meta_data_ObjWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ObjWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ObjWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ObjWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObjWidget))
        return static_cast<void*>(const_cast< ObjWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ObjWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ObjWidget::removalTriggered(ObjWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObjWidget::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ObjWidget::roiChanged(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
