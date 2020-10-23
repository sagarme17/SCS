#include "administrador.h"
#include "cambiar_contrasena.h"
#include "ui_administrador.h"
#include "recuperar_contrasena.h"
#include "ui_recuperar_contrasena.h"



administrador::administrador(QString Id_Administrador,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador)
{
    ui->setupUi(this);
    this->Id_Administrador=Id_Administrador;
    this->mdb=QSqlDatabase::database("Connection");
    if(mdb.open()){
        QSqlQuery nombre(mdb);
        nombre.prepare("select nombre from usuario where Id_Usuario='"+Id_Administrador+"'");
        nombre.exec();
        nombre.next();
        ui->label_2->setText(nombre.value(0).toString());
}
}

administrador::~administrador()
{
    delete ui;
}

void administrador::on_Cambio_clicked()
{
    Cambiar_Contrasena windows(Id_Administrador, this);
    windows.setWindowTitle("Cambiar contraseña");
    windows.exec();
}

void administrador::on_Cerrar_Sesion_clicked()
{
    close();
}

void administrador::on_Cambio_2_clicked()
{
    recuperar_contrasena  recuperar(this);
    recuperar.setWindowTitle("Recuperar Contraseña");
    recuperar.exec();

}
