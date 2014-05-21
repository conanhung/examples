/****************************************************************************
** Meta object code from reading C++ file 'AddObjectDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/AddObjectDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddObjectDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddObjectDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      33,   16,   16,   16, 0x08,
      40,   16,   16,   16, 0x08,
      47,   16,   16,   16, 0x08,
      56,   16,   16,   16, 0x08,
      70,   16,   16,   16, 0x08,
      89,   16,   16,   16, 0x08,
     113,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddObjectDialog[] = {
    "AddObjectDialog\0\0update(cv::Mat)\0"
    "next()\0back()\0cancel()\0takePicture()\0"
    "updateNextButton()\0updateNextButton(QRect)\0"
    "changeSelectionMode()\0"
};

void AddObjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddObjectDialog *_t = static_cast<AddObjectDialog *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 1: _t->next(); break;
        case 2: _t->back(); break;
        case 3: _t->cancel(); break;
        case 4: _t->takePicture(); break;
        case 5: _t->updateNextButton(); break;
        case 6: _t->updateNextButton((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 7: _t->changeSelectionMode(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddObjectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddObjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddObjectDialog,
      qt_meta_data_AddObjectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddObjectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddObjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddObjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddObjectDialog))
        return static_cast<void*>(const_cast< AddObjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddObjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
