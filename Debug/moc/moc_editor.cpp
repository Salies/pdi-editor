/****************************************************************************
** Meta object code from reading C++ file 'editor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../editor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_editor_t {
    QByteArrayData data[17];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_editor_t qt_meta_stringdata_editor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "editor"
QT_MOC_LITERAL(1, 7, 5), // "abrir"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 6), // "salvar"
QT_MOC_LITERAL(4, 21, 4), // "sair"
QT_MOC_LITERAL(5, 26, 17), // "converteParaCinza"
QT_MOC_LITERAL(6, 44, 10), // "dividirRGB"
QT_MOC_LITERAL(7, 55, 12), // "inverteCinza"
QT_MOC_LITERAL(8, 68, 15), // "inverteColorido"
QT_MOC_LITERAL(9, 84, 19), // "equalizarHistograma"
QT_MOC_LITERAL(10, 104, 13), // "addSaltPepper"
QT_MOC_LITERAL(11, 118, 11), // "janelaSobre"
QT_MOC_LITERAL(12, 130, 17), // "copiaParaEsquerda"
QT_MOC_LITERAL(13, 148, 16), // "converterRGB_HSL"
QT_MOC_LITERAL(14, 165, 12), // "atualizarPos"
QT_MOC_LITERAL(15, 178, 1), // "x"
QT_MOC_LITERAL(16, 180, 1) // "y"

    },
    "editor\0abrir\0\0salvar\0sair\0converteParaCinza\0"
    "dividirRGB\0inverteCinza\0inverteColorido\0"
    "equalizarHistograma\0addSaltPepper\0"
    "janelaSobre\0copiaParaEsquerda\0"
    "converterRGB_HSL\0atualizarPos\0x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_editor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    2,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

       0        // eod
};

void editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abrir(); break;
        case 1: _t->salvar(); break;
        case 2: _t->sair(); break;
        case 3: _t->converteParaCinza(); break;
        case 4: _t->dividirRGB(); break;
        case 5: _t->inverteCinza(); break;
        case 6: _t->inverteColorido(); break;
        case 7: _t->equalizarHistograma(); break;
        case 8: _t->addSaltPepper(); break;
        case 9: _t->janelaSobre(); break;
        case 10: _t->copiaParaEsquerda(); break;
        case 11: _t->converterRGB_HSL(); break;
        case 12: _t->atualizarPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject editor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_editor.data,
    qt_meta_data_editor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_editor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
