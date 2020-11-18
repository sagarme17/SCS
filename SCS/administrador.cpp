#include "administrador.h"
#include "cambiar_contrasena.h"
#include "ui_administrador.h"
#include "restablecer_contrasena1.h"

#include <QPrinter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>


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
    double total2016, total2017,Matricula,Porcentaje;
    QSqlQuery estadistico(mdb),logo(mdb),escudo(mdb);
    QString Codigo, Nonbre,MatriculaS;

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
 Cursando += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< Cursando;
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
  Cursando += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
      }
      qDebug()<< Cursando;

    QString html =
            "<img src=\"data:image/png;base64," + guardarlogo.toBase64() + "\" width='200' height='100' / >"
            "<img src=\"data:image/png;base64," + guardarescudo.toBase64() + "\" width='120' height='120' align='right' / >"
            "<br>"
            "<H1 align=center>ESTADISTICO MATERIAS CURSANDO</H1>"
            "<br>"
         "<div align=right>"
            "Heroico Estado de Puebla a "+QDate::currentDate().toString( "dddd  d , MMMM  , yyyy")+
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
            +Cursando+
            "</FONT>"
            "</p>"
            "<br>"
            "<br>"
            "<br>";
    QTextDocument docume;
    docume.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar Archivo"),
                                   "C:/Users/HP/Desktop/Estadistico materias cursando.pdf",
                                   tr("PDF-Files (*.pdf)"));
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    docume.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void administrador::on_Restablecer_contras_clicked()
{
    restablecer_contrasena1 windo(NULL,nullptr);
    windo.setWindowTitle("Restablecer contraseñas");
    windo.exec();
}

void administrador::on_est_materias_aprobadas_clicked()
{
    double total2016, total2017,Matricula,Porcentaje;
    QSqlQuery estadistico(mdb),logo(mdb),escudo(mdb);
    QString Codigo, Nonbre,MatriculaS;

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
 Aprobada += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< Aprobada;
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
  Aprobada += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " "+ "%"+"<br>"+"<br>"+"<br>";
      }
      qDebug()<< Aprobada;

    QString html =
            "<img src=\"data:image/png;base64," + guardarlogo.toBase64() + "\" width='200' height='100' / >"
            "<img src=\"data:image/png;base64," + guardarescudo.toBase64() + "\" width='120' height='120' align='right' / >"
            "<br>"
            "<H1 align=center>ESTADISTICO MATERIAS APROBADAS</H1>"
            "<br>"
         "<div align=right>"
           "Heroico Estado de Puebla a "+QDate::currentDate().toString( "dddd  d , MMMM  , yyyy")+
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
            +Aprobada+
            "</FONT>"
            "</p>"
            "<br>"
            "<br>"
            "<br>";
    QTextDocument documento;
    documento.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    QString Name = QFileDialog::getSaveFileName(this, tr("Guardar Archivo"),
                                   "C:/Users/HP/Desktop/Estadistico materias aprobadas.pdf",
                                   tr("PDF-Files (*.pdf)"));
    printer.setOutputFileName(Name);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    documento.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(Name));
}

void administrador::on_est_materias_porcursar_clicked()
{
   double total2016, total2017,Matricula,Porcentaje;
   QSqlQuery estadistico(mdb),logo(mdb),escudo(mdb);
   QString Codigo, Nonbre,MatriculaS;

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
PCursar += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " ""alumnos 2016"" "+"<br>"+"<br>"+"<br>";
    }
    qDebug()<< PCursar;
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
 PCursar += "<br>"+ Codigo+ " "+ Nonbre+ " "+ MatriculaS+ " ""alumnos 2017"" "+"<br>"+"<br>"+"<br>";
     }
     qDebug()<< PCursar;

   QString html =
           "<img src=\"data:image/png;base64," + guardarlogo.toBase64() + "\" width='200' height='100' / >"
           "<img src=\"data:image/png;base64," + guardarescudo.toBase64() + "\" width='120' height='120' align='right' / >"
           "<br>"
           "<H1 align=center>ESTADISTICO MATERIAS POR CURSAR</H1>"
           "<br>"
        "<div align=right>"
           "Heroico Estado de Puebla a "+QDate::currentDate().toString( "dddd  d , MMMM  , yyyy")+
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
           +PCursar+
           "</FONT>"
           "</p>"
           "<br>"
           "<br>"
           "<br>";
   QTextDocument document;
   document.setHtml(html);

   QPrinter printe(QPrinter::PrinterResolution);
   printe.setOutputFormat(QPrinter::PdfFormat);
   printe.setPaperSize(QPrinter::A4);
   QString file = QFileDialog::getSaveFileName(this, tr("Guardar Archivo"),
                                  "C:/Users/HP/Desktop/Estadistico materias por cursar.pdf",
                                  tr("PDF-Files (*.pdf)"));
   printe.setOutputFileName(file);
   printe.setPageMargins(QMarginsF(15, 15, 15, 15));

   document.print(&printe);

   QDesktopServices::openUrl(QUrl::fromLocalFile(file));
}
