#ifndef INICIO_H
#define INICIO_H

#include <QDialog>

namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

private:
    Ui::inicio *ui;
};

#endif // INICIO_H
