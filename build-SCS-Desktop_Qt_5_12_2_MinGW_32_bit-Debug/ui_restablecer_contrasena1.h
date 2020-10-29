/********************************************************************************
** Form generated from reading UI file 'restablecer_contrasena1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTABLECER_CONTRASENA1_H
#define UI_RESTABLECER_CONTRASENA1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_restablecer_contrasena1
{
public:
    QGroupBox *groupBox_2;
    QTableWidget *Tabla1;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *restablecer_contrasena1)
    {
        if (restablecer_contrasena1->objectName().isEmpty())
            restablecer_contrasena1->setObjectName(QString::fromUtf8("restablecer_contrasena1"));
        restablecer_contrasena1->resize(809, 573);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1490820813-6_82408.png"), QSize(), QIcon::Normal, QIcon::Off);
        restablecer_contrasena1->setWindowIcon(icon);
        groupBox_2 = new QGroupBox(restablecer_contrasena1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 811, 591));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Tabla1 = new QTableWidget(groupBox_2);
        if (Tabla1->columnCount() < 4)
            Tabla1->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Tabla1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Tabla1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Tabla1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Tabla1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Tabla1->setObjectName(QString::fromUtf8("Tabla1"));
        Tabla1->setGeometry(QRect(160, 150, 501, 291));
        Tabla1->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);\n"
"background-color: #1DE9B6;  "));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(132, 40, 561, 51));
        label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(595, 491, 121, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6; \n"
"font: 14pt 75 \"Times New Roman\";\n"
"\n"
"border: 2px ;\n"
"    border-radius: 9px;"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(115, 492, 131, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"\n"
"border: 2px ;\n"
"    border-radius: 9px;"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(18, -6, 771, 131));
        label_4->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(28, 24, 91, 81));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/door_internet_key_lock_password_safe_security_icon_127075.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(692, 21, 91, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/internet_lock_locked_padlock_password_secure_security_icon_127078.png")));
        label_3->setScaledContents(true);
        label_4->raise();
        Tabla1->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(restablecer_contrasena1);

        QMetaObject::connectSlotsByName(restablecer_contrasena1);
    } // setupUi

    void retranslateUi(QDialog *restablecer_contrasena1)
    {
        restablecer_contrasena1->setWindowTitle(QApplication::translate("restablecer_contrasena1", "Dialog", nullptr));
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = Tabla1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("restablecer_contrasena1", "Matricula", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Tabla1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("restablecer_contrasena1", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Tabla1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("restablecer_contrasena1", "Apellido materno", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Tabla1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("restablecer_contrasena1", "Apellido paterno", nullptr));
        label->setText(QApplication::translate("restablecer_contrasena1", "RECUPERAR CONTRASE\303\221A", nullptr));
        pushButton->setText(QApplication::translate("restablecer_contrasena1", "Aceptar", nullptr));
        pushButton_2->setText(QApplication::translate("restablecer_contrasena1", "Regresar", nullptr));
        label_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class restablecer_contrasena1: public Ui_restablecer_contrasena1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTABLECER_CONTRASENA1_H
