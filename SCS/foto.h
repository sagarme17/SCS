#ifndef FOTO_H
#define FOTO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDialog>

namespace Ui {
class Foto;
}

class Foto : public QDialog
{
    Q_OBJECT

public:
    explicit Foto(QString idusuario,QWidget *parent = nullptr);
    ~Foto();

private slots:
    void on_Actualizar_clicked();

private:
    Ui::Foto *ui;
    QString Matricula;
    QSqlDatabase mdb;

};

#endif // FOTO_H
