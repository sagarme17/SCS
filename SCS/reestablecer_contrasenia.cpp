#include "reestablecer_contrasenia.h"
#include "ui_reestablecer_contrasenia.h"

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
