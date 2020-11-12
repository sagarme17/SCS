#include "marcar_materias_cursando.h"
#include "ui_marcar_materias_cursando.h"

marcar_Materias_Cursando::marcar_Materias_Cursando(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marcar_Materias_Cursando)
{
    ui->setupUi(this);
}

marcar_Materias_Cursando::~marcar_Materias_Cursando()
{
    delete ui;
}
