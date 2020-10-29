#include "inicio.h"
#include "ui_inicio.h"
#include "administrador.h"
#include "alumno.h"
#include "reestablecer_contrasenia.h"
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

       QSqlQuery query1(mdb);
       QString idusuario;
       if(id.length()>0 && contrasenia.length()>0)
       {
       query1.prepare("SELECT Id_usuario FROM usuario WHERE Id_usuario='"+id+"' AND contraseña='"+contrasenia+"'");
       query1.exec();
       query1.next();
       idusuario = query1.value(0).toString();
       qDebug()<<idusuario;
       }
       if(!idusuario.isNull())
        {
   QSqlQuery queryadmin(mdb);
   QSqlQuery queryalumno(mdb);
   QString adminRes;
   QString alumnoRes;
   QString res3;

   queryadmin.prepare("SELECT Id_Administrador, IF('"+idusuario+"'=Id_Administrador ,'TRUE','FALSE') AS ESTADO FROM administrador WHERE Id_Administrador='"+idusuario+"'");
   queryadmin.exec();
   if(queryadmin.next()){
  adminRes = queryadmin.value(1).toString();

       }
   qDebug() <<adminRes;
   if(adminRes=="TRUE")
   {
   administrador admin(idusuario,this);
   admin.setWindowTitle("administrador");
   admin.exec();
   ui->Contrasena->clear();
   ui->Matricula->clear();
   }
   queryalumno.prepare("SELECT matricula, IF('"+idusuario+"'=matricula ,'TRUE','FALSE') AS ESTADO FROM alumno WHERE matricula='"+idusuario+"'");
   queryalumno.exec();
   while(queryalumno.next())
   {
     alumnoRes=queryalumno.value(1).toString();
   }
   if(alumnoRes=="TRUE")
   {
       alumno alumn(idusuario,this);
       alumn.setWindowTitle("alumno");
       alumn.exec();
       ui->Contrasena->clear();
       ui->Matricula->clear();
   }
}else{
           QMessageBox::critical(this,"Error","Contraseña incorrecta","Aceptar");
           ui->Contrasena->clear();
       }

}
  }
void inicio::on_pushButton_clicked()
{
    close();
}

void inicio::on_Olvidaste_Contrasena_clicked()
{
    reestablecer_Contrasenia windows(this);
    close();
}
