#ifndef MATERIAS_PORCURSAR_H
#define MATERIAS_PORCURSAR_H

#include <QDialog>

namespace Ui {
class materias_porCursar;
}

class materias_porCursar : public QDialog
{
    Q_OBJECT

public:
    explicit materias_porCursar(QWidget *parent = nullptr);
    ~materias_porCursar();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::materias_porCursar *ui;
};

#endif // MATERIAS_PORCURSAR_H
