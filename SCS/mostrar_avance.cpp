#include "mostrar_avance.h"
#include "ui_mostrar_avance.h"
#include <QDebug>

mostrar_avance::mostrar_avance(QString Matricula,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mostrar_avance)
{
    ui->setupUi(this);
    this->Matricula=Matricula;
    this->mdb=QSqlDatabase::database("Connection");
    aprobada();
    cursando();
}

mostrar_avance::~mostrar_avance()
{
    delete ui;
}

void mostrar_avance::on_Regresar_clicked()
{
    close();
}

void mostrar_avance::cursando()
{

    QSqlQuery query4(mdb),query1(mdb);
    QString a;
    int abd;
    query4.prepare("select distinct m.identificadorMapa,c.Código from cursando as c inner join materia as m on c.Código=m.Código where c.Matricula='"+Matricula+"'");
    query4.exec();
    while(query4.next())
    {
       abd=query4.value(0).toInt();
      //Debug()<<"jale";
      //Debug()<<abd;
    switch(abd)
    {
    case 1:
        ui->ICCS_001->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 2:
        ui->CCOS_003->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 3:
        ui->CCOS_001->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 4:
        ui->FGUS_004->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 5:
        ui->FGUS_001->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 6:
        ui->CCOS_007->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 7:
        ui->ICCS_002->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 8:
        ui->ICCS_003->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 9:
        ui->CCOS_004->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 10:
        ui->FGUS_005->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 11:
        ui->FGUS_002->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        /*Tercer Semestre*/
    case 12:
        ui->CCOS_008->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 13:
        ui->ICCS_004->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 14:
        ui->ICCS_005->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 15:
        ui->CCOS_010->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 16:
        ui->CCOS_005->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 17:
        ui->FGUS_006->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        /*Cuarto sementre*/
    case 18:
        ui->ICCS_006->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 19:
        ui->ICCS_007->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 20:
        ui->CCOS_261->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 21:
        ui->CCOS_013->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 22:
        ui->FGUS_007->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    //QUINTO
    case 23:
        ui->CCOS_251->setStyleSheet("image: url(:/Images/Reloj.png); background:transparent;");
        //ui->CCOS_251->setStyleSheet( "background:transparent; border:none; outline:none;");
        break;
     case 24:
         ui->ICCS_250->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     case  25:
         ui->CCOS_252->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     case 26:
         ui->ISCO_201->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     case  27:
         ui->ISCO_200->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     //SEXTO SEMESTRE
     case 28:
         ui->ICCS_259->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     case  29:
         ui->ICCS_253->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
      case 30:
         ui->ICCS_256->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
      case  31:
         ui->CCOS_254->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
       case 32:
         ui->IDDS_001->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
     //SEPTIMO SEMESTRE
       case 33:
         ui->ICCS_260->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
       case 34:
         ui->ICCS_257->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
       case 35:
         ui->ISCC_201->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
       case 36:
         ui->ICCS_251->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
       case 37:
         ui->ICCS_258->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
      //OCTAVO SEMESTRE
        case 38:
         ui->ICCS_254->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
        case 39:
         ui->ICCS_261->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
        case 40:
         ui->ICCS_255->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
        case 41:
         ui->ICCS_252->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
        case 42:
         ui->IDCC_002->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
         // Noveno Semestre
         case 43:
         ui->ICCS_262->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
        case 44:
        ui->ISCC_202->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        case 45:
        ui->SSCC_100->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        case 46:
        ui->PPCc_101->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        case 47:
        ui->IDDS_002->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;



//OPTATIVAS ESTEBAN

   case 48:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_600.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 49:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_605.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
     case 50:
        ui->Optativa_1->setStyleSheet("borde-image: url(:/Images/ICCS _601.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
     case 51:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_603.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
     case 52:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_601.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        /*OptativasChio*/
    case 53:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_607.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 54:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_608.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
    case 55:
       ui->Optativa_1->setStyleSheet("borde-image: url(:/Images/ICCS _602.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
       break;
    case 56:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_607.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
       break;
    case 57:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_264.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
       break;

       //SIMULACION OPTV1
    case 58:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_606.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        //COMPUTO BASICO OPTV1
     case 59:
         ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_604.bmp)");
         ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
         //ARQUITECTURA AVNZD DE COMPU. OPTV2
     case 60:
         ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_611.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
         //INVESTIGACION DE OPERACIONES OPTV2
     case 61:
         ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_608.bmp)");
         ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
         break;
         //SUPER COMPUTO OPTV2
     case 62:
            ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_609.bmp)");
            ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
            break;
         //SISTEMAS INTERACTIVOS MODERNOS
     case 63:
            ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_610.bmp)");
            ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
            break;
         //WEB SEMÁNTICO
     case 64:
            ui->Optativa_2->setStyleSheet("border-image: url(:/Images/CCOS_600.bmp)");
            ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
            break;
         //ALMACENAMIENTO DE DATOS
     case 65:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_614.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
         //CONTROL DIGITAL
     case 66:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_613.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        //ROBÓTICA APLICADA
     case 67:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Reloj.png); background:transparent;");
        break;
        //Saul
     case 68:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case 69:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case 70:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case 71:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case 72:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;






    }
}
}

