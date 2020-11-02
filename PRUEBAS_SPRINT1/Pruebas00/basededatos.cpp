#include "basededatos.h"
#include <QtTest>
#include<QDateTime>
#include <QDate>
#include <QDebug>
#include <iostream>
using namespace std;

baseDatos::baseDatos()
{
    mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
    //mDatabase.setPort(3306);
    //mDatabase.setHostName("localhost");
    //mDatabase.setUserName("root");
    //mDatabase.setPassword("");
    mDatabase.setDatabaseName("scs");
}
bool baseDatos::AutenticarseAdmin1()
{
    QSqlQuery buscar(mDatabase);
    buscar.prepare(" select * from usuario inner join administrador on  usuario.Id_Usuario=administrador.Id_Administrador and usuario.Contraseña=administrador.Id_Administrador");
    buscar.exec();
  if(buscar.next())
  {
      qDebug()<<"El administrador aun no cambia su contraseña";
      return true;

  }else
  {
       qDebug()<<"El administrador ya cambio su contraseña";
      return false;

  }


}
bool baseDatos::AutenticarseAlumno_1ra()
{
    QSqlQuery buscarA(mDatabase);
    QSqlQuery buscarA2(mDatabase);
    buscarA.prepare("select * from usuario inner join alumno on usuario.Id_Usuario=alumno.Matricula and usuario.Contraseña=alumno.Matricula");
    buscarA2.prepare("select * from usuario inner join alumno on usuario.Id_Usuario=alumno.Matricula and usuario.Contraseña<>alumno.Matricula");
    buscarA.exec();
    if(buscarA.next())
    {
         qDebug()<<"AUN HAY ALUMNOS CON LA MATRICULA COMO SU CONTRASEÑA";
        return true;
    }else if(buscarA2.next())
    {
         qDebug()<<"TODOS LOS ALUMNOS YA CAMBIARON SU CONTRASEÑA";
        return false;
    }

}
bool baseDatos::CambiarContraAdmin(int contra)
{
    QSqlQuery actualizar(mDatabase);
    QString i=QString::number(contra);
    //actualizar.prepare("update usuario set usuario.Contraseña='"+i+"'where   usuario.Id_Usuario=202000000");
    //actualizar.exec("update usuario set usuario.Contraseña='"+i+"'where   usuario.Id_Usuario=202000000");
    if(actualizar.exec("update usuario set usuario.Contraseña='"+i+"'where   usuario.Id_Usuario=202000000"))
    {
         qDebug()<<"El administrador ya cambio su contraseña";
        return true;
    }else
    {
        qDebug()<<"El administrador no ha cambiado su contraseña";
        return false;
    }
}
bool baseDatos::CambiarContraAlumno(int matricula,int contra)
{
     QSqlQuery actualizarA(mDatabase);
    QSqlQuery actualizarb(mDatabase);
     QString i=QString::number(matricula);
     QString b=QString::number(contra);
     //actualizarA.prepare("update usuario set usuario.Contraseña='"+i+"'where   usuario.Id_Usuario='"+b+"'");
     //actualizarA.exec();

     if(actualizarA.exec("update usuario set usuario.Contraseña='"+i+"'where   usuario.Id_Usuario='"+b+"'"))
     {
         actualizarb.prepare("select usuario.Contraseña from usuario inner join alumno on alumno.Matricula=:matric");
         actualizarb.bindValue(":matric",matricula);
         actualizarb.exec();
         actualizarb.first();
         if(actualizarb.value(0)==matricula)
         {
              qDebug()<<"El alumno actualizo su contraseña ";
              return true;
          }else
         {
             qDebug()<<"NO SE PUDO ACTUALIZAR LA CONTRASEÑA NO SE ENCONTRO EL USUARIO";
             return false;
         }

     }else
     {
         qDebug()<<"El alumno " + i + "  no ha cambiado su contraseña";
         return false;
     }
}
bool baseDatos::GeneralAutenticarse(int id, int contra)
{
    QSqlQuery ingreso(mDatabase);
    QString id_usuario=QString::number(id);
    QString c=QString::number(contra);
    ingreso.prepare("select usuario.Id_usuario , usuario.Contraseña from usuario inner join alumno on usuario.Id_Usuario='"+id_usuario+"' and usuario.Contraseña='"+c+"'");
    ingreso.exec();
    ingreso.first();
    if(ingreso.value(0)==id && ingreso.value(1)==contra)
    {
         qDebug()<<"AUTENTICANCION EXITOSA!";
        return true;
    }else
    {
        qDebug()<<"SU CONTRASEÑA O ID NO SON LOS CORRECTOS";
        return false;
    }
}
bool baseDatos::InsertarFoto1(QString direccion,int matricula)
{
    QSqlQuery foto(mDatabase);
    QString matri=QString::number(matricula);
   foto.prepare("INSERT INTO `foto`(`Direccion`, `Foto`, `Matricula`) VALUES (:direccionn,NULL,:matric)");
   foto.bindValue(":direccionn",direccion);
   foto.bindValue(":matric",matri);
    if(foto.exec())
    {
         qDebug()<<"FOTO ASOCIADA A EL ALUMNO CON MATRICULA!" +matri;
        return true;
    }else
    {
        qDebug()<<"No se cargo la foto";
        return false;
    }

}
/*---Segundo Sprint---*/
bool baseDatos::generarPDF(int matricula)
{
    QSqlQuery acceso(mDatabase),query1(mDatabase),query2(mDatabase),query3(mDatabase);
    QString matriculaA=QString::number(matricula),cod,totalN,totalPeriodo;
    int total=0,cred,hora,totalH=0;
    acceso.prepare("Select * from alumno where Matricula='"+matriculaA+"'");
    acceso.exec();
    if(acceso.next())
      {
        qDebug()<<"Matricula Existente";
        query1.prepare("select Código from alumno inner join cursando on alumno.Matricula=cursando.Matricula where alumno.Matricula='"+matriculaA+"'");
        query1.exec();
        qDebug()<<"------Materias cursando------";
        while (query1.next()) {
            cod=query1.value(0).toString();
            qDebug()<<"Código_Materia es: "+cod;
            query2.prepare("select Creditos from materia where Código='"+cod+"'");
            query2.exec();
            query3.prepare("select Horas_PeriodoPT from materia where Código='"+cod+"'");
            query3.exec();
           if(query2.next() and query3.next())
            {
                cred=query2.value(0).toInt();
                hora=query3.value(0).toInt();
                qDebug()<<"Creditos: "+QString::number(cred);
                qDebug()<<"Horas_Periodo : "+QString::number(hora);
                total+=cred;
                totalH+=hora;
            }

        }
        totalN=QString::number(total);
        qDebug()<<"El total de creditos cargados son: "+totalN;
        qDebug()<<"El total de horas(Teoria y practica) cargados son: "+QString::number(totalH);
        return true;
    }else
       {
            qDebug()<<"Matricula NO Existente";
            return false;
        }

}

