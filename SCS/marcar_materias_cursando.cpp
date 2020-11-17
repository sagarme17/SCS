#include "marcar_materias_cursando.h"
#include "ui_marcar_materias_cursando.h"

#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

marcar_Materias_Cursando::marcar_Materias_Cursando(QString matricula, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marcar_Materias_Cursando)
{
    ui->setupUi(this);
    this->matricula=matricula;
    this->mdb=QSqlDatabase::database("Connection");
    this->contadormat=0;
   LlenarTablaCursando();
}

marcar_Materias_Cursando::~marcar_Materias_Cursando()
{
    delete ui;
}

void marcar_Materias_Cursando::on_Regresar_clicked()
{
    close();
}
void marcar_Materias_Cursando::LlenarTablaCursando()
{
    if(mdb.open())
    {
        QSqlQuery query1(mdb),query2(mdb);

        ui->tablacursando->setRowCount(0);

        query1.prepare("CALL tabla_cursando('"+matricula+"');");
        query1.exec();

        while (query1.next()) {
            QCheckBox* MateriasCursando=new QCheckBox();

          //MateriasProyectadas();
            QTableWidgetItem *uno=new QTableWidgetItem(query1.value(0).toString());
            QTableWidgetItem *dos=new QTableWidgetItem(query1.value(1).toString());
            QTableWidgetItem *tres=new QTableWidgetItem(query1.value(2).toString());
            QTableWidgetItem *cuatro=new QTableWidgetItem(query1.value(3).toString());

            ui->tablacursando->setRowCount(ui->tablacursando->rowCount()+1);
            ui->tablacursando->setItem(ui->tablacursando->rowCount()-1,0,uno);
            ui->tablacursando->setItem(ui->tablacursando->rowCount()-1,1,dos);
            ui->tablacursando->setItem(ui->tablacursando->rowCount()-1,2,tres);
            ui->tablacursando->setItem(ui->tablacursando->rowCount()-1,3,cuatro);
            ui->tablacursando->setCellWidget(ui->tablacursando->rowCount()-1,4,MateriasCursando);

            connect(MateriasCursando,SIGNAL(stateChanged(int)),this,SLOT(BoxChecked()));
        }
        ui->tablacursando->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    }

}

void marcar_Materias_Cursando::BoxChecked()
{

    QCheckBox * a;
    a=qobject_cast<QCheckBox*>(ui->tablacursando->cellWidget(ui->tablacursando->currentRow(),4));

    if(a->isChecked() && contadormat<6)
       {
           qDebug()<<"Se selecciono";
           contadormat++;
            qDebug()<<contadormat;
            //qDebug()<<ui->Tabla1->item(0,0)->text();

       }else if(!a->isChecked())
       {
           qDebug()<<"Se desmarco";
           contadormat--;
            qDebug()<<contadormat;
       }
    else if(contadormat>=6 )
    {
       // Materias++;
        a->setChecked(false);  // NO PICAR DE NUEVOOOOO
        QMessageBox::critical(this,"Error","Se debe seleccionar de 3 a 6 materias","Aceptar");
                 qDebug()<<contadormat;
    }

}

void marcar_Materias_Cursando::on_Aceptar_clicked()
{

    QSqlQuery query1(mdb);
    QCheckBox *b;
    if(contadormat<3)
    {
        qDebug()<<"TE FALTAAAAAAN";
        QMessageBox::critical(this,"Error","Te faltan materias por seleccionar","Aceptar");

        }else
            {
             if(!QMessageBox::question(this,"Enviar Cambios","¿Está seguro de sus marcaciones?","Sí","No"))
              {
                qDebug()<<"MATERIAS";
                  for( int i=0; i<ui->tablacursando->rowCount(); i++)
                 {

                    b=qobject_cast<QCheckBox*>(ui->tablacursando->cellWidget(i,4));
                      if(b->isChecked())
                     {

                     qDebug()<<ui->tablacursando->item(i,0)->text();
                     query1.prepare("INSERT INTO cursando (`Matricula`, `Código`) VALUES ('"+matricula+"', '"+ui->tablacursando->item(i,0)->text()+"')");
                     query1.exec();
                     query1.next();
                     }
                  }
             }else return;


              if(!query1.next())
              {

                   QMessageBox::information(this,"Materias cargadas","Tu avance ha sido actualizado","Aceptar");
                   LlenarTablaCursando();
                   close();

              }
            }
}
