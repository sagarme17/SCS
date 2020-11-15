#include "foto.h"
#include "ui_foto.h"


#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QFileDialog>




Foto::Foto(QString idusuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Foto)
{
    ui->setupUi(this);
    this->Matricula=idusuario;
    this->mdb=QSqlDatabase::database("Connection");
    Act();
    Datos();


}

void Foto::Act()
{
    //this->mdb=QSqlDatabase::database("Connection");
    QSqlQuery query1(mdb);
   // QSqlQuery query(mdb);
    QByteArray foto;

    query1.prepare("SELECT img FROM perfil where matricula= '"+Matricula+"'");
    query1.exec();
    query1.last();
    foto = query1.value(0).toByteArray();

    if(!foto.isNull())
     {
    QPixmap pix(141,141);

    pix.loadFromData(query1.value(0).toByteArray());
    ui->aver->setPixmap(pix);
   // ui->aver->repaint();
    qDebug() << "Encontro la imagen";
}
}

Foto::~Foto()
{
    delete ui;

}

void Foto::Datos()
{
    QSqlQuery query1(mdb),query2(mdb);
    QString nombre,matricula;
    query1.prepare("Select Nombre,ApPaterno,ApMaterno from usuario where Id_usuario='"+Matricula+"'");
    query1.exec();
    if(query1.next())
    {
        nombre=query1.value(0).toString();
        ui->Nombre->setText(nombre);
    }
    query2.prepare("Select Id_usuario from usuario where Id_usuario='"+Matricula+"'");
    query2.exec();
    if(query2.next())
    {
        matricula=query2.value(0).toString();
        ui->Matricula->setText(matricula);
    }
    ui->Carrera->setText("Ing. en Ciencias de la Computación");
}


void Foto::on_Actualizar_clicked()
{



    QSqlQuery query(mdb);
        QString archivo_foto;
        archivo_foto = QFileDialog::getOpenFileName(this,tr("Abrir Archivo"),tr("/home"),tr("Imagenes(*.png *.xpm *.*)"));
        QFile file(archivo_foto);
        file.open(QIODevice::ReadOnly);
        QByteArray bytes = file.readAll();

        query.prepare("update Perfil set img = :img where Matricula='"+Matricula+"'");
        query.bindValue(":img", QVariant(bytes));
        query.exec();
        qDebug()<<Matricula;

        qDebug() << "ACtualizo imagen de alumno sin imagen";

        QMessageBox::critical(this,"Actualizar","Cierra esta Pestaña para actualizar los cambios");

        Act();

}

void Foto::on_Regresar_clicked()
{
    close();
}
