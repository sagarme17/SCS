#include "materias_por_cursar.h"
#include "ui_materias_por_cursar.h"

#include <QDateTime>
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

materias_por_cursar::materias_por_cursar(QString matricula,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materias_por_cursar)
{
    ui->setupUi(this);
    this->matricula=matricula;
    this->mdb=QSqlDatabase::database("Connection");
     qDebug()<<"ENTRO A EL CONTRUCTOR";
    LlenarTabla();
}

materias_por_cursar::~materias_por_cursar()
{
    delete ui;
}

void materias_por_cursar::LlenarTabla()
{
    if(mdb.open())
    {
         qDebug()<<"ENTRO A LLENAR TABLA";
        QSqlQuery query1(mdb),query2(mdb),registro(mdb),query3(mdb);
        //QString matriculaA=QString::number(matricula);

        ui->Tabla1->setRowCount(0);

        query1.prepare("select materia.Código,Nombre,Horas_PeriodoPT,Creditos from materia inner join cursando on materia.Código=cursando.Código where cursando.Matricula='"+matricula+"'");
        query1.exec();

        query2.prepare("");
        query2.exec();
       // query1.next();

        while (query1.next()) {
              //QComboBox* combo=new QComboBox();
            QCheckBox* MateriasxCursar=new QCheckBox();
            //QCheckBox* MateriasCursando=new QCheckBox();
            QLabel* cursando=new QLabel();
            cursando->setText("CURSANDO");

            QTableWidgetItem *uno=new QTableWidgetItem(query1.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(query1.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(query1.value(2).toString());
            QTableWidgetItem *cuatro=new QTableWidgetItem(query1.value(3).toString());
            //QTableWidgetItem *cinco=new QTableWidgetItem(query1.value(4).toString());
           // QTableWidgetItem *seis=new QTableWidgetItem(query1.value(5).toString());


            ui->Tabla1->setRowCount(ui->Tabla1->rowCount()+1);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,0,uno);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,1,dos);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,2,tres);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,3,cuatro);
            //ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,4,cinco);

            ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,5,MateriasxCursar);
            ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,4,cursando);
        }


    }
}

void materias_por_cursar::on_pushButton_2_clicked()
{
    close();
}
