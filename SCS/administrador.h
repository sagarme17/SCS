#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class administrador;
}

class administrador : public QDialog
{
    Q_OBJECT

public:
    explicit administrador(QString Id_Administrador,QWidget *parent = nullptr);
    ~administrador();

private slots:
    void on_Cambio_clicked();

    void on_Cerrar_Sesion_clicked();

    void on_est_Materias_cursando_clicked();

    void on_Restablecer_contras_clicked();

    void on_est_materias_aprobadas_clicked();

    void on_est_materias_porcursar_clicked();

private:
    Ui::administrador *ui;
    QString Id_Administrador;
    QString PDFESTADISTICA;
    QSqlDatabase mdb;
};

#endif // ADMINISTRADOR_H
