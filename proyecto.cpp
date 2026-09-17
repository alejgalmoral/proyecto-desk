#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
struct instrumento {
	int codigo;
	char *nombre = NULL;
	char *laboratorio = NULL;
	char *tipo = NULL;
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
			if(dan=<0) {
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
        cout
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
	else if(des==2) {
		char kirk[30];
		char linea[300];
		cout<<"mira bien hijo de tu puta madre, dame el nombre de el archivo"<<endl;
		cin.ignore();
		cin.getline(kirk,30);
		ifstream togore(kirk);
		if(!togore) {
			cout<<"puto idiota tu archivo no existe (como tu relacion)"<<endl;
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
					cout<<"error en linea del archivo!!"<<endl;
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
		cout<<"|7: rankin critico   |   8 laragate hdp     |"<<endl;
		cout<<"_____________________________________________"<<endl;
		cin>>D4C;
		while(true) {
			if((D4C>8)||(D4C<1)) {
				cout<<"escribe bien imbecil"<<endl;
				cin>>D4C;
			}
			else {
				break;
			}
		}
		TNT(equipos);



	} while(D4C=!8);

}
