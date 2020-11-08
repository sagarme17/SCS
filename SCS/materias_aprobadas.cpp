#include "materias_aprobadas.h"
#include "ui_materias_aprobadas.h"

#include <QMessageBox>
#include <QComboBox>
#include <QDebug>

materias_aprobadas::materias_aprobadas(QString matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materias_aprobadas)
{
    ui->setupUi(this);
    this->matricula=matricula;
    this->mdb=QSqlDatabase::database("Connection");
    this->Materias=0;
    LlenarTableAprobada();
}

materias_aprobadas::~materias_aprobadas()
{
    delete ui;
}
void materias_aprobadas::on_Regresar_clicked()
{
    close();
}
void materias_aprobadas::LlenarTableAprobada()
{
    if(mdb.open())
    {
        QSqlQuery query1(mdb),query2(mdb);

        ui->marcar->setRowCount(0);


        query1.prepare("select materia.Código,Nombre,Horas_PeriodoPT,Creditos from materia inner join cursando on materia.Código=cursando.Código where cursando.Matricula='"+matricula+"'"); //CURSANDO
        query1.exec();

        while (query1.next()) {
            QComboBox* combo=new QComboBox();
            combo->addItem(" ");
            combo->addItem("Aprobada");
            combo->addItem("Reprobada");

          //MateriasCursando();
            QTableWidgetItem *uno=new QTableWidgetItem(query1.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(query1.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(query1.value(2).toString());
            QTableWidgetItem *cuatro=new QTableWidgetItem(query1.value(3).toString());

            ui->marcar->setRowCount(ui->marcar->rowCount()+1);
            ui->marcar->setItem(ui->marcar->rowCount()-1,0,uno);
            ui->marcar->setItem(ui->marcar->rowCount()-1,1,dos);
            ui->marcar->setItem(ui->marcar->rowCount()-1,2,tres);
            ui->marcar->setItem(ui->marcar->rowCount()-1,3,cuatro);
            ui->marcar->setCellWidget(ui->marcar->rowCount()-1,4,combo);
        }

    }

}

void materias_aprobadas::on_Actualizar_clicked()
{
     if(mdb.open()){
         QSqlQuery eliminar(mdb),alta(mdb);
         int tam=ui->marcar->rowCount();
         for(int i=0;i<tam;i++)
          {
            QComboBox *combo;
            combo=qobject_cast<QComboBox*>(ui->marcar->cellWidget(i,4));
             if(combo->currentText()==" "){
                 QMessageBox::critical(this,"Error","Le faltan materias por elegir estado.","Aceptar");
                 return;
             }
           }

         for(int i=0;i<tam;i++)
          {
            QComboBox *combo;
            qDebug()<<"Entro for";
            combo=qobject_cast<QComboBox*>(ui->marcar->cellWidget(i,4));
             if(combo->currentText()=="Aprobada"){
                 alta.prepare("INSERT INTO aprobado (Matricula, Código) VALUES ('"+matricula+"', '"+ui->marcar->item(i,0)->text()+"')");
                 alta.exec();
                 alta.next();
                 alta.clear();

                 eliminar.prepare("DELETE FROM cursando WHERE (Matricula = '"+matricula+"') and (Código = '"+ui->marcar->item(i,0)->text()+"')");
                 eliminar.exec();
                 eliminar.next();
                 eliminar.clear();
             }else
            if(combo->currentText() =="Reprobada"){
                 eliminar.prepare("DELETE FROM cursando WHERE (Matricula = '"+matricula+"') and (Código = '"+ui->marcar->item(i,0)->text()+"')");
                 eliminar.exec();
                 eliminar.next();
                 eliminar.clear();
                }
             else return;

         }
         QMessageBox::information(this,"Actualizado","Su avance se ha actualizado.","Aceptar");
         LlenarTableAprobada();
     }//For
}

