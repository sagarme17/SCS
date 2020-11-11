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
    void GenerarEstAprobado();
    void visualizarProyeccion();
    void marcar_Materias();
    void generar_PDF_Por_Cursar();
    void generar_pdf_formato_kardex();
    void marcar_materias_cursando();


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
    //QCOMPARE(conexion->CambiarContraAlumno(201617587,123456789),true);
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
     //QCOMPARE(conexion->BuscarSolicitud(201624489),true);
}
void Pruebas0::RestablecerContra()
{
   // QVERIFY(conexion->RestablecerContrasena(201617942));
}
void Pruebas0::MateriasPorCursar()
{
   // QCOMPARE(conexion->MarcarMateriasPorCursar(201617942,"CCOS 007"),true);
}
void Pruebas0::MapaGrafico()
{
   //QCOMPARE(conexion->VisualizarAvance(201617847),true);
}
void Pruebas0::GenerarEstAprobado()
{
    //QCOMPARE(conexion->generarPDFAprobado(201624489),true);
}
void Pruebas0::visualizarProyeccion()
{
   // QCOMPARE(conexion->VisualizarProyeccion(201617587),true);
}
void Pruebas0::marcar_Materias()
{
    //QCOMPARE(conexion->marcar_Materias(201617587,"FGUS 001","Aprobada"),true);
}
void Pruebas0::generar_PDF_Por_Cursar()
{
    //QCOMPARE(conexion->generar_PDF_MateriasCursando(202000000),true);
}
void Pruebas0::generar_pdf_formato_kardex()
{
    QCOMPARE(conexion->generar_pdf_formato_kardex(201617587),true);
}
void Pruebas0::marcar_materias_cursando()
{
    QCOMPARE(conexion->marcar_materias_cursando(201617587,"FGUS 001","Marcada"),true);
}

QTEST_APPLESS_MAIN(Pruebas0)

#include "tst_pruebas0.moc"
