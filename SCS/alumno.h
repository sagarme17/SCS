#ifndef ALUMNO_H
#define ALUMNO_H

#include <QDialog>

namespace Ui {
class alumno;
}

class alumno : public QDialog
{
    Q_OBJECT

public:
    explicit alumno(QWidget *parent = nullptr);
    ~alumno();

private:
    Ui::alumno *ui;
};

#endif // ALUMNO_H
