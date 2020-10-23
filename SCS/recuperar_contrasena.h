#ifndef RECUPERAR_CONTRASENA_H
#define RECUPERAR_CONTRASENA_H

#include <QDialog>

namespace Ui {
class recuperar_contrasena;
}

class recuperar_contrasena : public QDialog
{
    Q_OBJECT

public:
    explicit recuperar_contrasena(QWidget *parent = nullptr);
    ~recuperar_contrasena();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::recuperar_contrasena *ui;
    QString id_usuario;
};

#endif // RECUPERAR_CONTRASENA_H
