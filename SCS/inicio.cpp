#include "inicio.h"
#include "ui_inicio.h"
#include "administrador.h"
#include "alumno.h"

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
           QSqlQuery query1(mdb),query2(mdb);
           query1.prepare("select Id_Administrador from administrador where Id_Administrador='"+id+"'");
           query1.exec();
           query2.prepare("select Matricula from alumno where Matricula='"+id+"'");
           query2.exec();

         //QString alumnoRes;
         //QString res3;
         //QString idusuario;

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
   }else if (query2.next())
           {
               query2.clear();
               query2.prepare("select Contraseña from usuario inner join alumno on Matricula=Id_Usuario where Id_Usuario='"+id+"'");
               query2.exec();
               query2.next();
               if(contrasenia==query2.value(0).toString())
               {
                   alumno alum(id);
                   alum.setWindowTitle("Alumno");
                   alum.setModal(false);
                   this->setVisible(false);
                   alum.exec();
                   this->setVisible(true);
                   ui->Matricula->clear();
                   ui->Contrasena->clear();
               }else
               {

                   QMessageBox::critical(this,"Error","Contraseña incorrecta","Aceptar");
                   ui->Contrasena->clear();
                   ui->Matricula->clear();

               }

       }else
           {
               QMessageBox::critical(this,"Error","Matricula incorrecta","Aceptar");
               ui->Contrasena->clear();
               ui->Matricula->clear();
           }

           } //bd
     } //labels
 } //funcion
void inicio::on_pushButton_clicked()
{
    close();
}
