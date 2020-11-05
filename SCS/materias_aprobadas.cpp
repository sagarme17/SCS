#include "materias_aprobadas.h"
#include "ui_materias_aprobadas.h"

materias_aprobadas::materias_aprobadas(QString, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materias_aprobadas)
{
    ui->setupUi(this);
}

materias_aprobadas::~materias_aprobadas()
{
    delete ui;
}
