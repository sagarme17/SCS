#include "reestablecer_contrasenia.h"
#include "ui_reestablecer_contrasenia.h"
#include "restablecer_contrasena1.h"
#include "ui_restablecer_contrasena1.h"
#include "administrador.h"
#include "alumno.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QtSql/QSqlDatabase>

reestablecer_Contrasenia::reestablecer_Contrasenia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reestablecer_Contrasenia)

{
    this->mdb=QSqlDatabase::database("Connection");
    ui->setupUi(this);
}
reestablecer_Contrasenia::~reestablecer_Contrasenia()
{
    delete ui;
}

void reestablecer_Contrasenia::on_Reestablecer_clicked()
{
    QString matri;
    matri=ui->Matricula->text();
    QSqlQuery query1(mdb);
    query1.prepare("select * from alumno where matricula='"+matri+"'");
    query1.exec();
    if(query1.next()){
        query1.clear();
        query1.prepare("select * from solicitud where matricula='"+matri+"'");
        query1.exec();
        if(query1.next()){
           QMessageBox::information(this,"Solicitud enviada","Tu solicitud se a enviado anteriormente, espera a que el administrador la acepte.","Aceptar");
            close();
        }
        else{
            query1.clear();
            query1.prepare("insert into solicitud(matricula) value('"+matri+"')");
            query1.exec();
            query1.next();
            QMessageBox::information(this,"Solicitud enviada","Tu solicitud ha sido envida, espera a que el administrador la acepte.","Aceptar");
            close();
        }
    }
    else{
        QMessageBox::critical(this,"Error","Matricula Invalida.","Aceptar");
        ui->Matricula->clear();
    }

}

void reestablecer_Contrasenia::on_Regresar_2_clicked()
{
    close();
}
