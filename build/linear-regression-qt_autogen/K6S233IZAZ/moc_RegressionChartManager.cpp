/****************************************************************************
** Meta object code from reading C++ file 'RegressionChartManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../headers/RegressionChartManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegressionChartManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegressionChartManager_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegressionChartManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegressionChartManager_t qt_meta_stringdata_RegressionChartManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "RegressionChartManager"
QT_MOC_LITERAL(1, 23, 9), // "add_point"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 1), // "x"
QT_MOC_LITERAL(4, 36, 1), // "y"
QT_MOC_LITERAL(5, 38, 11), // "erase_point"
QT_MOC_LITERAL(6, 50, 16), // "apply_regression"
QT_MOC_LITERAL(7, 67, 13), // "load_csv_file"
QT_MOC_LITERAL(8, 81, 7), // "fileUrl"
QT_MOC_LITERAL(9, 89, 22), // "generate_random_points"
QT_MOC_LITERAL(10, 112, 1), // "n"
QT_MOC_LITERAL(11, 114, 13) // "save_csv_file"

    },
    "RegressionChartManager\0add_point\0\0x\0"
    "y\0erase_point\0apply_regression\0"
    "load_csv_file\0fileUrl\0generate_random_points\0"
    "n\0save_csv_file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegressionChartManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    2,   49,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    3,    4,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QUrl,    8,

       0        // eod
};

void RegressionChartManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegressionChartManager *_t = static_cast<RegressionChartManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_point((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 1: _t->erase_point((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 2: _t->apply_regression(); break;
        case 3: _t->load_csv_file((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->generate_random_points((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->save_csv_file((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RegressionChartManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RegressionChartManager.data,
      qt_meta_data_RegressionChartManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RegressionChartManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegressionChartManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegressionChartManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RegressionChartManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
