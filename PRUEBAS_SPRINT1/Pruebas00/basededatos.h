#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class baseDatos
{
public:
    baseDatos();

    QSqlDatabase mDatabase;
    bool AutenticarseAdmin1();
    bool AutenticarseAlumno_1ra();
    bool CambiarContraAdmin(int);
    bool CambiarContraAlumno(int,int);
    bool GeneralAutenticarse(int,int);
    bool InsertarFoto1(QString,int);







};

#endif // BASEDEDATOS_H
