#ifndef CAMBIAR_CONTRASENA_H
#define CAMBIAR_CONTRASENA_H

#include <QDialog>

namespace Ui {
class Cambiar_Contrasena;
}

class Cambiar_Contrasena : public QDialog
{
    Q_OBJECT

public:
    explicit Cambiar_Contrasena(QWidget *parent = nullptr);
    ~Cambiar_Contrasena();

private:
    Ui::Cambiar_Contrasena *ui;
};

#endif // CAMBIAR_CONTRASENA_H
