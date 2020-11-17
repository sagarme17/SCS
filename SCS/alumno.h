#ifndef ALUMNO_H
#define ALUMNO_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class alumno;
}

class alumno : public QDialog
{
    Q_OBJECT

public:
    explicit alumno(QString Matricula, QWidget *parent = nullptr);
    void primera();

    ~alumno();
    void Verificarbotones();
    void Aprobadas();

private slots:
    void on_Cambio_al_clicked();

    void on_Cerrar_Sesion_clicked();

    void on_Cambiar_Foto_clicked();

    void on_Cambio_al_2_clicked();

    void on_Cambio_al_3_clicked();

    void on_Cambio_al_4_clicked();

    void on_Cambio_al_6_clicked();

    void on_Cambio_al_5_clicked();

    void on_Cambio_al_7_clicked();

private:
    Ui::alumno *ui;
    QString Matricula;
    QSqlDatabase mdb;
    QString Avances;
    QString CursandoM;
    QString Kardex;
    QString Datos;
    QString FotoA;
    QString Horas;
    QString HorasCd;
    QString CreditosAp;
    QString CreditosCp;



};

#endif // ALUMNO_H
