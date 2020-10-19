#include "alumno.h"
#include "ui_alumno.h"

alumno::alumno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumno)
{
    ui->setupUi(this);
}

alumno::~alumno()
{
    delete ui;
}
