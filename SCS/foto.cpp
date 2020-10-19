#include "foto.h"
#include "ui_foto.h"

Foto::Foto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Foto)
{
    ui->setupUi(this);
}

Foto::~Foto()
{
    delete ui;
}
