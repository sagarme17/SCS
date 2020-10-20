#include "inicio.h"
#include <QtSql/QSqlDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    QSqlDatabase mdb;

    mdb= QSqlDatabase::addDatabase("QODBC","Connection");
    mdb.setDatabaseName("scs");
    QApplication a(argc, argv);
    inicio w;
    w.setWindowTitle("SCS");
    w.show();
    return a.exec();
}
