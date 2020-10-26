#include "recuperar_contrasena.h"
#include "ui_recuperar_contrasena.h"
#include "cambiar_contrasena.h"
#include "ui_cambiar_contrasena.h"

recuperar_contrasena::recuperar_contrasena(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recuperar_contrasena)
{
    ui->setupUi(this);
}

recuperar_contrasena::~recuperar_contrasena()
{
    delete ui;
}

void recuperar_contrasena::on_pushButton_clicked()
{



}

void recuperar_contrasena::on_pushButton_2_clicked()
{
    close();
}
