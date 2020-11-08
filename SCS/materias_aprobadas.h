#ifndef MATERIAS_APROBADAS_H
#define MATERIAS_APROBADAS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class materias_aprobadas;
}

class materias_aprobadas : public QDialog
{
    Q_OBJECT

public:
    explicit materias_aprobadas(QString matricula, QWidget *parent = nullptr);
    ~materias_aprobadas();
    void LlenarTableAprobada();

private slots:
    void on_Regresar_clicked();

    void on_Actualizar_clicked();

private:
    Ui::materias_aprobadas *ui;
    QString matricula;
    QSqlDatabase mdb;
    int Materias;
};

#endif // MATERIAS_APROBADAS_H
