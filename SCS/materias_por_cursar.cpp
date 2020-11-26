#include "materias_por_cursar.h"
#include "ui_materias_por_cursar.h"

#include <QDateTime>
#include <QMessageBox>
#include <QCheckBox>


#include <QPushButton>
#include <QDebug>

materias_por_cursar::materias_por_cursar(QString matricula,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materias_por_cursar)
{
    ui->setupUi(this);
    this->matricula=matricula;
    this->mdb=QSqlDatabase::database("Connection");
     qDebug()<<"ENTRO A EL CONTRUCTOR";
     this->Materias=0;
    LlenarTabla();
}

materias_por_cursar::~materias_por_cursar()
{
    delete ui;
}

void materias_por_cursar::LlenarTabla()
{
   //MateriasCursando();
   MateriasNuevas();
}

void materias_por_cursar::on_pushButton_2_clicked()
{
    close();
}



void materias_por_cursar::MateriasNuevas()
{

    if(mdb.open())
    {
         qDebug()<<"MATERIAS NUEVAS";
        QSqlQuery query1(mdb),query2(mdb),query3(mdb),estadistico(mdb);
        int total=0,Porcentaje;

        ui->Tabla1->setRowCount(0);



        query1.prepare("CALL tabla_porcursar('"+matricula+"')"); //PROCEDIMIENTO QUE MUESTRA LAS MATERIAS CON PRERREQUISITOS
        query1.exec();

        query2.prepare("select materia.Código,Nombre,Horas_PeriodoPT,Creditos from materia inner join cursando on materia.Código=cursando.Código where cursando.Matricula='"+matricula+"'"); //CURSANDO
        query2.exec();

        query3.prepare("select materia.Código,materia.Nombre,materia.Horas_PeriodoPT,materia.Creditos from materia inner join prerequisito on materia.Código=prerequisito.Código where (prerequisito.CódigoPre='70C') and (materia.Código not in (select Código from aprobado where matricula='"+matricula+"')); ");
        query3.exec();

        estadistico.prepare("select count(*) from aprobado  where Matricula='"+matricula+"'");
        estadistico.exec();

        if(estadistico.next()){
            total= estadistico.value(0).toInt();
        }
        Porcentaje = (total * 100)/50;

        while (query2.next()) {

            QCheckBox* MateriasxCursar=new QCheckBox();
             //QPushButton* MateriasxCursar=new QPushButton();
            QLabel* cursando=new QLabel();


            //MateriasxCursar->setText("CLIKC");

             cursando->setText("CURSANDO");
          //MateriasCursando();
            QTableWidgetItem *uno=new QTableWidgetItem(query2.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(query2.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(query2.value(2).toString());

            QTableWidgetItem *cuatro=new QTableWidgetItem(query2.value(3).toString());

            ui->Tabla1->setRowCount(ui->Tabla1->rowCount()+1);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,0,uno);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,1,dos);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,2,tres);
            ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,3,cuatro);

            ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,5,MateriasxCursar);

            ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,4,cursando); //AQUI ESTAN LAS CURSANDO

            connect(MateriasxCursar,SIGNAL(stateChanged(int)),this,SLOT(BoxChecked()));

             }
              ui->Tabla1->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);


        while(query1.next())
        {

            QCheckBox* MateriasxCursar=new QCheckBox();
            QLabel* cursando=new QLabel();


                      //MateriasxCursar->setText("CLIKC");

                      cursando->setText("CURSANDO");
                    //MateriasCursando();
                      QTableWidgetItem *uno=new QTableWidgetItem(query1.value(0).toString());
                      QTableWidgetItem *dos=new QTableWidgetItem(query1.value(1).toString());
                      QTableWidgetItem *tres=new QTableWidgetItem(query1.value(2).toString());

                      QTableWidgetItem *cuatro=new QTableWidgetItem(query1.value(3).toString());

                      ui->Tabla1->setRowCount(ui->Tabla1->rowCount()+1);
                      ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,0,uno);
                      ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,1,dos);
                      ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,2,tres);
                      ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,3,cuatro);

                      ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,5,MateriasxCursar);
                      //if(query2.next())
                      //{
                          //ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,4,cursando);
                      //}
                      //MateriasxCursar->stateChanged->emit(checkbox->checkState())
                       //connect(MateriasxCursar,SIGNAL(clicked()),this,SLOT(BoxChecked()));

                      connect(MateriasxCursar,SIGNAL(stateChanged(int)),this,SLOT(BoxChecked()));
             }
                ui->Tabla1->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

                if(Porcentaje>=70) /*******-------------------------------------------------------------------******/
                 {

                    while (query3.next()) {
                        QCheckBox* MateriasxCursar=new QCheckBox();
                        QLabel* cursando=new QLabel();


                                  //MateriasxCursar->setText("CLIKC");

                                  cursando->setText("CURSANDO");
                                //MateriasCursando();
                                  QTableWidgetItem *uno=new QTableWidgetItem(query3.value(0).toString());
                                  QTableWidgetItem *dos=new QTableWidgetItem(query3.value(1).toString());
                                  QTableWidgetItem *tres=new QTableWidgetItem(query3.value(2).toString());

                                  QTableWidgetItem *cuatro=new QTableWidgetItem(query3.value(3).toString());

                                  ui->Tabla1->setRowCount(ui->Tabla1->rowCount()+1);
                                  ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,0,uno);
                                  ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,1,dos);
                                  ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,2,tres);
                                  ui->Tabla1->setItem(ui->Tabla1->rowCount()-1,3,cuatro);

                                  ui->Tabla1->setCellWidget(ui->Tabla1->rowCount()-1,5,MateriasxCursar);

                                  connect(MateriasxCursar,SIGNAL(stateChanged(int)),this,SLOT(BoxChecked()));
                    }
                    ui->Tabla1->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

              }else;

  }



}




