#include "mostrar_avance.h"
#include "ui_mostrar_avance.h"

mostrar_avance::mostrar_avance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mostrar_avance)
{
    ui->setupUi(this);
}

mostrar_avance::~mostrar_avance()
{
    delete ui;
}

void mostrar_avance::on_Regresar_clicked()
{
    close();
}
