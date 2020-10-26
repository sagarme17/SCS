#ifndef REESTABLECER_CONTRASENIA_H
#define REESTABLECER_CONTRASENIA_H

#include <QDialog>

namespace Ui {
class reestablecer_Contrasenia;
}

class reestablecer_Contrasenia : public QDialog
{
    Q_OBJECT

public:
    explicit reestablecer_Contrasenia(QWidget *parent = nullptr);
    ~reestablecer_Contrasenia();

private:
    Ui::reestablecer_Contrasenia *ui;
};

#endif // REESTABLECER_CONTRASENIA_H
