#ifndef VISUALIZAR_MATERIAS_H
#define VISUALIZAR_MATERIAS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class visualizar_materias;
}

class visualizar_materias : public QDialog
{
    Q_OBJECT

public:
    explicit visualizar_materias(QString matricula,QWidget *parent = nullptr);
    ~visualizar_materias();
    void LlenarTabla();

private slots:
    void on_Regresar_clicked();

private:
    Ui::visualizar_materias *ui;
    QString matricula;
    QSqlDatabase mdb;
};

#endif // VISUALIZAR_MATERIAS_H
