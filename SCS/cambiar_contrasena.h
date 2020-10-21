#ifndef CAMBIAR_CONTRASENA_H
#define CAMBIAR_CONTRASENA_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class Cambiar_Contrasena;
}

class Cambiar_Contrasena : public QDialog
{
    Q_OBJECT

public:
    explicit Cambiar_Contrasena(QString, QWidget *parent = nullptr);
    ~Cambiar_Contrasena();

private slots:
    void on_Actualizar_clicked();
    void on_Regresar_clicked();

private:
    Ui::Cambiar_Contrasena *ui;
    QSqlDatabase mdb;
    QString id_usuario;
};

#endif // CAMBIAR_CONTRASENA_H
