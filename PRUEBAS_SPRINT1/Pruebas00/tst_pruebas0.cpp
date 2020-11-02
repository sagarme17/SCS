#include <QtTest>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "basededatos.h"


// add necessary includes here

class Pruebas0 : public QObject
{
    Q_OBJECT

public:
    Pruebas0();
    ~Pruebas0();
    baseDatos *conexion;

private slots:
    void conexionBase();
    void AutenticarseAdmin();
    void AutenticarseAlumno1();
    void CambiarContraAdmin();
    void CambiarContraAlumno();
    void GeneralAutenticarse();
    void Foto();
    void GenerarEst();
    void Solicitud_p1();
    void Solicitud_p2();
    void RestablecerContra();
    void MateriasPorCursar();
    void MapaGrafico();


};

Pruebas0::Pruebas0()
{
    conexion = new baseDatos();
}
Pruebas0::~Pruebas0(){}

void Pruebas0::conexionBase()
{

    QVERIFY(conexion->mDatabase.open());
}
void Pruebas0::AutenticarseAdmin()
{
    //QCOMPARE(conexion->AutenticarseAdmin1(),true);
}
void Pruebas0::AutenticarseAlumno1()
{
    QCOMPARE(conexion->AutenticarseAlumno_1ra(),true);
}
void Pruebas0::CambiarContraAdmin()
{
    QCOMPARE(conexion->CambiarContraAdmin(12345),true);
}
void Pruebas0::CambiarContraAlumno()
{
    QCOMPARE(conexion->CambiarContraAlumno(201617587,123456789),true);
}
void Pruebas0::GeneralAutenticarse()
{
    //QCOMPARE(conexion->GeneralAutenticarse(201617602,201617602),true);
}
void Pruebas0::Foto()
{
   // QVERIFY(conexion->InsertarFoto1("D:/Descargas/panaMiguel.jpg",201617587));
}
void Pruebas0::GenerarEst()
{
    QCOMPARE(conexion->generarPDF(201772826),true);
}
void Pruebas0::Solicitud_p1()
{
   // QVERIFY(conexion->HacerSolicitud(201618233));
}
void Pruebas0::Solicitud_p2()
{
     QCOMPARE(conexion->BuscarSolicitud(201624489),true);
}
void Pruebas0::RestablecerContra()
{
    QVERIFY(conexion->RestablecerContrasena(201617942));
}
void Pruebas0::MateriasPorCursar()
{
    QCOMPARE(conexion->MarcarMateriasPorCursar(201617942,"CCOS 007"),true);
}
void Pruebas0::MapaGrafico()
{
   QCOMPARE(conexion->VisualizarAvance(201617847),true);
}
QTEST_APPLESS_MAIN(Pruebas0)

#include "tst_pruebas0.moc"
