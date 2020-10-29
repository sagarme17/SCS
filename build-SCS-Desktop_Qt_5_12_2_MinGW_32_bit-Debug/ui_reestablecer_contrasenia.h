/********************************************************************************
** Form generated from reading UI file 'reestablecer_contrasenia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REESTABLECER_CONTRASENIA_H
#define UI_REESTABLECER_CONTRASENIA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_reestablecer_Contrasenia
{
public:
    QLabel *label_7;
    QLabel *label_3;
    QLabel *Alumno;
    QLabel *label_5;
    QLabel *label_4;
    QGroupBox *groupBox;
    QLineEdit *Matricula;
    QPushButton *Regresar_2;
    QPushButton *Reestablecer;

    void setupUi(QDialog *reestablecer_Contrasenia)
    {
        if (reestablecer_Contrasenia->objectName().isEmpty())
            reestablecer_Contrasenia->setObjectName(QString::fromUtf8("reestablecer_Contrasenia"));
        reestablecer_Contrasenia->resize(387, 352);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1490820813-6_82408.png"), QSize(), QIcon::Normal, QIcon::Off);
        reestablecer_Contrasenia->setWindowIcon(icon);
        label_7 = new QLabel(reestablecer_Contrasenia);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(-10, -10, 431, 101));
        label_7->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label_3 = new QLabel(reestablecer_Contrasenia);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 71, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_3->setScaledContents(true);
        Alumno = new QLabel(reestablecer_Contrasenia);
        Alumno->setObjectName(QString::fromUtf8("Alumno"));
        Alumno->setGeometry(QRect(110, 40, 171, 41));
        Alumno->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label_5 = new QLabel(reestablecer_Contrasenia);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 10, 191, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label_4 = new QLabel(reestablecer_Contrasenia);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 10, 71, 71));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/laptop-1_102326.png")));
        label_4->setScaledContents(true);
        groupBox = new QGroupBox(reestablecer_Contrasenia);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, 90, 401, 261));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        Matricula = new QLineEdit(groupBox);
        Matricula->setObjectName(QString::fromUtf8("Matricula"));
        Matricula->setGeometry(QRect(70, 50, 249, 38));
        Matricula->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"color: rgb(0,0,0);\n"
"background: transparent;\n"
""));
        Matricula->setEchoMode(QLineEdit::Normal);
        Matricula->setAlignment(Qt::AlignCenter);
        Regresar_2 = new QPushButton(groupBox);
        Regresar_2->setObjectName(QString::fromUtf8("Regresar_2"));
        Regresar_2->setGeometry(QRect(20, 170, 131, 41));
        Regresar_2->setMouseTracking(true);
        Regresar_2->setFocusPolicy(Qt::ClickFocus);
        Regresar_2->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;\n"
""));
        Regresar_2->setFlat(false);
        Reestablecer = new QPushButton(groupBox);
        Reestablecer->setObjectName(QString::fromUtf8("Reestablecer"));
        Reestablecer->setGeometry(QRect(250, 170, 131, 41));
        Reestablecer->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6; \n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;"));
        Reestablecer->setAutoDefault(true);

        retranslateUi(reestablecer_Contrasenia);

        QMetaObject::connectSlotsByName(reestablecer_Contrasenia);
    } // setupUi

    void retranslateUi(QDialog *reestablecer_Contrasenia)
    {
        reestablecer_Contrasenia->setWindowTitle(QApplication::translate("reestablecer_Contrasenia", "Dialog", nullptr));
        label_7->setText(QString());
        label_3->setText(QString());
        Alumno->setText(QApplication::translate("reestablecer_Contrasenia", "Contrase\303\261a", nullptr));
        label_5->setText(QApplication::translate("reestablecer_Contrasenia", "Reestablecer", nullptr));
        label_4->setText(QString());
        groupBox->setTitle(QString());
        Matricula->setText(QString());
        Matricula->setPlaceholderText(QApplication::translate("reestablecer_Contrasenia", "Matricula", nullptr));
        Regresar_2->setText(QApplication::translate("reestablecer_Contrasenia", "Regresar", nullptr));
        Reestablecer->setText(QApplication::translate("reestablecer_Contrasenia", "Actualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reestablecer_Contrasenia: public Ui_reestablecer_Contrasenia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REESTABLECER_CONTRASENIA_H
