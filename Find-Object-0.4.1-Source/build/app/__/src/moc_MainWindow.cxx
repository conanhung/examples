/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   11,   11,   11, 0x0a,
      79,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x08,
     133,   11,  128,   11, 0x08,
     147,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     190,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     277,  270,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,
     321,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     385,  379,   11,   11, 0x08,
     401,   11,   11,   11, 0x08,
     423,  417,   11,   11, 0x08,
     466,  460,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0"
    "objectsFound(QMap<int,QPair<QRect,QTransform> >)\0"
    "startProcessing()\0stopProcessing()\0"
    "pauseProcessing()\0loadObjects()\0bool\0"
    "saveObjects()\0addObjectFromScene()\0"
    "addObjectsFromFiles()\0loadSceneFromFile()\0"
    "setupCameraFromVideoFile()\0"
    "setupCameraFromImagesDirectory()\0"
    "object\0removeObject(ObjWidget*)\0"
    "removeAllObjects()\0updateObjectsSize()\0"
    "updateMirrorView()\0showHideControls()\0"
    "image\0update(cv::Mat)\0updateObjects()\0"
    "param\0notifyParametersChanged(QStringList)\0"
    "frame\0moveCameraFrame(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->objectsFound((*reinterpret_cast< const QMap<int,QPair<QRect,QTransform> >(*)>(_a[1]))); break;
        case 1: _t->startProcessing(); break;
        case 2: _t->stopProcessing(); break;
        case 3: _t->pauseProcessing(); break;
        case 4: _t->loadObjects(); break;
        case 5: { bool _r = _t->saveObjects();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->addObjectFromScene(); break;
        case 7: _t->addObjectsFromFiles(); break;
        case 8: _t->loadSceneFromFile(); break;
        case 9: _t->setupCameraFromVideoFile(); break;
        case 10: _t->setupCameraFromImagesDirectory(); break;
        case 11: _t->removeObject((*reinterpret_cast< ObjWidget*(*)>(_a[1]))); break;
        case 12: _t->removeAllObjects(); break;
        case 13: _t->updateObjectsSize(); break;
        case 14: _t->updateMirrorView(); break;
        case 15: _t->showHideControls(); break;
        case 16: _t->update((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 17: _t->updateObjects(); break;
        case 18: _t->notifyParametersChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 19: _t->moveCameraFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::objectsFound(const QMap<int,QPair<QRect,QTransform> > & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
