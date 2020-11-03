#ifndef MOSTRAR_AVANCE_H
#define MOSTRAR_AVANCE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class mostrar_avance;
}

class mostrar_avance : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar_avance(QString, QWidget *parent = nullptr);
    ~mostrar_avance();
    void cursando();
    void aprobada();

private slots:
    void on_Regresar_clicked();

private:
    Ui::mostrar_avance *ui;
    QSqlDatabase mdb;
    QString Matricula;
};

#endif // MOSTRAR_AVANCE_H
