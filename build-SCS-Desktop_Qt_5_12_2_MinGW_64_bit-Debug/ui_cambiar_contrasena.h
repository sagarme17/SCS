/********************************************************************************
** Form generated from reading UI file 'cambiar_contrasena.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIAR_CONTRASENA_H
#define UI_CAMBIAR_CONTRASENA_H

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

class Ui_Cambiar_Contrasena
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit;
    QLabel *Alumno;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QPushButton *Regresar;
    QPushButton *Actualizar;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Contrasea;
    QLineEdit *Confirmar_Contrasea;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Cambiar_Contrasena)
    {
        if (Cambiar_Contrasena->objectName().isEmpty())
            Cambiar_Contrasena->setObjectName(QString::fromUtf8("Cambiar_Contrasena"));
        Cambiar_Contrasena->resize(741, 570);
        Cambiar_Contrasena->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(Cambiar_Contrasena);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 291, 571));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 271, 281));
        label->setPixmap(QPixmap(QString::fromUtf8("Images/skill_102344.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 410, 111, 101));
        label_2->setPixmap(QPixmap(QString::fromUtf8("Images/1486503785-authorisation-lock-padlock-password-privacy-safe-security_81267.png")));
        label_2->setScaledContents(true);
        groupBox_2 = new QGroupBox(Cambiar_Contrasena);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 0, 451, 571));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, -10, 451, 151));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        Alumno = new QLabel(groupBox_2);
        Alumno->setObjectName(QString::fromUtf8("Alumno"));
        Alumno->setGeometry(QRect(170, 40, 121, 41));
        Alumno->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 10, 171, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 100, 411, 451));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        Regresar = new QPushButton(groupBox_4);
        Regresar->setObjectName(QString::fromUtf8("Regresar"));
        Regresar->setGeometry(QRect(30, 340, 131, 41));
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
        Actualizar->setGeometry(QRect(260, 340, 131, 41));
        Actualizar->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6; \n"
"font: 14pt 75 \"Times New Roman\";\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;"));
        Actualizar->setAutoDefault(true);
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 20, 111, 101));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"border:none;\n"
"hover!pressed:border: 5px solid blue;"));
        label_6->setPixmap(QPixmap(QString::fromUtf8("Images/internet_lock_locked_padlock_password_secure_security_icon_127100.png")));
        label_6->setScaledContents(true);
        verticalLayoutWidget = new QWidget(groupBox_4);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 140, 251, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Contrasea = new QLineEdit(verticalLayoutWidget);
        Contrasea->setObjectName(QString::fromUtf8("Contrasea"));
        Contrasea->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"color: rgb(0,0,0);\n"
"background: transparent;\n"
""));
        Contrasea->setEchoMode(QLineEdit::Password);
        Contrasea->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Contrasea);

        Confirmar_Contrasea = new QLineEdit(verticalLayoutWidget);
        Confirmar_Contrasea->setObjectName(QString::fromUtf8("Confirmar_Contrasea"));
        Confirmar_Contrasea->setStyleSheet(QString::fromUtf8("font: 14pt \"Times New Roman\";\n"
"color: rgb(0,0,0);\n"
"background: transparent;\n"
""));
        Confirmar_Contrasea->setEchoMode(QLineEdit::Password);
        Confirmar_Contrasea->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Confirmar_Contrasea);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 71, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 0, 71, 71));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("Images/alumno.png")));
        label_4->setScaledContents(true);

        retranslateUi(Cambiar_Contrasena);

        QMetaObject::connectSlotsByName(Cambiar_Contrasena);
    } // setupUi

    void retranslateUi(QDialog *Cambiar_Contrasena)
    {
        Cambiar_Contrasena->setWindowTitle(QApplication::translate("Cambiar_Contrasena", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        label_2->setText(QString());
        groupBox_2->setTitle(QString());
        Alumno->setText(QApplication::translate("Cambiar_Contrasena", "Alumno", nullptr));
        label_5->setText(QApplication::translate("Cambiar_Contrasena", "Bienvenido ", nullptr));
        groupBox_4->setTitle(QString());
        Regresar->setText(QApplication::translate("Cambiar_Contrasena", "Regresar", nullptr));
        Actualizar->setText(QApplication::translate("Cambiar_Contrasena", "Actualizar", nullptr));
        label_6->setText(QString());
        Contrasea->setText(QString());
        Contrasea->setPlaceholderText(QApplication::translate("Cambiar_Contrasena", "Contrase\303\261a (min. 6 caracteres)", nullptr));
        Confirmar_Contrasea->setText(QString());
        Confirmar_Contrasea->setPlaceholderText(QApplication::translate("Cambiar_Contrasena", "Confirmar contrase\303\261a", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cambiar_Contrasena: public Ui_Cambiar_Contrasena {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIAR_CONTRASENA_H