void materias_por_cursar::on_pushButton_clicked()
{
    QSqlQuery query1(mdb);
    QCheckBox *b;
    if(Materias<6)
    {
        qDebug()<<"TE FALTAAAAAAN";
        QMessageBox::critical(this,"Error","Te faltan materias por seleccionar","Aceptar");

        }else
            {
                qDebug()<<"MATERIAS";
              for( int i=0; i<ui->Tabla1->rowCount(); i++)
             {

                b=qobject_cast<QCheckBox*>(ui->Tabla1->cellWidget(i,5));
                  if(b->isChecked())
                 {

                 qDebug()<<ui->Tabla1->item(i,0)->text();
                 query1.prepare("INSERT INTO porcursar (`Matricula`, `Código`) VALUES ('"+matricula+"', '"+ui->Tabla1->item(i,0)->text()+"')");
                 query1.exec();
                 query1.next();

                 }
              }

              if(!query1.next()) //TIEMPOS?
              {

                   QMessageBox::information(this,"Materias cargadas","Tus materias han sido enviadas","Aceptar");
                   close();
              }
            }

}


void materias_por_cursar::BoxChecked()
{

    QCheckBox * a;
    a=qobject_cast<QCheckBox*>(ui->Tabla1->cellWidget(ui->Tabla1->currentRow(),5));

    if(a->isChecked() && Materias<6)
       {
           qDebug()<<"Se selecciono";
           Materias++;
            qDebug()<<Materias;
            //qDebug()<<ui->Tabla1->item(0,0)->text();

       }else if(!a->isChecked())
       {
           qDebug()<<"Se desmarco";
           Materias--;
            qDebug()<<Materias;
       }
    else if(Materias>=6)
    {
       // Materias++;
        a->setChecked(false);  // NO PICAR DE NUEVOOOOO
        QMessageBox::critical(this,"Error","Se debe seleccionar solo 6 materias","Aceptar");
                 qDebug()<<Materias;
    }

}
//QMessageBox::critical(this,"Error","Se debe seleccionar al menos 6 materias","Aceptar");