bool baseDatos::HacerSolicitud(int matricula)
{
    QSqlQuery registro(mDatabase);
    QString matriculaA=QString::number(matricula);
    if(registro.exec("INSERT INTO `solicitud` ( `Matricula`) VALUES ('"+matriculaA+"')"))
    {
        qDebug()<<"Solicitud Cargada al alumno: "+matriculaA;
        return true;
    }else
    {
        qDebug()<<"No se pudo realizar la solicitud a la alumno: "+ matriculaA;
        return false;
    }
}
bool baseDatos::BuscarSolicitud(int matricula)
{
    QSqlQuery verSolicitud(mDatabase);
    verSolicitud.prepare("select *from alumno inner join solicitud where solicitud.Matricula='"+QString::number(matricula)+"'");
    verSolicitud.exec();
    if(verSolicitud.next())
    {
        qDebug()<<"Solicitud Encontrada!!!";
        return true;
    }else
    {
        return false;
    }
}
bool baseDatos::RestablecerContrasena(int matricula)
{
    QSqlQuery solicitud(mDatabase),query1(mDatabase),query2(mDatabase);
    QString matriculaA=QString::number(matricula);
    solicitud.prepare("select * from solicitud where solicitud.Matricula='"+matriculaA+"'");
    solicitud.exec();
    if(solicitud.next())
      {
        qDebug()<<"Alumno CON solicitud";

        if(query1.exec("update usuario set usuario.Contraseña='"+matriculaA+"'where   usuario.Id_Usuario='"+matriculaA+"'"))
        {
            qDebug()<<"Se restablecio la contraseña del alumno: "+matriculaA;
            query2.prepare("DELETE FROM solicitud WHERE solicitud.Matricula = '"+matriculaA+"'");
            query2.exec();
            query2.next();
            qDebug()<<"Solicitud asociada con la matricula "+matriculaA+" eliminada";
            return true;
        }else
        {
            qDebug()<<"No se pudo actualizar";
            return false;
        }
      }else
       {
          qDebug()<<"Alumno SIN solicitud";
          return false;
       }


}
bool baseDatos::MarcarMateriasPorCursar(int matricula, QString codigo)
{
    QSqlQuery query1(mDatabase),query2(mDatabase),registro(mDatabase),query3(mDatabase);
    QString matriculaA=QString::number(matricula),pre;
    /*Verifico se la materia que quiero marcar tiene prerequisito*/
    query1.prepare("select CódigoPre from materia inner join prerequisito on materia.Código=prerequisito.Código where prerequisito.Código='"+codigo+"'");
    query1.exec();
    if(query1.next()) {
        pre=query1.value(0).toString();
        qDebug()<<"Materia con prerequisito "+pre;
        /*Verifico que esta como prerequisito ya la aprobe*/
        query2.prepare("select Código from alumno inner join aprobado on alumno.Matricula=aprobado.Matricula where aprobado.Matricula='"+matriculaA+"' and aprobado.Código='"+pre+"'");
        query2.exec();
        if(query2.next())
        {
            qDebug()<<"La materia prerequisito "+pre+" esta aprobada";
            /*Cargar materia a tabla de porcursar*/
            if(registro.exec("INSERT INTO porcursar (`Matricula`, `Código`) VALUES ('"+matriculaA+"', '"+codigo+"')"))
            {
                qDebug()<<"Materia "+codigo+ "marcada como PorCursar";
                return true;
            }
            else
            {
                qDebug()<<"Materia "+codigo+ "SIN marcar como PorCursar";
                return false;
            }
        }
        else
        {
           qDebug()<<"La materia con código "+pre+" no esta aprobada";
           return false;
        }
    }else
    {
        qDebug()<<"Materia SIN prerequisito ";
        qDebug()<<"Se restablecio la contraseña del alumno: "+matriculaA;
        query2.prepare("INSERT INTO porcursar (`Matricula`, `Código`) VALUES ('"+matriculaA+"', '"+codigo+"')");
        query2.exec();
        query2.next();
        qDebug()<<"Se ha cargado la materia "+codigo+" al alumno "+matriculaA;
        return false;
    }

}
bool baseDatos::VisualizarAvance(int matricula)
{
    QSqlQuery acceso(mDatabase),query1(mDatabase),query2(mDatabase),query3(mDatabase);
    QSqlQuery query4(mDatabase),query5(mDatabase),query6(mDatabase);
    QSqlQuery query7(mDatabase),query8(mDatabase),query9(mDatabase);
    QSqlQuery numMaterias(mDatabase);
    QString matriculaA=QString::number(matricula),cod,totalN,totalPeriodo,totalNC,totalNP;
    int total=0,cred,hora,totalH=0,totalHC=0,totalHP=0,totalC=0,totalP=0;
    int matA=0,matC=0,matP=0;
    acceso.prepare("Select * from alumno where Matricula='"+matriculaA+"'");
    acceso.exec();
    if(acceso.next())
      {
        qDebug()<<"Matricula Existente";
        /*----------------------------*/
        query1.prepare("select Código from alumno inner join aprobado on alumno.Matricula=aprobado.Matricula where alumno.Matricula='"+matriculaA+"'");
        query1.exec();
        qDebug()<<"------Materias Aprobadas------";
        while (query1.next()) {
            matA++;
            cod=query1.value(0).toString();
            qDebug()<<"Código_Materia es: "+cod;
            query2.prepare("select Creditos from materia where Código='"+cod+"'");
            query2.exec();
            query3.prepare("select Horas_PeriodoPT from materia where Código='"+cod+"'");
            query3.exec();
           if(query2.next() and query3.next())
            {
                cred=query2.value(0).toInt();
                hora=query3.value(0).toInt();
                qDebug()<<"Creditos: "+QString::number(cred);
                qDebug()<<"Horas_Periodo : "+QString::number(hora);
                total+=cred;
                totalH+=hora;
            }
        }
        totalN=QString::number(total);
        qDebug()<<"Tiene "+QString::number(matA)+" materias aprobadas";
        qDebug()<<"El total de creditos APROBADOS son: "+totalN;
        qDebug()<<"El total de horas(Teoria y practica) APROBADAS son: "+QString::number(totalH);
        /*----------------------------*/
        query4.prepare("select Código from alumno inner join cursando on alumno.Matricula=cursando.Matricula where alumno.Matricula='"+matriculaA+"'");
        query4.exec();
        qDebug()<<"------Materias cursando------";
        while (query4.next()) {
            matC++;
            cod=query4.value(0).toString();
            qDebug()<<"Código_Materia es: "+cod;
            query5.prepare("select Creditos from materia where Código='"+cod+"'");
            query5.exec();
            query6.prepare("select Horas_PeriodoPT from materia where Código='"+cod+"'");
            query6.exec();
           if(query5.next() and query6.next())
            {
                cred=query5.value(0).toInt();
                hora=query6.value(0).toInt();
                qDebug()<<"Creditos: "+QString::number(cred);
                qDebug()<<"Horas_Periodo : "+QString::number(hora);
                totalC+=cred;
                totalHC+=hora;
            }
        }
        totalNC=QString::number(totalC);
        qDebug()<<"Tiene "+QString::number(matC)+" materias cursando";
        qDebug()<<"El total de creditos CURSANDO son: "+totalNC;
        qDebug()<<"El total de horas(Teoria y practica) CURSANDO son: "+QString::number(totalHC);
        /*-------------------------------*/
        query7.prepare("select Código from alumno inner join porcursar on alumno.Matricula=porcursar.Matricula where alumno.Matricula='"+matriculaA+"'");
        query7.exec();
        qDebug()<<"------Materias PorCursar------";
        while (query7.next()) {
            matP++;
            cod=query7.value(0).toString();
            qDebug()<<"Código_Materia es: "+cod;
            query8.prepare("select Creditos from materia where Código='"+cod+"'");
            query8.exec();
            query9.prepare("select Horas_PeriodoPT from materia where Código='"+cod+"'");
            query9.exec();
           if(query8.next() and query9.next())
            {
                cred=query8.value(0).toInt();
                hora=query9.value(0).toInt();
                qDebug()<<"Creditos: "+QString::number(cred);
                qDebug()<<"Horas_Periodo : "+QString::number(hora);
                totalP+=cred;
                totalHP+=hora;
            }
        }
        totalNP=QString::number(totalP);
        qDebug()<<"Tiene "+QString::number(matP)+" materias por cursar";
        qDebug()<<"El total de creditos POR CURSAR son: "+totalNP;
        qDebug()<<"El total de horas(Teoria y practica) POR CURSAR son: "+QString::number(totalHP);


        return true;
    }else
       {
            qDebug()<<"Matricula NO Existente";
            return false;
        }

}
