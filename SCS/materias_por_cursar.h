#ifndef MATERIAS_POR_CURSAR_H
#define MATERIAS_POR_CURSAR_H


#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>
namespace Ui {
class materias_por_cursar;
}

class materias_por_cursar : public QDialog
{
    Q_OBJECT

public:
    explicit materias_por_cursar(QString matricula,QWidget *parent = nullptr);
    ~materias_por_cursar();

    void LlenarTabla();

    void MateriasNuevas();
    //void MateriasCursando();




private slots:
    void on_pushButton_2_clicked();
    void BoxChecked();

    void on_pushButton_clicked();

private:
    Ui::materias_por_cursar *ui;
    QString matricula;
      QSqlDatabase mdb;
      int Materias;
};

#endif // MATERIAS_POR_CURSAR_H
