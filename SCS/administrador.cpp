#include "administrador.h"
#include "ui_administrador.h"



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
