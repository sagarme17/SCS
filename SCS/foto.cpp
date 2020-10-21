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
    CargarFoto();
}

Foto::~Foto()
{
    delete ui;

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

        qDebug() << "Actualizo imagen de alumno sin imagen";

        CargarFoto();

       QMessageBox::information(this,"Actualizar","Foto Actualizada","Aceptar");



}

void Foto::CargarFoto()
{
    QSqlQuery query1(mdb);
    QSqlQuery query(mdb);
    QByteArray foto;


    query.prepare("SELECT img FROM perfil where matricula= '"+Matricula+"'");
    query.exec();
    query.last();
    foto = query.value(0).toByteArray();

    if(!foto.isNull())
     {
    QPixmap pix(141,141);

    pix.loadFromData(query.value(0).toByteArray());
    ui->aver->setPixmap(pix);
    qDebug() << "Encontro la imagen";

    }
}

void Foto::on_Regresar_clicked()
{
    close();
}
