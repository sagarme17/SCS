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
    /*---Pruebas Sprint 2---*/
    bool generarPDF(int);
    bool HacerSolicitud(int);
    bool BuscarSolicitud(int);
    bool RestablecerContrasena(int);
    bool MarcarMateriasPorCursar(int,QString);
    /*---Pruebas Sprint 3---*/
    bool VisualizarAvance(int);
    bool generarPDFAprobado(int);
    /*---Pruebas Sprint 4 --*/
    bool VisualizarProyeccion(int);
    bool marcar_Materias(int, QString,QString);
    bool generar_PDF_MateriasCursando(int);







};

#endif // BASEDEDATOS_H
