#include "cambiar_contrasena.h"
#include "ui_cambiar_contrasena.h"

Cambiar_Contrasena::Cambiar_Contrasena(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cambiar_Contrasena)
{
    ui->setupUi(this);
}

Cambiar_Contrasena::~Cambiar_Contrasena()
{
    delete ui;
}
