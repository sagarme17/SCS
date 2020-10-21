/********************************************************************************
** Form generated from reading UI file 'foto.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOTO_H
#define UI_FOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Foto
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *Alumno;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_4;
    QPushButton *Regresar;
    QPushButton *Actualizar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Nombre;
    QLabel *Matricula;
    QLabel *Carrera;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Foto)
    {
        if (Foto->objectName().isEmpty())
            Foto->setObjectName(QString::fromUtf8("Foto"));
        Foto->resize(740, 581);
        Foto->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(Foto);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 301, 581));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 160, 281, 271));
        label->setPixmap(QPixmap(QString::fromUtf8("Images/skill_102344.png")));
        label->setScaledContents(true);
        groupBox_2 = new QGroupBox(Foto);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 0, 441, 581));
        Alumno = new QLabel(groupBox_2);
        Alumno->setObjectName(QString::fromUtf8("Alumno"));
        Alumno->setGeometry(QRect(180, 20, 91, 41));
        Alumno->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, -10, 441, 151));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 90, 401, 461));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        Regresar = new QPushButton(groupBox_4);
        Regresar->setObjectName(QString::fromUtf8("Regresar"));
        Regresar->setGeometry(QRect(30, 380, 131, 41));
        Regresar->setMouseTracking(true);
        Regresar->setFocusPolicy(Qt::ClickFocus);
        Regresar->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;\n"
""));
        Regresar->setFlat(false);
        Actualizar = new QPushButton(groupBox_4);
        Actualizar->setObjectName(QString::fromUtf8("Actualizar"));
        Actualizar->setGeometry(QRect(240, 380, 131, 41));
        Actualizar->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6; \n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;"));
        Actualizar->setAutoDefault(true);
        verticalLayoutWidget = new QWidget(groupBox_4);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 190, 381, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Nombre = new QLabel(verticalLayoutWidget);
        Nombre->setObjectName(QString::fromUtf8("Nombre"));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(16);
        Nombre->setFont(font);
        Nombre->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(Nombre);

        Matricula = new QLabel(verticalLayoutWidget);
        Matricula->setObjectName(QString::fromUtf8("Matricula"));
        Matricula->setFont(font);
        Matricula->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(Matricula);

        Carrera = new QLabel(verticalLayoutWidget);
        Carrera->setObjectName(QString::fromUtf8("Carrera"));
        Carrera->setFont(font);
        Carrera->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(Carrera);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 60, 121, 111));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/iconfinder-7-avatar-2754582_120519.png")));
        label_4->setScaledContents(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 71, 71));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 0, 61, 71));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/laptop-1_102326.png")));
        label_3->setScaledContents(true);
        lineEdit->raise();
        Alumno->raise();
        groupBox_4->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Foto);

        QMetaObject::connectSlotsByName(Foto);
    } // setupUi

    void retranslateUi(QDialog *Foto)
    {
        Foto->setWindowTitle(QCoreApplication::translate("Foto", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        groupBox_2->setTitle(QString());
        Alumno->setText(QCoreApplication::translate("Foto", "Perfil", nullptr));
        groupBox_4->setTitle(QString());
        Regresar->setText(QCoreApplication::translate("Foto", "Regresar", nullptr));
        Actualizar->setText(QCoreApplication::translate("Foto", "Actualizar", nullptr));
        Nombre->setText(QString());
        Matricula->setText(QString());
        Carrera->setText(QString());
        label_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Foto: public Ui_Foto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOTO_H
