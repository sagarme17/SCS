#include "cambiar_contrasena.h"
#include "ui_cambiar_contrasena.h"
#include <QMessageBox>

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
    if(mdb.open())
    {
        QString contrasea=ui->Contrasea->text();
        QString confirma=ui->Confirmar_Contrasea->text();
        QSqlQuery contra(mdb);
        if(ui->Contrasea->text().size()<6 && ui->Confirmar_Contrasea->text().size()<6)
        {
            QMessageBox::critical(this,"Error","Su contraseña es muy corta.","Aceptar");
        }
        else
        {
       if(ui->Contrasea->text()==ui->Confirmar_Contrasea->text())
       {
         if(ui->Contrasea->text()!=id_usuario && ui->Confirmar_Contrasea->text()!=id_usuario)
          {
            contra.prepare("Update usuario set Contraseña ='"+ui->Contrasea->text()+"' where Id_Usuario='"+id_usuario+"'");
            contra.exec();
            contra.next();
            QMessageBox::information(this,"Actualizado","Su contraseña ha sido actualizada.","Aceptar");
            contra.clear();
            close();
          }
          else
          {
             ui->Contrasea->clear();
             ui->Confirmar_Contrasea->clear();
             QMessageBox::critical(this,"Error","La contraseña no debe ser igual a tu matricula.","Aceptar");
          }
       }
       else{
           QMessageBox::critical(this,"Error","La contraseña no coincide.","Aceptar");
           }
       }
    }
}

void Cambiar_Contrasena::on_Regresar_clicked()
{
    close();
}
