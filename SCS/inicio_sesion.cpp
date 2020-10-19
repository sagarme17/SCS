#include "inicio_sesion.h"


inicio_sesion::inicio_sesion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inicio_sesion)
{
    ui->setupUi(this);
}

inicio_sesion::~inicio_sesion()
{
    delete ui;
}

