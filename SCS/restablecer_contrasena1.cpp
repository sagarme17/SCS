#include "restablecer_contrasena1.h"
#include "ui_restablecer_contrasena1.h"
#include "reestablecer_contrasenia.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

restablecer_contrasena1::restablecer_contrasena1(QString Id_Usuario,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restablecer_contrasena1)
{
    ui->setupUi(this);
    this->mdb=QSqlDatabase::database("Connection");
    LlenarTabla();
}

restablecer_contrasena1::~restablecer_contrasena1()
{
    delete ui;
}

void restablecer_contrasena1::on_pushButton_2_clicked()
{
    close();
}

void restablecer_contrasena1::LlenarTabla()
{
    if(mdb.open()){
        ui->Tabla1->setRowCount(0);
        QSqlQuery llenar(mdb);
        llenar.prepare("select a.Matricula,c.Nombre,c.ApPaterno, c.ApMaterno from solicitud as a inner join usuario as c on a.Matricula=c.Id_Usuario;");
        llenar.exec();
        while (llenar.next()) {
            QTableWidgetItem *uno=new QTableWidgetItem(llenar.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(llenar.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(llenar.value(2).toString());
            QTableWidgetItem *cuatro=new QTableWidgetItem(llenar.value(3).toString());
            ui->Tabla1->setRowCount(ui->Tabla1->rowCount()+1);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,0,uno);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,1,dos);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,2,tres);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,3,cuatro);
        }
    }
}

void restablecer_contrasena1::on_Restablecer_clicked()
{
    if(mdb.open()){
    QSqlQuery matri(mdb),query1(mdb),query2(mdb);
    QString mat;
    matri.prepare("select Matricula from solicitud");
    matri.exec();
    mat=matri.value(0).toString();
    for(int i=0;i<ui->Tabla1->rowCount();i++)
    {
        query1.prepare("Update usuario set Contraseña=Id_Usuario where Id_Usuario='"+ui->Tabla1->item(i,0)->text()+"'");
        query1.exec();
        query1.next();
        qDebug()<<"Entro";
    }
    query2.prepare("Delete from solicitud");
    query2.exec();
    query2.next();
    ui->Tabla1->setRowCount(0);
    QMessageBox::information(this,"Actualizado","Las contraseñas volvieron a su valor predeterminado.","Aceptar");
    }
}
