#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
struct instrumento {
	int codigo;
	char *nombre = NULL;
	char *laboratorio = NULL;
	char *tipo = NULL;
	char *estado = NULL;
	int costo;
	int semestre;
	char *desck = NULL;
	int horas_a=0;
};
struct usuario {
	int codigo;
	char *nomes=NULL;
	char *programa=NULL;
	int semes;
	int pena_a=0;
	int cont_s =0;
};
struct sesion {
	int codigo;
	int codigo_u;
	int codigo_e;
	int fecha;
	int duracion;
	char *observacion=NULL;
	bool penalisa;
};
void asignarCadena(char*& destino, const char* origen) {
	if (origen == NULL) return;
	destino = new char[strlen(origen) + 1];
	strcpy(destino, origen);
}
void TNT(instrumento *&equipo) {
	int cod_aux;
	char nom_aux[300];
	char lab_aux[300];
	char tipo_aux[300];
	char esta_aux[300];
	int costo_aux;
	int sme_aux;
	char des_aux[300];
	int dan=0;
	int des;
	cout<<"-----------------"<<endl;
	cout<<"|ingresar equipo|"<<endl;
	cout<<"|manual======[1]|"<<endl;
	cout<<"|archivo=====[2]|"<<endl;
	cout<<"-----------------"<<endl;
	cin>>des;
	if(des==1) {
		cout<<"ingrese la cantidad de equipos que va a ingresar"<<endl;
		cin>>dan;
		while(true) {
			if(dan<=0) {
				cout<<"ingrese un numero valido"<<endl;
				cin>>dan;
			}
			else {
				break;
			}
		}
		equipo = new instrumento[dan];
		instrumento* equipos = equipo;
        for(int y=0;y<dan;y++){
        cout<<"ingresa codigo del equipo "<<y+1<<endl;
        cin>>cod_aux;
		equipos->codigo=cod_aux;
		cout<<"ingresa nombre del equipo "<<y+1<<endl;
		cin.ignore();
		cin.getline(nom_aux,300);
		asignarCadena(equipos->nombre,nom_aux);
		cout<<"ingresa laboratorio del equipo "<<y+1<<endl;
		cin.getline(lab_aux,300);
		asignarCadena(equipos->laboratorio,lab_aux);
		cout<<"ingresa tipo de equipo "<<y+1<<endl;
		cin.getline(tipo_aux,300);
		asignarCadena(equipos->tipo,tipo_aux);
		cout<<"ingrese estado del equipo "<<y+1<<endl
		cin.getline(esta_aux,300);
		asignarCadena(equipos->estado,esta_aux);
		cout<<"ingresa costo del equipo "<<y+1<<endl;
        cin>>costo_aux;
		equipos->costo=costo_aux;
		cout<<"ingresa semestre minimo para el equipo "<<y+1<<endl;
        cin>>sme_aux;
		equipos->semestre=sme_aux;
		cout<<"ingresa descripcion del equipo "<<y+1<<endl;
		cin.ignore();
		cin.getline(des_aux,300);
		asignarCadena(equipos->desck,des_aux);
		equipos++;
        }
	}
	else if(des==2) {
		char kirk[30];
		char linea[300];
		cout<<"escribe el nombre de el archivo"<<endl;
		cin.ignore();
		cin.getline(kirk,30);
		ifstream togore(kirk);
		if(!togore) {
			cout<<"error:archivo no existe "<<endl;
			return ;
		}
		else {
			while(togore.getline(linea,300)) {
				dan++;
			}
			equipo = new instrumento[dan];
			instrumento* equipos = equipo;
			togore.clear();              // Restaura el estado del stream (quita la bandera EOF)
			togore.seekg(0, ios::beg);
			//Declaración de variables auxiliares para tokenización
			int opcion=0;
			while(togore.getline(linea,300)) {
				char* token = strtok(linea, "*");
				opcion=0;
				while (token != NULL) {
					switch (opcion) {
					case 0:
						cod_aux=atoi(token);
						break;
					case 1:
						strcpy(nom_aux,token);
						break;
					case 2:
						strcpy(lab_aux,token);
						break;
					case 3:
						strcpy(tipo_aux,token);
						break;
					case 4:
						strcpy(esta_aux,token);
						break;
					case 5:
						costo_aux=atoi(token);
						break;
					case 6:
						sme_aux=atoi(token);
						break;
					case 7:
						strcpy(des_aux,token);
						break;
					}
					token = strtok(NULL, "*");
					opcion++;
				}
				if(opcion!=7||sme_aux==0||costo_aux==0||cod_aux==0) {
					cout<<"error: linea del archivo corrupta"<<endl;
				}
				else {
					equipos->codigo=cod_aux;
					asignarCadena(equipos->nombre,nom_aux);
					asignarCadena(equipos->laboratorio,lab_aux);
					asignarCadena(equipos->tipo,tipo_aux);
					equipos->costo=costo_aux;
					equipos->semestre=sme_aux;
					asignarCadena(equipos->desck,des_aux);
					equipos++;
				}

			}

		}
	}
}

void cierre_sesion (){
	fstream arch_ses("sesiones.bin", ios::binary || ios::app || ios::in || ios::out) //Apertura para escribir en archivo binario Sesiones

	int codigo_ses;
	cout<<"Ingrese el codigo de la sesion a cerrar, por favor"<<endl; //Solicitud de código para buscar coincidencia de la variable Codigo en el archivo y así ubicar el apuntador en la información de la sesión en el archivo binario
	cin>>codigo_ses;
	
	

int main() {
	int D4C;
	instrumento *equipos=NULL;
	usuario *estudiantes=NULL;
	sesion *sesiones=NULL;
	do {
		cout<<"_____________________________________________"<<endl;
		cout<<"|----------MENU DE OPCIONES XD :V-----------|"<<endl;
		cout<<"_____________________________________________"<<endl;
		cout<<"|1: cargar equipos   |   2:cargar usuarios  |"<<endl;
		cout<<"|3: consultar estado |   4:programar sesion |"<<endl;
		cout<<"|5: cerrar sesion    |   6:generar informe  |"<<endl;
		cout<<"|7: rankin critico   |   8 laragate         |"<<endl;
		cout<<"_____________________________________________"<<endl;
		cin>>D4C;
		while(true) {
			if((D4C>8)||(D4C<1)) {
				cout<<"ingresa un dato valido"<<endl;
				cin>>D4C;
			}
			else {
				break;
			}
		}
		TNT(equipos);



	} while(D4C=!8);

}
