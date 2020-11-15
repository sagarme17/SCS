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

#include <QPrinter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>


#include <QTimerEvent>
#include <QDate>


alumno::alumno(QString Matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumno)
{
    ui->setupUi(this);
    this->Matricula=Matricula;
    this->mdb=QSqlDatabase::database("Connection");
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

void alumno::on_Cambio_al_7_clicked()
{
    {
     //QMessageBox::information(this,"Cardex Avance","Selecciona la ruta en la que deseas guardar tu kardex.\nGracias.");
       int total=0,Porcentaje;
       QSqlQuery    estadistico(mdb),NOMBRE(mdb), cursando(mdb),foto(mdb);//,estadistico2(mdb);
       QString Codigo, Nonbre,Avance,nombre,ApellidoM,ApellidoP,Mat;
       QString CodigoC, NombreC,CodigoQ;
       QString HorasPeriodoC, CreditosC, HorasPeridoA, CreditosA;


       foto.prepare("select img from perfil where matricula='"+Matricula+"'");
       foto.exec();
       foto.next();

           QByteArray guardarfoto=foto.value(0).toByteArray();
           QPixmap pixmap;
            pixmap.scaled(QSize(50,50),Qt::KeepAspectRatio);
           QBuffer buffer(&guardarfoto);
               pixmap.save(&buffer, "PNG");
               QString url = QString("<img src=\"data:image/png;base64,") + guardarfoto.toBase64() + "\"/ >";
   // FotoA+= url+ "<br>";



        /*verfoto.prepare("SELECT img FROM perfil where matricula= '"+Matricula+"'");
        verfoto.exec();
        if(verfoto.next())
        {
            QByteArray array=verfoto.value(0).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(array);

            //QString name = QString("%1.png").arg(verfoto.value(0));
            QString name = QFileDialog::getSaveFileName(this,tr("Guardar"),"D:/FOTOOO/Alumno.jpg",tr("JPG-FILES (*.jpg)"));
            // QString fileName2 = QDir().filePath(name);
        qDebug()<<"NO SEEEEEEEEEEEEEEEEE"+name;
                //QPixmap pixmap;
             pixmap.loadFromData(verfoto.value(0).toByteArray());
             pixmap.save(name);

        }*/




       NOMBRE.prepare("Select Nombre, ApPaterno, ApMaterno, Id_Usuario from usuario where Id_Usuario='"+Matricula+"'");
       NOMBRE.exec();
       if(NOMBRE.next())
       {
           nombre=NOMBRE.value(0).toString();
           ApellidoP=NOMBRE.value(1).toString();
           ApellidoM=NOMBRE.value(2).toString();
           Mat=NOMBRE.value(3).toString();
       }

       Datos += "<br>" "Alumno/a: "+ nombre+ " "+ApellidoP+" "+ApellidoM+" "+"<br>" "Matricula:" +Mat+"<br>" "Programa Educativo:Ing. en Ciencias de la computación";

       estadistico.prepare("select count(*) from aprobado  where Matricula='"+Matricula+"'");
       estadistico.exec();
        if(estadistico.next()){

            total= estadistico.value(0).toInt();
        }
        //qDebug()<<"TOTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL"+total;

        estadistico.prepare("select Código from aprobado where Matricula='"+Matricula+"'");
        estadistico.exec();
        while(estadistico.next())
        {
            Codigo = estadistico.value(0).toString();
            //Matricula1 = estadistico.value(1).toInt();
            QSqlQuery Nombre(mdb);
            Nombre.prepare("select Nombre,Horas_PeriodoPT,Creditos from Materia where Código = '"+Codigo+"'");
            Nombre.exec();
            Nombre.next();
            Nonbre = Nombre.value(0).toString();
            HorasPeridoA=Nombre.value(1).toString();
            CreditosA=Nombre.value(2).toString();

           // Kardex += "<br>"+ Codigo+ " "+ Nonbre+ "................................................" +HorasPeridoA+ "     " +CreditosA+ "<br>";
            Kardex += "<br>"+ Codigo+ " "+ Nonbre+ "<br>";
         }

        Porcentaje = (total * 100)/50;
        Avance = QString::number(Porcentaje);
        //qDebug() << "TU PORCENTAJE DE AVANCE ES:"+Porcentaje;
         Avances+= "<br>" "Tu avance es del: "   +Avance+ "  " " ""%"" "+"<br>"+"<br>"+"<br>";

         cursando.prepare("select Código from cursando  where Matricula='"+Matricula+"'");
         cursando.exec();
         while(cursando.next())
         {
             CodigoQ=cursando.value(0).toString();

             QSqlQuery cursando2(mdb);
             cursando2.prepare("Select Nombre, Horas_PeriodoPT,Creditos from Materia where Código='"+CodigoQ+"'");
             cursando2.exec();
             cursando2.next();
             NombreC=cursando2.value(0).toString();
             HorasPeriodoC=cursando2.value(1).toString();
             CreditosC=cursando2.value(2).toString();
             //CodigoC=cursando.value(0).toString();
             //NombreC=cursando.value(1).toString();
             //horasC=cursando.value(2).toString();
             //creditosC=cursando.value(3).toString();
             // CursandoM+= "<br>"+CodigoQ+" "+ NombreC+ "................................................" +HorasPeriodoC+ " " +CreditosC+ "<br>";
             CursandoM+= "<br>"+CodigoQ+" "+ NombreC+ "<br>";
         }

          //qDebug()<<CursandoM;





        //qDebug()<< PDFESTADISTICA;
       QString html =
               "<img src='D:/Descargas/logo_FCC.png' width='200' height='100'>"
               "<H1 align=center>KARDEX DE AVANCE</H1>"
               "<br>"

            "</div>"
            "<div align=right>"
               "Heroico Estado de Puebla "+QDate::currentDate().toString("dddd MMMM d yyyy")+
            "</div>"
            "<br>"
               "<div align=center>"
               "<H2>"
               "BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA"
               "<br>""<br>"
               "FACULTAD DE CIENCIAS DE LA COMPUTACIÓN"
               "</H2>"
               "</div>"
               "<p>"
               //"<img src='+pixmap+'>"
               //"FOTO"
               //"<?php mysql_connect('localhost','root');  mysql_select_db('scs');  $re=mysql_query('Select img from perfil where matricula=201617587');    $f=mysql_fetch_array($re);     header('Content-type: image/x-png');  echo $f['imagen'];  ?>"
                //"<img src=\"data:image/png;base64,"  + guardarfoto.toBase64()  + "\"width='100' height='100'/  >"
               //+FotoA+
               "</p>"
           "<p align=justify>"
              "<h3>"
               +Datos+
              // "<img src=\"data:image/png;base64,"  + guardarfoto.toBase64()  + "\"width='100' height='100',lign='right' , hspace='1' , border='5'                 /  >"

                //"<div aling=right>""<img src=\"data:image/png;base64,"  + guardarfoto.toBase64()  + "\"width='100' height='100'/  >" "</div"
               "</h3>"
               "</p>"

               "<FONT FACE=times new roman font size=4>"

               "<img src=\"data:image/png;base64,"  + guardarfoto.toBase64()  + "\" width='100' height='100' align='right'/  >"
               "<h3>"
               "Materias aprobadas"
               "</h3>"
                 +Kardex+
               "<h3>"
               "Materias cursando"
               "</h3>"
               +CursandoM+
               "<h3 align=center> "
               +Avances+
               "</h3>"
               "</FONT>"
               "</div>"
                "</FONT>"
               "</p>";
       QTextDocument document;
       document.setHtml(html);

       QPrinter printer(QPrinter::PrinterResolution);

       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar Archivo"),
                                     "C:/Users/HP/Desktop/Kardex.pdf",
                                     tr("PDF-Files (*.pdf)"));
         printer.setOutputFileName(fileName);




       printer.setPageMargins(QMarginsF(15, 15, 15, 15));

       document.print(&printer);

       QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
       QMessageBox::information(this,"Cardex Avance","Tu kardex ha sido guardado.\nGracias.");
    }

}
