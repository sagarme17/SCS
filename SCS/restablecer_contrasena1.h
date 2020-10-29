#ifndef RESTABLECER_CONTRASENA1_H
#define RESTABLECER_CONTRASENA1_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class restablecer_contrasena1;
}

class restablecer_contrasena1 : public QDialog
{
    Q_OBJECT

public:
    explicit restablecer_contrasena1(QString, QWidget *parent = nullptr);
    ~restablecer_contrasena1();
    void LlenarTabla();

private slots:
    void on_pushButton_2_clicked();

    void on_Restablecer_clicked();

private:
    Ui::restablecer_contrasena1 *ui;
    QSqlDatabase mdb;
    QString Id_Usuario;
};

#endif // RESTABLECER_CONTRASENA1_H
