#ifndef MARCAR_MATERIAS_CURSANDO_H
#define MARCAR_MATERIAS_CURSANDO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class marcar_Materias_Cursando;
}

class marcar_Materias_Cursando : public QDialog
{
    Q_OBJECT

public:
    explicit marcar_Materias_Cursando(QString matricula, QWidget *parent = nullptr);
    ~marcar_Materias_Cursando();
    void LlenarTablaCursando();

private slots:
    void on_Regresar_clicked();
    void BoxChecked();



    void on_Aceptar_clicked();

private:
    Ui::marcar_Materias_Cursando *ui;
    QString matricula;
    QSqlDatabase mdb;
    int contadormat;
};

#endif // MARCAR_MATERIAS_CURSANDO_H
