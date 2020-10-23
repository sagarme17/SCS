#include "materias_porcursar.h"
#include "ui_materias_porcursar.h"

materias_porCursar::materias_porCursar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materias_porCursar)
{
    ui->setupUi(this);
}

materias_porCursar::~materias_porCursar()
{
    delete ui;
}

void materias_porCursar::on_pushButton_2_clicked()
{
    close();
}
