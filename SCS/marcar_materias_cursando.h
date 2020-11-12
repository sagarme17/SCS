#ifndef MARCAR_MATERIAS_CURSANDO_H
#define MARCAR_MATERIAS_CURSANDO_H

#include <QDialog>

namespace Ui {
class marcar_Materias_Cursando;
}

class marcar_Materias_Cursando : public QDialog
{
    Q_OBJECT

public:
    explicit marcar_Materias_Cursando(QWidget *parent = nullptr);
    ~marcar_Materias_Cursando();

private:
    Ui::marcar_Materias_Cursando *ui;
};

#endif // MARCAR_MATERIAS_CURSANDO_H
