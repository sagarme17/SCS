#include "alumno.h"
#include "cambiar_contrasena.h"
#include "ui_alumno.h"
#include "foto.h"
#include "materias_por_cursar.h"
#include "ui_materias_por_cursar.h"
#include "materias_aprobadas.h"
#include "ui_materias_aprobadas.h"
#include "visualizar_materias.h"
#include "ui_visualizar_materias.h"
#include "mostrar_avance.h"
#include "marcar_materias_cursando.h"
#include <QMessageBox>
#include <QTimerEvent>
#include <QDate>


alumno::alumno(QString Matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumno)
{
    ui->setupUi(this);
    this->Matricula=Matricula;
    this->mdb=QSqlDatabase::database("Connection");
    primera();
    Verificarbotones();
}

alumno::~alumno()
{
    delete ui;
}
void alumno::Verificarbotones(){
    QDate fechaac;
    int dia=fechaac.currentDate().dayOfWeek();

       if(dia==1)/*Lunes*/
       {
           ui->Cambio_al_2->setVisible(false);/*porcursar*/
           ui->Marcar->setVisible(false);
           ui->Marcar_Materias->setVisible(false);
           ui->Cambio_al_5->setVisible(true);/*-------------cursando*/
           ui->Marcar_3->setVisible(true);
           ui->Marcar_Materias_3->setVisible(true);
           ui->Cambio_al_4->setVisible(false);/*aprobadas*/
           ui->Marcar_2->setVisible(false);
           ui->Marcar_Materias_2->setVisible(false);

       }
       else if(dia==4)/*Jueves*/
       {

           ui->Cambio_al_2->setVisible(true);/*-------------porcursar*/
           ui->Marcar->setVisible(true);
           ui->Marcar_Materias->setVisible(true);
           ui->Cambio_al_5->setVisible(false);/*cursando*/
           ui->Marcar_3->setVisible(false);
           ui->Marcar_Materias_3->setVisible(false);
           ui->Cambio_al_4->setVisible(false);/*aprobadas*/
           ui->Marcar_2->setVisible(false);
           ui->Marcar_Materias_2->setVisible(false);

       }else if(dia==6)/*Sábado*/
       {
           ui->Cambio_al_2->setVisible(false);/*porcursar*/
           ui->Marcar->setVisible(false);
           ui->Marcar_Materias->setVisible(false);
           ui->Cambio_al_5->setVisible(false);/*cursando*/
           ui->Marcar_3->setVisible(false);
           ui->Marcar_Materias_3->setVisible(false);
           ui->Cambio_al_4->setVisible(true);/*--------------aprobadas*/
           ui->Marcar_2->setVisible(true);
           ui->Marcar_Materias_2->setVisible(true);
       }return;

}

void alumno::on_Cambio_al_clicked()
{
    Cambiar_Contrasena windows(Matricula, this);
    windows.setWindowTitle("Cambiar contraseña");
    windows.exec();
}

void alumno::on_Cerrar_Sesion_clicked()
{
    close();
}


void alumno::on_Cambiar_Foto_clicked()
{
    Foto camb_foto(Matricula, this);
    camb_foto.setWindowTitle("Actualizar Perfil");
    camb_foto.exec();
}

void alumno::on_Cambio_al_2_clicked()
{
    Verificarbotones();
    if(mdb.open()){
        QSqlQuery porcur(mdb);
        porcur.prepare("select * from porcursar where matricula='"+Matricula+"'");
        porcur.exec();
        if(porcur.next()){
            QMessageBox::warning(this,"Solicitud enviada","Ya has llenado la solicitud de materias por cursar.\nGracias.","Aceptar");
        }
        else{
            materias_por_cursar PorCursar(Matricula,this);
            PorCursar.setWindowTitle("Materias por cursar");
            PorCursar.exec();
        }
    }

}


void alumno::primera()
{
    if(mdb.open())
    {
        QSqlQuery amd(mdb);
        QString bla;
        amd.prepare("Select Contraseña from usuario where id_usuario='"+Matricula+"'");
        amd.exec();
        amd.next();
        bla=amd.value(0).toString();
        if(bla==Matricula)
        {
         Cambiar_Contrasena windows(Matricula, this);
         windows.setWindowTitle("Cambiar contraseña primera vez");
         QMessageBox::information(this,"Actualizar contraseña","Se requiere que actualize su contraseña para continuar.\nGracias.","Aceptar");
         windows.exec();
        }
    }
}

void alumno::on_Cambio_al_3_clicked()
{
    mostrar_avance mostrar(Matricula,this);
    mostrar.setWindowTitle("Mostrar Avance");
    mostrar.exec();
}

void alumno::on_Cambio_al_4_clicked()
{
    Verificarbotones();
    materias_aprobadas aprobada(Matricula,this);
    aprobada.setWindowTitle("Materias aprobadas");
    aprobada.exec();
}

void alumno::on_Cambio_al_6_clicked()
{
    visualizar_materias materias(Matricula,this);
    materias.setWindowTitle("Proyección de materias");
    materias.exec();
}

void alumno::on_Cambio_al_5_clicked()
{
     Verificarbotones();
     if(mdb.open())
     {
         QSqlQuery cursando(mdb);
         cursando.prepare("select * from cursando where matricula='"+Matricula+"'");
         cursando.exec();
         if(cursando.next()){
             QMessageBox::warning(this,"Marcación hecha","Ya has hecho la marcación de tus materias cursando.\nGracias.","Aceptar");
          }else
        {
        marcar_Materias_Cursando cursando(Matricula,this);
        cursando.setWindowTitle("Materias cursando");
        cursando.exec();
       }

   }
}
