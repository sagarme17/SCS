#ifndef MOSTRAR_AVANCE_H
#define MOSTRAR_AVANCE_H

#include <QDialog>

namespace Ui {
class mostrar_avance;
}

class mostrar_avance : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar_avance(QWidget *parent = nullptr);
    ~mostrar_avance();

private slots:
    void on_Regresar_clicked();

private:
    Ui::mostrar_avance *ui;
};

#endif // MOSTRAR_AVANCE_H
