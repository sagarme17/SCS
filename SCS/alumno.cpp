#include "alumno.h"
#include "cambiar_contrasena.h"
#include "ui_alumno.h"
#include "foto.h"
#include "materias_por_cursar.h"
#include "ui_materias_por_cursar.h"
#include <QMessageBox>

alumno::alumno(QString Matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumno)
{
    ui->setupUi(this);
    this->Matricula=Matricula;
    this->mdb=QSqlDatabase::database("Connection");
}

alumno::~alumno()
{
    delete ui;
}

void alumno::on_Cambio_al_clicked()
{
    Cambiar_Contrasena windows(Matricula, this);
    windows.setWindowTitle("Cambiar contraseña");
    windows.exec();
}

void alumno::on_Cerrar_Sesion_clicked()
{
    close();
}

void alumno::on_Cambiar_Foto_objectNameChanged(const QString &objectName)
{

}

void alumno::on_Cambiar_Foto_clicked()
{
    Foto camb_foto(Matricula, this);
    camb_foto.setWindowTitle("Actualizar Perfil");
    camb_foto.exec();
}

void alumno::on_Cambio_al_2_clicked()
{
    if(mdb.open()){
        QSqlQuery porcur(mdb);
        porcur.prepare("select * from porcursar where matricula='"+Matricula+"'");
        porcur.exec();
        if(porcur.next()){
            QMessageBox::warning(this,"Solicitud enviada","Ya has llenado la solicitud de materias por cursar.\nGracias.","Aceptar");
        }
        else{
            materias_por_cursar PorCursar(Matricula,this);
            PorCursar.setWindowTitle("Materias por cursar");
            PorCursar.exec();
        }
    }

}
