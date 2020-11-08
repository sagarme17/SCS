#include "visualizar_materias.h"
#include "ui_visualizar_materias.h"

visualizar_materias::visualizar_materias(QString,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visualizar_materias)
{
    ui->setupUi(this);
}

visualizar_materias::~visualizar_materias()
{
    delete ui;
}

void visualizar_materias::on_Regresar_clicked()
{
    close();
}
