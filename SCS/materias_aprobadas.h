#ifndef MATERIAS_APROBADAS_H
#define MATERIAS_APROBADAS_H

#include <QDialog>

namespace Ui {
class materias_aprobadas;
}

class materias_aprobadas : public QDialog
{
    Q_OBJECT

public:
    explicit materias_aprobadas(QString, QWidget *parent = nullptr);
    ~materias_aprobadas();

private slots:
    void on_Regresar_clicked();

private:
    Ui::materias_aprobadas *ui;
};

#endif // MATERIAS_APROBADAS_H
