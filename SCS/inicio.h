#ifndef INICIO_H
#define INICIO_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>


namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();


private slots:


    void on_Inicio_sesion_clicked();

    void on_pushButton_clicked();

private:
    Ui::inicio *ui;
    QSqlDatabase mdb;
};

#endif // INICIO_H
