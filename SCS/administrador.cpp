#include "administrador.h"
#include "cambiar_contrasena.h"
#include "ui_administrador.h"
#include "restablecer_contrasena1.h"

#include <QPrinter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QMessageBox>


administrador::administrador(QString Id_Administrador,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador)
{
    ui->setupUi(this);
    this->Id_Administrador=Id_Administrador;
    this->mdb=QSqlDatabase::database("Connection");
    if(mdb.open()){
        QSqlQuery nombre(mdb);
        nombre.prepare("select nombre from usuario where Id_Usuario='"+Id_Administrador+"'");
        nombre.exec();
        nombre.next();
        ui->label_2->setText(nombre.value(0).toString());
}
}

administrador::~administrador()
{
    delete ui;
}

void administrador::on_Cambio_clicked()
{
    Cambiar_Contrasena windows(Id_Administrador, this);
    windows.setWindowTitle("Cambiar contraseña");
    windows.exec();
}

void administrador::on_Cerrar_Sesion_clicked()
{
    close();
}

void administrador::on_est_Materias_cursando_clicked()
{
       QMessageBox::information(this,"PDF Materias cursando","El PDF con la estadistica se guardo en tu escritorio.\nGracias.","Aceptar");
    int total2016, total2017,Matricula,Porcentaje;
    QSqlQuery estadistico(mdb);
    QString Codigo, Nonbre,MatriculaS;
    estadistico.prepare("select count(*) from cursando where Matricula Between 201600000 and 201700000");
    estadistico.exec();
    if(estadistico.next())
    {
        total2016 = estadistico.value(0).toInt();
    }
    estadistico.prepare("select count(*) from cursando where Matricula Between 201700000 and 201800000");
    estadistico.exec();
    if(estadistico.next())
    {
        total2017 = estadistico.value(0).toInt();
    }
    estadistico.prepare("select Código, count(Matricula) from cursando where Matricula between 201600000 and 201700000 group by código;");
    estadistico.exec();
     while(estadistico.next()){
         Codigo = estadistico.value(0).toString();
         Matricula = estadistico.value(1).toInt();
         QSqlQuery Nombre(mdb);
         Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
         Nombre.exec();
         Nombre.next();
         Nonbre = Nombre.value(0).toString();

         Porcentaje = (Matricula * 100)/total2016;
         MatriculaS = QString::number(Porcentaje);
         qDebug() << Porcentaje;
 PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< PDFESTADISTICA;
     estadistico.prepare("select Código, count(Matricula) from cursando where Matricula between 201700000 and 201800000 group by código;");
     estadistico.exec();
      while(estadistico.next()){
          Codigo = estadistico.value(0).toString();
          Matricula = estadistico.value(1).toInt();
          QSqlQuery Nombre(mdb);
          Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
          Nombre.exec();
          Nombre.next();
          Nonbre = Nombre.value(0).toString();

          Porcentaje = (Matricula * 100)/total2017;
          MatriculaS = QString::number(Porcentaje);
          qDebug() << Porcentaje;
  PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
      }
      qDebug()<< PDFESTADISTICA;

    QString html =
            "<H1 align=center>ESTADISTICO MATERIAS CURSANDO </H1>"
            "<br>"
            "<img src='C:/Users/esteban/Desktop/git 7/SCS/SCS/Images/FCC.jfif' width='150' height='150'>"
         "</div>"
         "<div align=right>"
            "PUEBLA,"+QDate::currentDate().toString()+
         "</div>"
         "<br>"
         "<div align=center>"
         "<H3>"
         "BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA"
         "<br>""<br>"
         "FACULTAD DE CIENCIAS DE LA COMPUTACIÓN"
         "</H3>"
         "</div>"
        "<p align=justify>"
         "<h4>""LISTADO""</h4>"
          "<FONT FACE=times new roman>"
            +PDFESTADISTICA+
            "</FONT>"
            "</p>"
            "<br>"
            "<br>"
            "<br>";
    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:/Users/esteban/Desktop/Estadisticos.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/esteban/Desktop/Estadisticos.pdf"));
}

void administrador::on_Restablecer_contras_clicked()
{
    restablecer_contrasena1 windo(NULL,nullptr);
    windo.setWindowTitle("Restablecer contraseñas");
    windo.exec();
}

void administrador::on_est_materias_aprobadas_clicked()
{
     QMessageBox::information(this,"PDF Materias aprobadas","El PDF con la estadistica se guardo en tu escritorio.\nGracias.","Aceptar");
    int total2016, total2017,Matricula,Porcentaje;
    QSqlQuery estadistico(mdb);
    QString Codigo, Nonbre,MatriculaS;
    estadistico.prepare("select count(*) from aprobado  where Matricula Between 201600000 and 201700000");
    estadistico.exec();
    if(estadistico.next())
    {
        total2016 = estadistico.value(0).toInt();
    }
    estadistico.prepare("select count(*) from aprobado where Matricula Between 201700000 and 201800000");
    estadistico.exec();
    if(estadistico.next())
    {
        total2017 = estadistico.value(0).toInt();
    }
    estadistico.prepare("select Código, count(Matricula) from aprobado where Matricula between 201600000 and 201700000 group by código;");
    estadistico.exec();
     while(estadistico.next()){
         Codigo = estadistico.value(0).toString();
         Matricula = estadistico.value(1).toInt();
         QSqlQuery Nombre(mdb);
         Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
         Nombre.exec();
         Nombre.next();
         Nonbre = Nombre.value(0).toString();

         Porcentaje = (Matricula * 100)/total2016;
         MatriculaS = QString::number(Porcentaje);
         qDebug() << Porcentaje;
 PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< PDFESTADISTICA;
     estadistico.prepare("select Código, count(Matricula) from aprobado where Matricula between 201700000 and 201800000 group by código;");
     estadistico.exec();
      while(estadistico.next()){
          Codigo = estadistico.value(0).toString();
          Matricula = estadistico.value(1).toInt();
          QSqlQuery Nombre(mdb);
          Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
          Nombre.exec();
          Nombre.next();
          Nonbre = Nombre.value(0).toString();

          Porcentaje = (Matricula * 100)/total2017;
          MatriculaS = QString::number(Porcentaje);
          qDebug() << Porcentaje;
  PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
      }
      qDebug()<< PDFESTADISTICA;

    QString html =
            "<H1 align=center>ESTADISTICO MATERIAS APROBADAS </H1>"
            "<br>"
            "<img src='C:/Users/esteban/Desktop/git 7/SCS/SCS/Images/FCC.jfif' width='150' height='150'>"
         "</div>"
         "<div align=right>"
            "PUEBLA,"+QDate::currentDate().toString()+
         "</div>"
         "<br>"
            "<div align=center>"
            "<H3>"
            "BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA"
            "<br>""<br>"
            "FACULTAD DE CIENCIAS DE LA COMPUTACIÓN"
            "</H3>"
            "</div>"
        "<p align=justify>"
           "<h4>""LISTADO""</h4>"
            "<FONT FACE=times new roman>"
            +PDFESTADISTICA+
            "</FONT>"
            "</p>"
            "<br>"
            "<br>"
            "<br>";
    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:/Users/esteban/Desktop/EstadisticosA.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/esteban/Desktop/EstadisticosA.pdf"));
}

void administrador::on_est_materias_porcursar_clicked()
{
   QMessageBox::information(this,"PDF materias por cursar","El PDF con la estadistica se guardo en tu escritorio.\nGracias.","Aceptar");
   int total2016, total2017,Matricula,Porcentaje;
   QSqlQuery estadistico(mdb);
   QString Codigo, Nonbre,MatriculaS;
   estadistico.prepare("select count(*) from porcursar  where Matricula Between 201600000 and 201700000");
   estadistico.exec();
   if(estadistico.next())
   {
       total2016 = estadistico.value(0).toInt();
   }
   estadistico.prepare("select count(*) from porcursar where Matricula Between 201700000 and 201800000");
   estadistico.exec();
   if(estadistico.next())
   {
       total2017 = estadistico.value(0).toInt();
   }
   estadistico.prepare("select Código, count(Matricula) from porcursar where Matricula between 201600000 and 201700000 group by código;");
   estadistico.exec();
    while(estadistico.next()){
        Codigo = estadistico.value(0).toString();
        Matricula = estadistico.value(1).toInt();
        //qDebug()<<Matricula;
        QSqlQuery Nombre(mdb);
        Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
        Nombre.exec();
        Nombre.next();
        Nonbre = Nombre.value(0).toString();

        Porcentaje = Matricula;
        MatriculaS = QString::number(Porcentaje);
        qDebug() << Porcentaje;
PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " ""alumnos 2016"" "+"<br>"+"<br>"+"<br>";
    }
    qDebug()<< PDFESTADISTICA;
    estadistico.prepare("select Código, count(Matricula) from porcursar where Matricula between 201700000 and 201800000 group by código;");
    estadistico.exec();
     while(estadistico.next()){
         Codigo = estadistico.value(0).toString();
         Matricula = estadistico.value(1).toInt();
         QSqlQuery Nombre(mdb);
         Nombre.prepare("select Nombre from Materia where Código = '"+Codigo+"'");
         Nombre.exec();
         Nombre.next();
         Nonbre = Nombre.value(0).toString();

         Porcentaje = Matricula;
         MatriculaS = QString::number(Porcentaje);
         qDebug() << Porcentaje;
 PDFESTADISTICA += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " ""alumnos 2017"" "+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< PDFESTADISTICA;

   QString html =
           "<H1 align=center>ESTADISTICO MATERIAS POR CURSAR </H1>"
           "<br>"
           "<img src='C:/Users/esteban/Desktop/git 7/SCS/SCS/Images/FCC.jfif' width='150' height='150'>"
        "</div>"
        "<div align=right>"
           "PUEBLA,"+QDate::currentDate().toString()+
        "</div>"
        "<div align=center>"
        "<H3>"
        "BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA"
        "<br>""<br>"
        "FACULTAD DE CIENCIAS DE LA COMPUTACIÓN"
        "</H3>"
        "</div>"
       "<p align=justify>"
        "<h4>""LISTADO""</h4>"
         "<FONT FACE=times new roman>"
           +PDFESTADISTICA+
           "</FONT>"
           "</p>"
           "<br>"
           "<br>"
           "<br>";
   QTextDocument document;
   document.setHtml(html);

   QPrinter printer(QPrinter::PrinterResolution);
   printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setPaperSize(QPrinter::A4);
   printer.setOutputFileName("C:/Users/esteban/Desktop/EstadisticosP.pdf");
   printer.setPageMargins(QMarginsF(15, 15, 15, 15));

   document.print(&printer);

   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/esteban/Desktop/EstadisticosP.pdf"));
}
