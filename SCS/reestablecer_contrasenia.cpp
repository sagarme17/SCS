#include "reestablecer_contrasenia.h"
#include "ui_reestablecer_contrasenia.h"
#include "restablecer_contrasena1.h"
#include "ui_restablecer_contrasena1.h"

reestablecer_Contrasenia::reestablecer_Contrasenia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reestablecer_Contrasenia)
{
    ui->setupUi(this);
}

reestablecer_Contrasenia::~reestablecer_Contrasenia()
{
    delete ui;
}

void reestablecer_Contrasenia::on_Reestablecer_clicked()
{
   restablecer_contrasena1 Contra(this);
    Contra.setWindowTitle("Recuperar Contraseña");
    Contra.exec();
}

void reestablecer_Contrasenia::on_Regresar_2_clicked()
{
    close();
}
