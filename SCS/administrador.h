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

private:
    Ui::administrador *ui;
    QString Id_Administrador;
    QSqlDatabase mdb;
};

#endif // ADMINISTRADOR_H
