/********************************************************************************
** Form generated from reading UI file 'materias_por_cursar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIAS_POR_CURSAR_H
#define UI_MATERIAS_POR_CURSAR_H

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

class Ui_materias_por_cursar
{
public:
    QGroupBox *groupBox_2;
    QTableWidget *Tabla1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *materias_por_cursar)
    {
        if (materias_por_cursar->objectName().isEmpty())
            materias_por_cursar->setObjectName(QString::fromUtf8("materias_por_cursar"));
        materias_por_cursar->resize(1088, 668);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1490820813-6_82408.png"), QSize(), QIcon::Normal, QIcon::Off);
        materias_por_cursar->setWindowIcon(icon);
        groupBox_2 = new QGroupBox(materias_por_cursar);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1101, 691));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Tabla1 = new QTableWidget(groupBox_2);
        if (Tabla1->columnCount() < 6)
            Tabla1->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        Tabla1->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        Tabla1->setObjectName(QString::fromUtf8("Tabla1"));
        Tabla1->setGeometry(QRect(183, 180, 751, 351));
        Tabla1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #1DE9B6;  "));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 40, 511, 81));
        label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"Berlin Sans FB Demi\";\n"
"background:transparent;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(61, 24, 111, 101));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/check-form_116472.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(922, 22, 111, 101));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/checklist_102320.png")));
        label_3->setScaledContents(true);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(800, 570, 131, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6; \n"
"font: 14pt 75 \"Times New Roman\";\n"
"\n"
"border: 2px ;\n"
"    border-radius: 9px;"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 570, 131, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #FF4081;\n"
"font: 14pt 75 \"Times New Roman\";\n"
"border: 2px ;\n"
"    border-radius: 9px;"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(29, 2, 1031, 161));
        label_4->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label_4->raise();
        Tabla1->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(materias_por_cursar);

        QMetaObject::connectSlotsByName(materias_por_cursar);
    } // setupUi

    void retranslateUi(QDialog *materias_por_cursar)
    {
        materias_por_cursar->setWindowTitle(QApplication::translate("materias_por_cursar", "Dialog", nullptr));
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = Tabla1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("materias_por_cursar", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Tabla1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("materias_por_cursar", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Tabla1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("materias_por_cursar", "Horas_PT", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Tabla1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("materias_por_cursar", "Creditos", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Tabla1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("materias_por_cursar", "Estado", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Tabla1->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("materias_por_cursar", "Marcar", nullptr));
        label->setText(QApplication::translate("materias_por_cursar", "MATERIAS POR CURSAR", nullptr));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("materias_por_cursar", "Aceptar", nullptr));
        pushButton_2->setText(QApplication::translate("materias_por_cursar", "Regresar", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class materias_por_cursar: public Ui_materias_por_cursar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIAS_POR_CURSAR_H
