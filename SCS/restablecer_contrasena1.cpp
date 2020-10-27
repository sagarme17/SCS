#include "restablecer_contrasena1.h"
#include "ui_restablecer_contrasena1.h"

restablecer_contrasena1::restablecer_contrasena1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restablecer_contrasena1)
{
    ui->setupUi(this);
}

restablecer_contrasena1::~restablecer_contrasena1()
{
    delete ui;
}

void restablecer_contrasena1::on_pushButton_2_clicked()
{
    close();
}
