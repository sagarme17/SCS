#include "basededatos.h"
#include <QtTest>
#include<QDateTime>
#include <QDate>
#include <QDebug>

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

