/********************************************************************************
** Form generated from reading UI file 'administrador.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRADOR_H
#define UI_ADMINISTRADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_administrador
{
public:
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *Cerrar_Sesion;
    QLabel *label_4;
    QGroupBox *groupBox;
    QLabel *label_15;

    void setupUi(QDialog *administrador)
    {
        if (administrador->objectName().isEmpty())
            administrador->setObjectName(QString::fromUtf8("administrador"));
        administrador->resize(740, 560);
        administrador->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(administrador);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(310, 0, 431, 561));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, -10, 431, 151));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 171, 41));
        label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 81, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 40, 221, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 90, 391, 451));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 181, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 100, 181, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 220, 181, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 220, 181, 41));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 340, 251, 41));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 260, 91, 91));
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/Images/internet_lock_locked_padlock_password_secure_security_icon_127100.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 140, 91, 91));
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Images/check-form_116472.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(250, 20, 91, 91));
        label_12->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Images/iconfinder-document03-1622833_121957.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(250, 140, 91, 91));
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/Images/door_internet_key_lock_password_safe_security_icon_127075.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(60, 20, 91, 91));
        label_14->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Images/test_102328.png")));
        label_14->setScaledContents(true);
        Cerrar_Sesion = new QPushButton(groupBox_4);
        Cerrar_Sesion->setObjectName(QString::fromUtf8("Cerrar_Sesion"));
        Cerrar_Sesion->setGeometry(QRect(250, 400, 131, 41));
        Cerrar_Sesion->setMouseTracking(true);
        Cerrar_Sesion->setFocusPolicy(Qt::ClickFocus);
        Cerrar_Sesion->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;\n"
""));
        Cerrar_Sesion->setFlat(false);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 0, 81, 81));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/laptop-1_102326.png")));
        label_4->setScaledContents(true);
        groupBox = new QGroupBox(administrador);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 311, 571));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(-10, 110, 331, 321));
        label_15->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Images/system_102355.png")));
        label_15->setScaledContents(true);

        retranslateUi(administrador);

        QMetaObject::connectSlotsByName(administrador);
    } // setupUi

    void retranslateUi(QDialog *administrador)
    {
        administrador->setWindowTitle(QApplication::translate("administrador", "Dialog", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("administrador", "Bienvenido ", nullptr));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("administrador", "Administrador", nullptr));
        groupBox_4->setTitle(QString());
        label_5->setText(QApplication::translate("administrador", "Est. materias por cursar", nullptr));
        label_6->setText(QApplication::translate("administrador", "Est. materias cursando", nullptr));
        label_7->setText(QApplication::translate("administrador", "Est. materias cursadas", nullptr));
        label_8->setText(QApplication::translate("administrador", "Cambiar contrase\303\261a", nullptr));
        label_9->setText(QApplication::translate("administrador", "Restablecer contrase\303\261a de alumno", nullptr));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        Cerrar_Sesion->setText(QApplication::translate("administrador", "Cerrar sesi\303\263n", nullptr));
        label_4->setText(QString());
        groupBox->setTitle(QString());
        label_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class administrador: public Ui_administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
