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
            QPushButton* btnEst = new QPushButton();
            combo->addItem(" ");
            combo->addItem("Aprobada");
            combo->addItem("Reprobada");
            btnEst->setText("Mover");
            btnEst->setStyleSheet("background-color:#098AB9");

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
            ui->marcar->setCellWidget(ui->marcar->rowCount()-1,5,btnEst);

            connect(btnEst,SIGNAL(clicked()),this,SLOT(btnEstclicked()));
        }

    }

}

void materias_aprobadas::btnEstclicked(){
    if(mdb.open()){
        qDebug()<<"Entro clicked";
        QSqlQuery eliminar(mdb),alta(mdb);

        QComboBox *combo;
        combo=qobject_cast<QComboBox*>(ui->marcar->cellWidget(ui->marcar->currentRow(),4));

        if(combo->currentText()=="Aprobada"){
            QString cod=ui->marcar->item(ui->marcar->currentRow(),0)->text();
             qDebug()<<"el codigo es"+cod;
            alta.prepare("INSERT INTO aprobado (Matricula, Código) VALUES ('"+matricula+"', '"+cod+"')");
            alta.exec();
            alta.next();
            eliminar.prepare("DELETE FROM cursando WHERE (Matricula = '"+matricula+"') and (Código = '"+cod+"')");
            eliminar.exec();
            eliminar.next();

            QMessageBox::information(this,"Aprobada","Su materia ha sido cambiada a aprobada","Aceptar");
            LlenarTableAprobada();
        }
        else if(combo->currentText()=="Reprobada"){
            QString cod=ui->marcar->item(ui->marcar->currentRow(),0)->text();
            eliminar.prepare("DELETE FROM cursando WHERE (Matricula = '"+matricula+"') and (Código = '"+cod+"')");
            eliminar.exec();
            eliminar.next();
            QMessageBox::information(this,"Aprobada","Su materia ha dejado de estar en cursando ","Aceptar");
            LlenarTableAprobada();

        }else if(combo->currentText()==" ")
        {
            QMessageBox::critical(this,"Vacio","Falta seleccionar una opción","Aceptar");
        }else return;
    }
}


