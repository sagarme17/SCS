QT += testlib
QT += core gui sql


TARGER = CodeCoveragePrueba

CONFIG += qt console warn_on depend_includepath testcase


TEMPLATE = app

# --coverage option is synonym for: -fprofile-arcs -ftest-coverage -lgcov
QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

include( $$PWD/tests/Tests.pri )

SOURCES +=  tst_pruebas0.cpp \
    basededatos.cpp

HEADERS += \
    basededatos.h
