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
    this->mdb=QSqlDatabase::database("Connection");
    QSqlQuery query1(mdb);


    query1.prepare("select Direccion from foto where matricula = '"+idusuario+"'");
    query1.exec();
    QString nombre_imagen;
    while (query1.next()) {
       nombre_imagen = query1.value(0).toString();
       qDebug() << nombre_imagen;

    }

    QPixmap myPixmap;
   myPixmap.load("foto/'"+nombre_imagen+"'");
   ui->label_FOTO->setPixmap(myPixmap);

    qDebug() << "NO PUES QUIEN SABE";

    ui->setupUi(this);



}

Foto::~Foto()
{
    delete ui;

}

void Foto::on_Actualizar_clicked()
{
    QString archivo_foto;
    archivo_foto = QFileDialog::getOpenFileName(this,tr("Abrir Archivo"),tr("/home"),tr("Imagenes(*.png *.xpm *.*)"));
    QFile file(archivo_foto);

}
