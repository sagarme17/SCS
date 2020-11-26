#include "visualizar_materias.h"
#include "ui_visualizar_materias.h"

visualizar_materias::visualizar_materias(QString matricula,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visualizar_materias)
{
    ui->setupUi(this);
    this->matricula=matricula;
    this->mdb=QSqlDatabase::database("Connection");
    LlenarTabla();
}

visualizar_materias::~visualizar_materias()
{
    delete ui;
}

void visualizar_materias::on_Regresar_clicked()
{
    close();
}

void visualizar_materias::LlenarTabla()
{
        QSqlQuery query1(mdb),query3(mdb),estadistico(mdb);

        ui->visualizar->setRowCount(0);

        query1.prepare("CALL tabla_cursando('"+matricula+"');");
        query1.exec();

        query3.prepare("select materia.Código,materia.Nombre,materia.Horas_PeriodoPT,materia.Creditos from materia inner join prerequisito on materia.Código=prerequisito.Código where (prerequisito.CódigoPre='70C') and (materia.Código not in (select Código from aprobado where matricula='"+matricula+"')); ");
        query3.exec();
        int total=0,Porcentaje;

        estadistico.prepare("select count(*) from aprobado  where Matricula='"+matricula+"'");
        estadistico.exec();
        if(estadistico.next()){
            total= estadistico.value(0).toInt();
        }
        Porcentaje = (total * 100)/50;

        while (query1.next()) {

            QTableWidgetItem *uno=new QTableWidgetItem(query1.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(query1.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(query1.value(2).toString());

            QTableWidgetItem *cuatro=new QTableWidgetItem(query1.value(3).toString());

            ui->visualizar->setRowCount(ui->visualizar->rowCount()+1);
            ui->visualizar->setItem(ui->visualizar->rowCount()-1,0,uno);
            ui->visualizar->setItem(ui->visualizar->rowCount()-1,1,dos);
            ui->visualizar->setItem(ui->visualizar->rowCount()-1,2,tres);
            ui->visualizar->setItem(ui->visualizar->rowCount()-1,3,cuatro);
        }
        ui->visualizar->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

        if(Porcentaje>=70) /*******-------------------------------------------------------------------******/
         {

            while (query3.next()) {


                QTableWidgetItem *uno=new QTableWidgetItem(query3.value(0).toString());
                QTableWidgetItem *dos=new QTableWidgetItem(query3.value(1).toString());
                QTableWidgetItem *tres=new QTableWidgetItem(query3.value(2).toString());

                QTableWidgetItem *cuatro=new QTableWidgetItem(query3.value(3).toString());

                ui->visualizar->setRowCount(ui->visualizar->rowCount()+1);
                ui->visualizar->setItem(ui->visualizar->rowCount()-1,0,uno);
                ui->visualizar->setItem(ui->visualizar->rowCount()-1,1,dos);
                ui->visualizar->setItem(ui->visualizar->rowCount()-1,2,tres);
                ui->visualizar->setItem(ui->visualizar->rowCount()-1,3,cuatro);
            }
            ui->visualizar->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

      }else;

}


