#include "inicio.h"
#include "ui_inicio.h"
#include "administrador.h"

#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QtSql/QSqlDatabase>

inicio::inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicio)
{
    this->mdb=QSqlDatabase::database("Connection");
    ui->setupUi(this);

}

inicio::~inicio()
{
    delete ui;
}



void inicio::on_Inicio_sesion_clicked()
{

   //close();

    QPalette falta;
    falta.setColor(ui->Matricula->foregroundRole(),Qt::black);
    ui->Matricula->setPalette(falta);
    falta.setColor(ui->Contrasena->foregroundRole(),Qt::black);
    ui->Contrasena->setPalette(falta);

   QString id,contrasenia,aux;
   id=ui->Matricula->text();
   contrasenia=ui->Contrasena->text();
   if(id==""||contrasenia==""){
       QPalette falta;
       if(id==""){
           falta.setColor(ui->Matricula->foregroundRole(),Qt::red);
           ui->Matricula->setPalette(falta);
       }
       if(contrasenia==""){
           falta.setColor(ui->Contrasena->foregroundRole(),Qt::red);
           ui->Contrasena->setPalette(falta);
       }
   }
   else{
    /*QString id,contrasenia,aux;
    id=ui->Matricula->text();
    contrasenia=ui->Contrasena->text();*/

       if(mdb.open()){
           qDebug() << "Conexión exitosa";
           QSqlQuery query1(mdb);
           query1.prepare("select Id_Administrador from administrador where Id_Administrador='"+id+"'");
           query1.exec();


           if(query1.next()){
              query1.clear();
              query1.prepare("select Contraseña from usuario inner join administrador on Id_Administrador=Id_Usuario where Id_Usuario='"+id+"'");
              query1.exec();
              query1.next();
              if(contrasenia==query1.value(0).toString()){
                  administrador admin(id);
                  admin.setWindowTitle("Administrador");
                  admin.setModal(false);
                  this->setVisible(false);//this
                  admin.exec();
                  this->setVisible(true); //this
                  ui->Matricula->clear();
                  ui->Contrasena->clear();
              }
              else{
                  QMessageBox::critical(this,"Error","Contraseña incorrecta","Aceptar");
                  ui->Contrasena->clear();
              }
   }
     }
   }
}

void inicio::on_pushButton_clicked()
{
    close();
}
