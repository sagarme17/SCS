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

    ~alumno();

private:
    Ui::alumno *ui;
    QString Matricula;
    QSqlDatabase mdb;


};

#endif // ALUMNO_H
