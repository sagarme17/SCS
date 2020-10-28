#include "reestablecer_contrasenia.h"
#include "ui_reestablecer_contrasenia.h"
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
    query1.prepare("insert into solicitud(matricula) value('"+matri+"')");
    query1.exec();
    query1.next();
    qDebug()<<matri;
}

void reestablecer_Contrasenia::on_Regresar_2_clicked()
{
    close();
}
