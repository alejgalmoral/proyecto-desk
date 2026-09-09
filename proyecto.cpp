#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
struct instrumento{
    int codigo;
    char *nombre = NULL;
    char *laboratorio = NULL;
    char *tipo = NULL;
    int costo;
    int semestre;
    char *desck = NULL;
    int horas_a=0;
};
struct usuario{
    int codigo;
    char *nomes=NULL;
    char *programa=NULL;
    int semes;
    int pena_a=0;
    int cont_s =0;
};
struct sesion{
  int codigo;
  int codigo_u;
  int codigo_e;
  int fecha;
  int duracion;
  char *observacion=NULL;
  bool penalisa;
};
void TNT(instrumento *equipos){
   char kirk[30];
   cout<<"mira bien hijo de tu puta madre, dame el nombre de el archivo"<<endl;
   cin.ignore();
   cin.getline(kirk,30);
   ifstream kris
    
    
}




int main(){
    int D4C;
    instrumento *equipos=NULL;
    usuario *estudiantes=NULL;
    sesion *sesiones=NULL;
    do{
    cout<<"_____________________________________________"<<endl;
    cout<<"|----------MENU DE OPCIONES XD :V-----------|"<<endl;
    cout<<"_____________________________________________"<<endl;
    cout<<"|1: cargar equipos   |   2:cargar usuarios  |"<<endl;
    cout<<"|3: consultar estado |   4:programar sesion |"<<endl;
    cout<<"|5: cerrar sesion    |   6:generar informe  |"<<endl;
    cout<<"|7: rankin critico   |   8 laragate hdp     |"<<endl;
    cout<<"_____________________________________________"<<endl;
    cin>>D4C;
    while(true){
        if((D4C>8)||(D4C<1)){
            cout<<"escribe bien imbecil"<<endl;
            cin>>D4C;
        }
        else{
            break;
        }
    }
     
        
        
        
    }while(D4C=!8);
    
}
