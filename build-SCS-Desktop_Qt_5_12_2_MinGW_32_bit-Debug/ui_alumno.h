/********************************************************************************
** Form generated from reading UI file 'alumno.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALUMNO_H
#define UI_ALUMNO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_alumno
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *Foto;
    QPushButton *Cambiar_Foto;
    QLabel *Ver_Perfil;
    QGroupBox *groupBox_2;
    QLabel *Alumno;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_4;
    QLabel *Visualizar_Avance;
    QLabel *Marcar_Materias;
    QLabel *Cambiar_Contrasena;
    QPushButton *Cerrar_Sesion;
    QLabel *Avance;
    QLabel *Marcar;
    QLabel *Contrasena;
    QPushButton *Cambio_al;
    QPushButton *Cambio_al_2;
    QLabel *label_2;

    void setupUi(QDialog *alumno)
    {
        if (alumno->objectName().isEmpty())
            alumno->setObjectName(QString::fromUtf8("alumno"));
        alumno->resize(728, 571);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/1490820813-6_82408.png"), QSize(), QIcon::Normal, QIcon::Off);
        alumno->setWindowIcon(icon);
        alumno->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(alumno);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 281, 571));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 210, 281, 291));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/skill_102344.png")));
        label->setScaledContents(true);
        Foto = new QLabel(groupBox);
        Foto->setObjectName(QString::fromUtf8("Foto"));
        Foto->setGeometry(QRect(80, 40, 121, 121));
        Foto->setPixmap(QPixmap(QString::fromUtf8(":/Images/foldertealphoto_92861.png")));
        Foto->setScaledContents(true);
        Cambiar_Foto = new QPushButton(groupBox);
        Cambiar_Foto->setObjectName(QString::fromUtf8("Cambiar_Foto"));
        Cambiar_Foto->setEnabled(true);
        Cambiar_Foto->setGeometry(QRect(80, 40, 111, 111));
        Cambiar_Foto->setStyleSheet(QString::fromUtf8("       background:transparent;\n"
"       border:none;\n"
"       outline:none;\n"
""));
        Ver_Perfil = new QLabel(groupBox);
        Ver_Perfil->setObjectName(QString::fromUtf8("Ver_Perfil"));
        Ver_Perfil->setGeometry(QRect(50, 140, 181, 41));
        Ver_Perfil->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        Ver_Perfil->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(alumno);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 0, 451, 571));
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
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 81, 71));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/pencils_120694.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 0, 81, 71));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/laptop-1_102326.png")));
        label_4->setScaledContents(true);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 90, 391, 451));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"  border: 2px solid gray;\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;"));
        Visualizar_Avance = new QLabel(groupBox_4);
        Visualizar_Avance->setObjectName(QString::fromUtf8("Visualizar_Avance"));
        Visualizar_Avance->setGeometry(QRect(10, 150, 181, 41));
        Visualizar_Avance->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        Visualizar_Avance->setAlignment(Qt::AlignCenter);
        Marcar_Materias = new QLabel(groupBox_4);
        Marcar_Materias->setObjectName(QString::fromUtf8("Marcar_Materias"));
        Marcar_Materias->setGeometry(QRect(200, 150, 181, 41));
        Marcar_Materias->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        Marcar_Materias->setAlignment(Qt::AlignCenter);
        Cambiar_Contrasena = new QLabel(groupBox_4);
        Cambiar_Contrasena->setObjectName(QString::fromUtf8("Cambiar_Contrasena"));
        Cambiar_Contrasena->setGeometry(QRect(110, 300, 181, 41));
        Cambiar_Contrasena->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Berlin Sans FB Demi\";"));
        Cambiar_Contrasena->setAlignment(Qt::AlignCenter);
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
        Avance = new QLabel(groupBox_4);
        Avance->setObjectName(QString::fromUtf8("Avance"));
        Avance->setGeometry(QRect(50, 60, 101, 101));
        Avance->setPixmap(QPixmap(QString::fromUtf8(":/Images/checklist_25365.png")));
        Avance->setScaledContents(true);
        Marcar = new QLabel(groupBox_4);
        Marcar->setObjectName(QString::fromUtf8("Marcar"));
        Marcar->setGeometry(QRect(250, 60, 101, 101));
        Marcar->setPixmap(QPixmap(QString::fromUtf8(":/Images/checklist_102320.png")));
        Marcar->setScaledContents(true);
        Contrasena = new QLabel(groupBox_4);
        Contrasena->setObjectName(QString::fromUtf8("Contrasena"));
        Contrasena->setGeometry(QRect(150, 210, 101, 101));
        Contrasena->setPixmap(QPixmap(QString::fromUtf8(":/Images/door_internet_key_lock_password_safe_security_icon_127075.png")));
        Contrasena->setScaledContents(true);
        Cambio_al = new QPushButton(groupBox_4);
        Cambio_al->setObjectName(QString::fromUtf8("Cambio_al"));
        Cambio_al->setGeometry(QRect(154, 222, 91, 81));
        Cambio_al->setStyleSheet(QString::fromUtf8("\n"
"       background:transparent;\n"
"       border:none;\n"
"       outline:none;\n"
""));
        Cambio_al_2 = new QPushButton(groupBox_4);
        Cambio_al_2->setObjectName(QString::fromUtf8("Cambio_al_2"));
        Cambio_al_2->setGeometry(QRect(260, 70, 91, 81));
        Cambio_al_2->setStyleSheet(QString::fromUtf8("\n"
"       background:transparent;\n"
"       border:none;\n"
"       outline:none;\n"
""));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, -10, 431, 131));
        label_2->setStyleSheet(QString::fromUtf8("background-color: #1DE9B6;  \n"
"border: 1px solid #1DE9B6;\n"
"    border-radius: 20px;\n"
"    margin-top: 0.5em;"));
        label_2->raise();
        Alumno->raise();
        label_5->raise();
        label_3->raise();
        label_4->raise();
        groupBox_4->raise();

        retranslateUi(alumno);

        QMetaObject::connectSlotsByName(alumno);
    } // setupUi

    void retranslateUi(QDialog *alumno)
    {
        alumno->setWindowTitle(QApplication::translate("alumno", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        Foto->setText(QString());
        Cambiar_Foto->setText(QString());
        Ver_Perfil->setText(QApplication::translate("alumno", "Ver Perfil", nullptr));
        groupBox_2->setTitle(QString());
        Alumno->setText(QApplication::translate("alumno", "Alumno", nullptr));
        label_5->setText(QApplication::translate("alumno", "Bienvenido ", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        groupBox_4->setTitle(QString());
        Visualizar_Avance->setText(QApplication::translate("alumno", "Visualizar Avance", nullptr));
        Marcar_Materias->setText(QApplication::translate("alumno", "Marcar Materias", nullptr));
        Cambiar_Contrasena->setText(QApplication::translate("alumno", "Cambiar contrase\303\261a", nullptr));
        Cerrar_Sesion->setText(QApplication::translate("alumno", "Cerrar sesi\303\263n", nullptr));
        Avance->setText(QString());
        Marcar->setText(QString());
        Contrasena->setText(QString());
        Cambio_al->setText(QString());
        Cambio_al_2->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class alumno: public Ui_alumno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALUMNO_H
