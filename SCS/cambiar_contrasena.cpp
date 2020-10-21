#include "cambiar_contrasena.h"
#include "ui_cambiar_contrasena.h"

Cambiar_Contrasena::Cambiar_Contrasena(QString id_usuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cambiar_Contrasena)
{
    ui->setupUi(this);
    this->id_usuario=id_usuario;
    this->mdb=QSqlDatabase::database("Connection");
}

Cambiar_Contrasena::~Cambiar_Contrasena()
{
    delete ui;
}

void Cambiar_Contrasena::on_Actualizar_clicked()
{

}

void Cambiar_Contrasena::on_Regresar_clicked()
{

}
