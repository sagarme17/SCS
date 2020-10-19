#ifndef INICIO_SESION_H
#define INICIO_SESION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class inicio_sesion; }
QT_END_NAMESPACE

class inicio_sesion : public QMainWindow
{
    Q_OBJECT

public:
    inicio_sesion(QWidget *parent = nullptr);
    ~inicio_sesion();

private:
    Ui::inicio_sesion *ui;
};
#endif // INICIO_SESION_H