void mostrar_avance::aprobada()
{

    QSqlQuery query(mdb);
    int r;
    query.prepare("select distinct m.identificadorMapa,a.Código from aprobado as a inner join materia as m on a.Código=m.Código where a.Matricula='"+Matricula+"'");
    query.exec();
    while(query.next())
    {
       r=query.value(0).toInt();
      //Debug()<<"jal";
      //Debug()<<r;
    switch(r)
    {
    case 1:
        ui->ICCS_001->setStyleSheet("image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 2:
        ui->CCOS_003->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 3:
        ui->CCOS_001->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 4:
        ui->FGUS_004->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 5:
        ui->FGUS_001->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 6:
        ui->CCOS_007->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 7:
        ui->ICCS_002->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 8:
        ui->ICCS_003->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 9:
        ui->CCOS_004->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 10:
        ui->FGUS_005->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 11:
        ui->FGUS_002->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
        /*Tercer semestre*/
    case 12:
        ui->CCOS_008->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 13:
        ui->ICCS_004->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 14:
        ui->ICCS_005->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 15:
        ui->CCOS_010->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 16:
        ui->CCOS_005->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 17:
        ui->FGUS_006->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
        /*Cuarto sementre*/
    case 18:
        ui->ICCS_006->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 19:
        ui->ICCS_007->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 20:
        ui->CCOS_261->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 21:
        ui->CCOS_013->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 22:
        ui->FGUS_007->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
   //QUINTO
     case 23:
        ui->CCOS_251->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case 24:
        ui->ICCS_250->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
     case  25:
         ui->CCOS_252->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
         break;
     case 26:
         ui->ISCO_201->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
         break;
     case  27:
          ui->ISCO_200->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
          break;
   //SEXTO SEMESTRE
     case 28:
           ui->ICCS_259->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case  29:
           ui->ICCS_253->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 30:
           ui->ICCS_256->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case  31:
           ui->CCOS_254->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 32:
           ui->IDDS_001->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
   //SEPTIMO SEMESTRE
     case 33:
           ui->ICCS_260->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 34:
           ui->ICCS_257->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 35:
           ui->ISCC_201->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 36:
           ui->ICCS_251->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
     case 37:
           ui->ICCS_258->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
   //OCTAVO SEMESTRE
      case 38:
           ui->ICCS_254->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
      case 39:
           ui->ICCS_261->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
      case 40:
           ui->ICCS_255->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
      case 41:
           ui->ICCS_252->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
      case 42:
           ui->IDCC_002->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;

           // Noveno Semestre
           case 43:
           ui->ICCS_262->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
          case 44:
          ui->ISCC_202->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
          break;
          case 45:
          ui->SSCC_100->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
          break;
          case 46:
          ui->PPCc_101->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
          break;
          case 47:
          ui->IDDS_002->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
          break;
//OPTATIVAS

    case 48:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_600.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 49:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_605.bmp)");
         ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 50:
       ui->Optativa_1->setStyleSheet("borde-image: url(:/Images/ICCS _601.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 51:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_603.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 52:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_601.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    /*OptativasChio*/
    case 53:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_607.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 54:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_608.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 55:
       ui->Optativa_1->setStyleSheet("borde-image: url(:/Images/ICCS _602.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    case 56:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_607.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 57:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/CCOS_264.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;

    //SIMULACION OPTV1
    case 58:
       ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_606.bmp)");
       ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    //COMPUTO BASICO OPTV1
    case 59:
        ui->Optativa_1->setStyleSheet("border-image: url(:/Images/ICCS_604.bmp)");
        ui->Codigo_optativa1->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    //ARQUITECTURA AVNZD DE COMPU. OPTV2
    case 60:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_611.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    //INVESTIGACION DE OPERACIONES OPTV2
    case 61:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_608.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
    //SUPER COMPUTO OPTV2
     case 62:
        ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_609.bmp)");
        ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
        //SISTEMAS INTERACTIVOS MODERNOS
    case 63:
           ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_610.bmp)");
           ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
        //WEB SEMÁNTICO
    case 64:
           ui->Optativa_2->setStyleSheet("border-image: url(:/Images/CCOS_600.bmp)");
           ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
           break;
        //ALMACENAMIENTO DE DATOS
    case 65:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_614.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
        //CONTROL DIGITAL
    case 66:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_613.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
        break;
       //ROBÓTICA APLICADA
    case 67:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;

       //Saul
    case 68:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 69:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 70:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 71:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;
    case 72:
       ui->Optativa_2->setStyleSheet("border-image: url(:/Images/ICCS_617.bmp)");
       ui->Codigo_optativa2->setStyleSheet("border-image: url(:/Images/Palomita.png); background:transparent;");
       break;




    }
}
}
