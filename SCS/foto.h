#ifndef FOTO_H
#define FOTO_H

#include <QDialog>

namespace Ui {
class Foto;
}

class Foto : public QDialog
{
    Q_OBJECT

public:
    explicit Foto(QWidget *parent = nullptr);
    ~Foto();

private:
    Ui::Foto *ui;
};

#endif // FOTO_H
