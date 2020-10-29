#include "administrador.h"
#include "Cambiar_contrasena.h"
#include "ui_administrador.h"
#include "restablecer_contrasena1.h"

#include <QPrinter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>



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
            "<img src='C:/Users/saul-/OneDrive/Escritorio/SCS/SCS/SCS/Images/buap.jfif' width='100' height='100'>"
         "</div>"
         "<div align=right>"
            "PUEBLA,"+QDate::currentDate().toString()+
         "</div>"
         "<br>"
          "<br>"
            "<div align=left>"
            "ESTADISTICA MATERIAS CURSANDO<br>"
         "<br>"
         "<br>"
        "<p align=justify>"
           "LISTADO "
            +PDFESTADISTICA+
            "</p>"
            "<br>"
            "<br>"
            "<br>";
    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("C:/Users/saul-/OneDrive/Escritorio/Estadisticos.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/saul-/OneDrive/Escritorio/Estadisticos.pdf"));
}

void administrador::on_Restablecer_contras_clicked()
{
    restablecer_contrasena1 windo(NULL,nullptr);
    windo.setWindowTitle("Restablecer contraseñas");
    windo.exec();
}
