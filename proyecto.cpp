#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
struct instrumento {
	int codigo;
	char *nombre = NULL;
	char *laboratorio = NULL;
	char *tipo = NULL;
	char estado[22];
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
	char fecha[11];
	int duracion_r;
	char observacion[300];
	bool abierto;
};
void asignarCadena(char*& destino, const char* origen) {
	if (origen == NULL) return;
	destino = new char[strlen(origen) + 1];
	strcpy(destino, origen);
}
void agregarSesion(sesion *&sesiones, int &cant, sesion nueva) {
	sesion *nuevo = new sesion[cant + 1];
	sesion *orig = sesiones;
	sesion *dest = nuevo;
	for (int i = 0; i < cant; i++) {
		*dest++ = *orig++;
	}
	*dest = nueva;
	delete[] sesiones;
	sesiones = nuevo;
	cant++;
}
int TNT(instrumento *&equipo) {
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
		for(int y=0; y<dan; y++) {
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
			cout<<"ingrese estado del equipo "<<y+1<<endl;
			cin.getline(esta_aux,300);
			strcpy(equipos->estado,esta_aux);
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
		return dan;
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
			return 0;
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
				if(opcion<8||sme_aux==0||costo_aux==0||cod_aux==0) {
					cout<<"error: linea del archivo corrupta"<<endl;
				}
				else {
					equipos->codigo=cod_aux;
					asignarCadena(equipos->nombre,nom_aux);
					asignarCadena(equipos->laboratorio,lab_aux);
					asignarCadena(equipos->tipo,tipo_aux);
					strcpy(equipos->estado, esta_aux);
					equipos->costo=costo_aux;
					equipos->semestre=sme_aux;
					asignarCadena(equipos->desck,des_aux);
					equipos++;
				}

			}

		}
		cout<<"archivo cerrado con exito"<<endl;
		togore.close();
		return dan;
	}
}
int TVT(usuario *&estudiantes) {
	int cod_aux;
	char nom_aux[300];
	char pog_aux[300];
	int sme_aux;
	int dan=0;
	int des;
	cout<<"-------------------"<<endl;
	cout<<"|ingresar usuarios|"<<endl;
	cout<<"|manual========[1]|"<<endl;
	cout<<"|archivo=======[2]|"<<endl;
	cout<<"-------------------"<<endl;
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
		estudiantes = new usuario[dan];
		usuario* usuarios = estudiantes;
		for(int y=0; y<dan; y++) {
			cout<<"ingresa codigo del estudiante "<<y+1<<endl;
			cin>>cod_aux;
			usuarios->codigo=cod_aux;
			cout<<"ingresa nombre del estudiante "<<y+1<<endl;
			cin.ignore();
			cin.getline(nom_aux,300);
			asignarCadena(usuarios->nomes,nom_aux);
			cout<<"ingresa programa del equipo "<<y+1<<endl;
			cin.getline(pog_aux,300);
			asignarCadena(usuarios->programa,pog_aux);
			cout<<"ingresa semestre del estudiante "<<y+1<<endl;
			cin>>sme_aux;
			usuarios->semes=sme_aux;
			usuarios++;
		}
		return dan;
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
			return 0;
		}
		else {
			while(togore.getline(linea,300)) {
				dan++;
			}
			estudiantes = new usuario[dan];
			usuario* usuarios = estudiantes;
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
						strcpy(pog_aux,token);
						break;
					case 3:
						sme_aux=atoi(token);
						break;
					}
					token = strtok(NULL, "*");
					opcion++;
				}
				if(opcion<4||sme_aux==0||cod_aux==0) {
					cout<<"error: linea del archivo corrupta"<<endl;
				}
				else {
					usuarios->codigo=cod_aux;
					asignarCadena(usuarios->nomes,nom_aux);
					asignarCadena(usuarios->programa,pog_aux);
					usuarios->semes=sme_aux;
					usuarios++;
				}

			}

		}
		cout<<"archvio cargado con exito"<<endl;
		togore.close();
		return dan;
	}
}
void TXT (sesion *&sesiones,usuario *&estudiantes,instrumento *&equipo,int &des,int eqe,int usu) {
	int yes;
	char Prestado[17] = " prestado ";
	sesion paso;
	if (estudiantes == nullptr || equipo == nullptr) {
		cout << "error: Cargue primero los archivos de usuarios y equipos." << endl;
		return;
	}
	ofstream chester("datos.bin", ios::binary |ios::app| ios::out);
	if (!chester.is_open()) {
		cout << "Error al abrir el archivo binario." << endl;
		return;
	}
	instrumento *print =equipo;
	for(int u=0; u<eqe; u++) {
		cout<<print->codigo<<"=="<<print->nombre<<" | ";
		if((1+u)%2==0) cout<<endl;
		print++;
	}
	cout<<"ingrese el id del equipo a usar del equipo que quiere usar"<<endl;
	cin>>yes;
	print =equipo;
	for(int g=0; g<eqe; g++) {
		if(yes==print->codigo) {
			cout<<"equipo encontrado"<<endl;
			break;
		}
		else if(g==eqe-1) {
			cout<<"equipo no existe"<<endl;
			return;
		}
		print++;
	}
	usuario *search = estudiantes;
	cout<<"ingrese el id del estudiante"<<endl;
	cin>>yes;
	for(int g=0; g<usu; g++) {
		if(yes==search->codigo) {
			cout<<"usuario encontrado"<<endl;
			break;
		}
		else if(g==usu-1) {
			cout<<"usuario no existe"<<endl;
			return;
		}
		search++;
	}
	if (search->semes<print->semestre) {
		cout<<"el estudiante no cuenta con los semestre requeridos"<<endl;
		return;
	}
	if (strcmp(print->estado, " mantenimiento ") == 0 || strcmp(print->estado, " fuera de servicio ") == 0) {
		cout << "El equipo no se puede usar." << endl;
		cout << "Estado actual: " << print->estado << endl;
		return;
	}
	cout<<"sesion aprobada"<<endl;
	paso.codigo=des;
	paso.codigo_u=search->codigo;
	paso.codigo_e=print->codigo;
	cout<<"ingrese la fecha de la sesion"<<endl;
	cin.ignore();
	cin.getline(paso.fecha,11);
	cout<<"ingrese el tiempo de uso (en horas)"<<endl;
	cin>>paso.duracion_r;
	paso.abierto=true;
	agregarSesion(sesiones,des,paso);
	chester.write(reinterpret_cast<const char*>(&paso), sizeof(sesion));
    strcpy(print->estado,Prestado);
	chester.close();
	cout << "Sesion registrada exitosamente en datos.bin" << endl;

}
void TFT(sesion *&sesiones,usuario *&estudiantes,instrumento *&equipo,int des,int eqe,int usu) {
    char Operativo[17]    = " operativa ";
    char Mantenimiento[17] = " mantenimiento ";
    char FueraServicio[22] = " fuera de servicio ";
	int hora;
	int moon;
	int spamnton;
	usuario *wake=estudiantes;
	instrumento *golden=equipo;
	sesion *full=sesiones;
	if(sesiones == nullptr) {
		cout<<"no existen sesiones registradas"<<endl;
	}
	cout<<"ingresa numero de la sesion a cerrar: "<<endl;
	cin>>moon;
	for(int y=0; y<des; y++) {
		if(moon==full->codigo) {
			cout<<"sesion encontrada"<<endl;
			break;
		}
		else if(y==des-1) {
			cout<<"la sesion no existe"<<endl;
			return;
		}
		full++;
	}
	if (full->abierto==false) {
		cout<<"la sesion ya fue cerrada"<<endl;
		return;
	}
		for(int g=0; g<eqe; g++) {
		if(full->codigo_e==golden->codigo) {
			break;
		}
		else if(g==eqe-1) {
			return;
		}
		golden++;
	}
	cout<<"ingrese el timepo final de la sesion"<<endl;
	cin>>hora;
	if(full->duracion_r<hora) {
		cout<<"se le sera aplicada una sancion por ecceso de tiempo"<<endl;
		for(int g=0; g<usu; g++) {
			if(full->codigo_u==wake->codigo) {
				break;
			}
			else if(g==usu-1) {
				return;
			}
			wake++;
		}
		int spike = hora-full->duracion_r;
		int pena=(golden->costo*0.03)*spike;
		cout<<"tu penalizacion sera de "<<pena<<endl;
		wake->pena_a=pena;
		
	}
	full->abierto = false;
	wake->cont_s+=1;
	cout<<"el equipo sufrio alguna daño?"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"|ninguno==============[1]|"<<endl;
	cout<<"|mantenimiento========[2]|"<<endl;
	cout<<"|salida de servivio===[3]|"<<endl;
	cout<<"--------------------------"<<endl;
	cin>>spamnton;
	while(true) {
			if((spamnton>3)||(spamnton<1)) {
				cout<<"ingresa un dato valido"<<endl;
				cin>>spamnton;
			}
			else {
				break;
			}
		}
	switch (spamnton){
	    case 1:
	    cout<<"equipo operativo"<<endl;
	    strcpy(golden->estado,Operativo);
	    break;
	    case 2:
	    cout<<"equipo para mantenimiento"<<endl;
	    strcpy(golden->estado,Mantenimiento);
	    break;
	    case 3:
	    cout<<"equipo queda fuera de servicio"<<endl;
	    strcpy(golden->estado,FueraServicio);
	    break;
	}
	cout<<"escriba sus observaciones de la sesion"<<endl;
	cin.ignore();
	cin.getline(full->observacion,300);
	fstream deltarune("datos.bin", ios::binary | ios::in | ios::out);
    if (!deltarune.is_open()) {
        cout << "Error al abrir datos.bin para actualizacion." << endl;
        return;
    }
    streampos desplazamiento = (full - sesiones) * sizeof(sesion);
    deltarune.seekp(desplazamiento);
    deltarune.write(reinterpret_cast<const char*>(full), sizeof(sesion));
    deltarune.close();
    cout << "Sesion #" << moon << " actualizada exitosamente en el archivo binario." << endl;
}



int main() {
	int D4C;
	int eqe;
	int usu;
	int marca=0;
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
		cout<<"|7: rankin critico   |   8:salir            |"<<endl;
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
		switch (D4C) {
		case 1:
			eqe=TNT(equipos);
			break;
		case 2:
			usu=TVT(estudiantes);
			break;
		case 4:
			TXT(sesiones,estudiantes,equipos,marca,eqe,usu);
			break;
		case 5:
			TFT(sesiones,estudiantes,equipos,marca,eqe,usu);
			break;
		}

	} while(D4C!=8);

}
