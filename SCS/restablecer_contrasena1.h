#ifndef RESTABLECER_CONTRASENA1_H
#define RESTABLECER_CONTRASENA1_H

#include <QDialog>

namespace Ui {
class restablecer_contrasena1;
}

class restablecer_contrasena1 : public QDialog
{
    Q_OBJECT

public:
    explicit restablecer_contrasena1(QWidget *parent = nullptr);
    ~restablecer_contrasena1();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::restablecer_contrasena1 *ui;
};

#endif // RESTABLECER_CONTRASENA1_H
