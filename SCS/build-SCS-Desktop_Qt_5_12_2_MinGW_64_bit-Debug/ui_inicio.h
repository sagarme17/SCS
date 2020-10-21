/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_4;
    QLineEdit *Contrasena;
    QLineEdit *Matricula;
    QPushButton *Inicio_sesion;
    QPushButton *Olvidaste_Contrasena;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QGroupBox *groupBox;
    QLabel *label_2;

    void setupUi(QDialog *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(720, 559);
        inicio->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(inicio);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 0, 371, 561));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 130, 291, 411));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        Contrasena = new QLineEdit(groupBox_4);
        Contrasena->setObjectName(QString::fromUtf8("Contrasena"));
        Contrasena->setGeometry(QRect(10, 90, 271, 41));
        Contrasena->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"color: rgb(0,0,0);\n"
"background: transparent;\n"
"border: 2px solid gray;\n"
"    border-radius: 6px;\n"
"    margin-top: 0.5em;"));
        Contrasena->setEchoMode(QLineEdit::Password);
        Matricula = new QLineEdit(groupBox_4);
        Matricula->setObjectName(QString::fromUtf8("Matricula"));
        Matricula->setGeometry(QRect(10, 40, 271, 41));
        Matricula->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"color: rgb(0,0,0);\n"
"background: transparent;\n"
"border: 2px solid gray;\n"
"    border-radius: 6px;\n"
"    margin-top: 0.5em;"));
        Inicio_sesion = new QPushButton(groupBox_4);
        Inicio_sesion->setObjectName(QString::fromUtf8("Inicio_sesion"));
        Inicio_sesion->setGeometry(QRect(80, 230, 131, 41));
        Inicio_sesion->setMouseTracking(true);
        Inicio_sesion->setFocusPolicy(Qt::ClickFocus);
        Inicio_sesion->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;\n"
""));
        Inicio_sesion->setFlat(false);
        Olvidaste_Contrasena = new QPushButton(groupBox_4);
        Olvidaste_Contrasena->setObjectName(QString::fromUtf8("Olvidaste_Contrasena"));
        Olvidaste_Contrasena->setGeometry(QRect(60, 270, 171, 31));
        Olvidaste_Contrasena->setFocusPolicy(Qt::ClickFocus);
        Olvidaste_Contrasena->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: grey;\n"
"border:none;\n"
"font: 10pt 75 \"Times New Roman\";"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 160, 51, 61));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/login-square-arrow-button-outline_icon-icons.com_73220.png")));
        label_4->setScaledContents(true);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 90, 201, 41));
        label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 10, 81, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_3->setScaledContents(true);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, -10, 361, 151));
        label_5->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label_5->raise();
        groupBox_4->raise();
        label->raise();
        label_3->raise();
        groupBox = new QGroupBox(inicio);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 351, 581));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, 50, 371, 441));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/1490820813-6_82408.png")));
        label_2->setScaledContents(true);

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QDialog *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Dialog", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_4->setTitle(QString());
        Contrasena->setText(QString());
        Contrasena->setPlaceholderText(QApplication::translate("inicio", "Contrase\303\261a", nullptr));
        Matricula->setText(QString());
        Matricula->setPlaceholderText(QApplication::translate("inicio", "Matricula", nullptr));
        Inicio_sesion->setText(QApplication::translate("inicio", "Iniciar sesi\303\263n", nullptr));
        Olvidaste_Contrasena->setText(QApplication::translate("inicio", "\302\277Olvidaste tu contrase\303\261a?", nullptr));
        label_4->setText(QString());
        label->setText(QApplication::translate("inicio", "School System", nullptr));
        label_3->setText(QString());
        label_5->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
