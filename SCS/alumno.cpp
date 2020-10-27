#include "alumno.h"
#include "cambiar_contrasena.h"
#include "ui_alumno.h"
#include "foto.h"
#include "materias_por_cursar.h"
#include "ui_materias_por_cursar.h"

alumno::alumno(QString Matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumno)
{
    ui->setupUi(this);
    this->Matricula=Matricula;
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
    materias_por_cursar PorCursar(Matricula);
    PorCursar.setWindowTitle("Materias por cursar");
    PorCursar.exec();
}
