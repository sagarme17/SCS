#ifndef REESTABLECER_CONTRASENIA_H
#define REESTABLECER_CONTRASENIA_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class reestablecer_Contrasenia;
}

class reestablecer_Contrasenia : public QDialog
{
    Q_OBJECT

public:
    explicit reestablecer_Contrasenia(QWidget *parent = nullptr);
    ~reestablecer_Contrasenia();

private slots:
    void on_Reestablecer_clicked();
    
    void on_Regresar_2_clicked();

private:
    Ui::reestablecer_Contrasenia *ui;
    QSqlDatabase mdb;
};



#endif // REESTABLECER_CONTRASENIA_H
