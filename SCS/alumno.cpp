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


void alumno::Aprobadas()
{

}
void alumno::on_Cambio_al_7_clicked()
{
    {
     //QMessageBox::information(this,"Cardex Avance","Selecciona la ruta en la que deseas guardar tu kardex.\nGracias.");
       int total=0,Porcentaje;
       QSqlQuery    estadistico(mdb),NOMBRE(mdb), cursando(mdb),foto(mdb), logo(mdb),horas(mdb),horasC(mdb),escudo(mdb),creditosA(mdb),creditosC(mdb);
       QString Codigo, Nonbre,Avance,nombre,ApellidoM,ApellidoP,Mat;
       QString CodigoC, NombreC,CodigoQ;
       QString HorasPeriodoC, CreditosC, HorasPeriodoA, CreditosA;


       //FOTO DEL LOGO

       logo.prepare("SELECT imgen FROM fotos where Id_foto=3");
       logo.exec();
       logo.next();
            QByteArray guardarlogo=logo.value(0).toByteArray();
            QPixmap pixmapL;
            QBuffer bufferL(&guardarlogo);
            pixmapL.save(&bufferL, "PNG");
            QString urlL = QString("<img src=\"data:image/png;base64,") + guardarlogo.toBase64() + "\"/ >";


       //FOTO BUAP

        escudo.prepare("SELECT imgen FROM fotos where Id_foto=2");
        escudo.exec();
        escudo.next();
             QByteArray guardarescudo=escudo.value(0).toByteArray();
             QPixmap pixmapE;
             QBuffer bufferE(&guardarescudo);
             pixmapL.save(&bufferE, "PNG");
             QString urlE = QString("<img src=\"data:image/png;base64,") + guardarescudo.toBase64() + "\"/ >";


       //FOTO DEL ALUMNO

       foto.prepare("select img from perfil where matricula='"+Matricula+"'");
       foto.exec();
       foto.next();
           QByteArray guardarfoto=foto.value(0).toByteArray();
           QPixmap pixmap;
           QBuffer buffer(&guardarfoto);
           pixmap.save(&buffer, "PNG");
           QString url = QString("<img src=\"data:image/png;base64,") + guardarfoto.toBase64() + "\"/ >";




       NOMBRE.prepare("Select Nombre, ApPaterno, ApMaterno, Id_Usuario from usuario where Id_Usuario='"+Matricula+"'");
       NOMBRE.exec();
       if(NOMBRE.next())
       {
           nombre=NOMBRE.value(0).toString();
           ApellidoP=NOMBRE.value(1).toString();
           ApellidoM=NOMBRE.value(2).toString();
           Mat=NOMBRE.value(3).toString();
       }

       Datos += "<br>" "Alumno/a: "+ nombre+ " "+ApellidoP+" "+ApellidoM+" "+"<br>" "Matricula:" +Mat+"<br>" "Programa Educativo:Ing. en Ciencias de la Computación";

       //ESTADISTICO
       estadistico.prepare("select count(*) from aprobado  where Matricula='"+Matricula+"'");
       estadistico.exec();
        if(estadistico.next()){
            total= estadistico.value(0).toInt();
        }

        estadistico.prepare("select Código from aprobado where Matricula='"+Matricula+"'");
        estadistico.exec();
        while(estadistico.next())
        {
            Codigo = estadistico.value(0).toString();
            QSqlQuery Nombre(mdb);
            Nombre.prepare("select Nombre, Código from materia where Código = '"+Codigo+"'");
            Nombre.exec();
            Nombre.next();
            Nonbre = Nombre.value(0).toString();
            Kardex += "<br>"+ Codigo+ " "+ Nonbre+ "<br>";
         }

        Porcentaje = (total * 100)/50;
        Avance = QString::number(Porcentaje);
        Avances+= "<br>" "Tu avance es del: "   +Avance+ "  " " ""%"" "+"<br>"+"<br>"+"<br>";
//*******************************************************************************************************************

        //MATERIAS CURSANDO
         cursando.prepare("select Código from cursando  where Matricula='"+Matricula+"'");
         cursando.exec();
         while(cursando.next())
         {
             CodigoQ=cursando.value(0).toString();

             QSqlQuery cursando2(mdb);
             cursando2.prepare("Select Nombre from materia where Código='"+CodigoQ+"'");
             cursando2.exec();
             cursando2.next();
                NombreC=cursando2.value(0).toString();

             CursandoM+= "<br>"+CodigoQ+" "+ NombreC+ "<br>";
         }

         // HORAS APROBADAS
         horas.prepare("select Código from aprobado  where Matricula='"+Matricula+"'");
         horas.exec();
         while(horas.next())
         {
             CodigoQ=horas.value(0).toString();

             QSqlQuery horas2(mdb);
             horas2.prepare("Select Horas_PeriodoPT from materia where Código='"+CodigoQ+"'");
             horas2.exec();
             horas2.next();
                  HorasPeriodoA=horas2.value(0).toString();

             Horas+= "<br>"+HorasPeriodoA+ "<br>";

         }

        //HORAS CURSANDO
         horasC.prepare("select Código from cursando  where Matricula='"+Matricula+"'");
         horasC.exec();
         while(horasC.next())
         {
             CodigoQ=horasC.value(0).toString();
             QSqlQuery horasC2(mdb);
             horasC2.prepare("Select Horas_PeriodoPT from materia where Código='"+CodigoQ+"'");
             horasC2.exec();
             horasC2.next();
                  HorasPeriodoC=horasC2.value(0).toString();

             HorasCd+= "<br>"+HorasPeriodoC+ "<br>";

         }

        //CREDITOS APROBADOS
         creditosA.prepare("select Código from aprobado  where Matricula='"+Matricula+"'");
         creditosA.exec();
         while(creditosA.next())
         {
             CodigoQ=creditosA.value(0).toString();

             QSqlQuery CreditosA1(mdb);
             CreditosA1.prepare("Select Creditos from materia where Código='"+CodigoQ+"'");
             CreditosA1.exec();
             CreditosA1.next();
             CreditosA=CreditosA1.value(0).toString();

             CreditosAp+= "<br>"+CreditosA+ "<br>";

         }

         //CREDITOS CURSANDO
         creditosC.prepare("select Código from cursando  where Matricula='"+Matricula+"'");
         creditosC.exec();
         while(creditosC.next())
         {
             CodigoQ=creditosC.value(0).toString();

             QSqlQuery CreditosC1(mdb);
             CreditosC1.prepare("Select Creditos from materia where Código='"+CodigoQ+"'");
             CreditosC1.exec();
             CreditosC1.next();
             CreditosC=CreditosC1.value(0).toString();
             CreditosCp+= "<br>"+CreditosC+ "<br>";

         }



       QString html =
               "<img src=\"data:image/png;base64," + guardarlogo.toBase64() + "\" width='200' height='100' / >"
               "<img src=\"data:image/png;base64," + guardarescudo.toBase64() + "\" width='120' height='120' align='right' / >"
               "<br>"
               "<H1 align=center>KARDEX DE AVANCE</H1>"
               "<br>"


            "<div align=right>"
               "Heroico Estado de Puebla a "+QDate::currentDate().toString( "dddd  d , MMMM  , yyyy")+
            "</div>"
            "<br>"


               "<div align=center>"
               "<H2>"
               "BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA"
               "<br>""<br>"
               "FACULTAD DE CIENCIAS DE LA COMPUTACIÓN"
               "</H2>"
               "</div>"

               "<table>"
               "<tbody>"
                "<td>"
           "<p align=justify>"
              "<h3>"
               +Datos+
               "</h3>"
               "</p>"
               "</td>"
               "<td>"     "<img src=\"data:image/png;base64,"  + guardarfoto.toBase64()  + "\" width='100' height='100' align='right'/  >" "</td>"


               "</tbody>"
               "</table>"

               "<br>"
               "<br>"


               "<FONT FACE=times new roman font size=4>"

               "<table>"

                "<tbody>"

                "<tr>"
               "<td>"
                 "<h3>" "Materias Aprobadas"  "</h3>"    +Kardex+
               "</td>"
               "<td align='center'>" "<h3>" "Horas""</h3>" +Horas+ "</td>"
               "<td align='center' >" "<h3>" "Creditos" "</h3>"  +CreditosAp+  "</td>"
               "</tr>"





            "<tr>"
               "<td >"
                   "<h3>" "Materias cursando"  "</h3>"     +CursandoM+
                "</td>"
                "<td align='center'>" "<h3>" "Horas""</h3>" +HorasCd+ "</td>"
               "<td align='center'>" "<h3>" "Creditos" "</h3>" +CreditosCp+  "</td>"

             "</tr>"








               "</tbody>"
               "</table>"

               "<FONT FACE=times new roman font size=4>"
               "<h3 align=center> "
               +Avances+
               "</h3>"
   "</FONT>"
               "</div>"

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
       QMessageBox::information(this,"Cardex Avance","Tu kardex ha sido guardado.\nGracias.","Aceptar");
    }

}
