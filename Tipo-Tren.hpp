
#include <iostream>
#include "Trenes.hpp"
#include "Rutas.hpp"
#pragma once
using namespace std;
class nodoDobleT {
public:
    nodoDobleT(int codigoc, string cnombre)
    {
    	codTren= codigoc;
        nombre= cnombre;
        siguiente = NULL;
        anterior = NULL;
        tren = NULL;
        listaDeTrenes = listaTrenes();
        listaCodRutas = lista();
    }

    nodoDobleT(int codigoc ,string cnombre, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble)
    {
    	codTren= codigoc;
        nombre= cnombre;
        siguiente = signodoDoble;
        anterior = sigantDoble;
        listaDeTrenes = listaTrenes();
    }
public:
	int codTren;
	string nombre;
	lista listaCodRutas;
    nodoDobleT* siguiente;
    nodoDobleT* anterior;
    nodoDobleT* tren;
    listaTrenes listaDeTrenes;
    
    friend class listaDT;
    friend class listaTrenes;
    friend class nodoSimpTrenes;
};

typedef nodoDobleT* pnodoDobleT;

class listaDT {
public:
    listaDT() { primero = NULL; }
    ~listaDT();

    void InsertarInicioDT(int v, string nombre);
    void InsertarFinalDT(int codTipo, string nombre);
    bool ListaVaciaDT() { return primero == NULL; }
    void Mostrar();
    int largoLista();
    void llenarListaTipotrenes();
    void llenarListaTrenes();
    void llenarListaCodRutas();
    void InsertarTipoTren();
    void MostrarUnTipoDeTren();
    void ConsultarAsientos();
    void ModificarNumAsientos();
    void RegistrarTren();
    void ModificarTren();
    void llenarListaRutas(listaDC paises);
    pnodoDobleT primero;

};

listaDT::~listaDT()
{
    pnodoDobleT aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaDT::largoLista() {
    int cont = 0;

    pnodoDobleT aux;
    aux = primero;
    if (ListaVaciaDT()) {
        return cont;
    }
    else {
        while (aux != NULL) {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDT::InsertarInicioDT(int v,string nombre)
{
   if (ListaVaciaDT())
   {
   
     primero = new nodoDobleT(v,nombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoDobleT (v,nombre);
     primero->siguiente->anterior=primero;
   }
}
 

void listaDT::InsertarFinalDT(int codTipo, string nombre)
{
    if (ListaVaciaDT()) {
        primero = new nodoDobleT( codTipo,  nombre);
    }
    else
    {
        pnodoDobleT aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        pnodoDobleT nuevo = new nodoDobleT( codTipo,  nombre);
        aux->siguiente = nuevo;
        nuevo->anterior = aux;

    }
}
void listaDT::Mostrar()
{
    nodoDobleT* aux;

    aux = primero;
    while (aux!=NULL) {
    	cout<<"CodTipTren : "<<aux->codTren;
    	cout<<"  Nombre de Tren : "<<aux->nombre<<endl;
        aux = aux->siguiente;
    }
    cout << endl;
}

void listaDT::llenarListaTipotrenes(){
	ifstream archivoT;
    string texto;
    archivoT.open("TipoTren.txt", ios::in);
    if (archivoT.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivoT.eof()) {
        getline(archivoT, texto);
        
        int posPC = texto.find(";");
        int codTipTren = atoi(texto.substr(0, posPC).c_str());
        
        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        string nombre = (Todo.substr(0, posPC2));
        
        if(ListaVaciaDT()){
        	//cout<<"Lista Vacia"<<endl;
        	InsertarInicioDT(codTipTren,nombre);
		}
		else{
			pnodoDobleT trenAux = primero;bool existeTren = false;
			while(trenAux!=NULL){
				if(trenAux->codTren==codTipTren){
					existeTren= true;
					break;
				}else{
					trenAux=trenAux->siguiente;
				}
			}if(!existeTren){
				InsertarFinalDT(codTipTren,nombre);
			}
		}
	}
	archivoT.close();
}
void listaDT::llenarListaTrenes(){
	ifstream archivoT;
    string texto;
    archivoT.open("Trenes.txt", ios::in);
    if (archivoT.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivoT.eof()) {
        getline(archivoT, texto);
        
        int posPC = texto.find(";");
        int codTipTren = atoi(texto.substr(0, posPC).c_str());
        cout << "Tipo Tren: " << codTipTren << endl;
        
        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        int codTren = atoi(Todo.substr(0, posPC2).c_str());
        cout << "Codigo Tren: " << codTren << endl;

        string Todo2 = Todo.substr(posPC2 + 1, Todo.length());
        int posPC3 = Todo2.find(";");
        string nomTren = (Todo2.substr(0, posPC3));
        cout << "Tren: " << nomTren << endl;
        
        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length());
        int posPC4 = Todo3.find(";");
        int numAsientos = atoi((Todo3.substr(0, posPC4).c_str()));
        cout << "Numero de asientos: " << numAsientos << endl;
        
        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length());
        int posPC5 = Todo4.find(";");
        int ruta = atoi((Todo4.substr(0, posPC5).c_str()));
        cout << "Rutas:  " << ruta << endl;      
        //Buscamos que el tipo de tren exista
        pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false;
        while(tiposTrenes!=NULL){
        	if(tiposTrenes->codTren==codTipTren){
        		existeTipoTren = true;
        		break;
			}
			else{
				tiposTrenes=tiposTrenes->siguiente;
			}
		}
		if(existeTipoTren){
			if(tiposTrenes->listaDeTrenes.primero==NULL){
				tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos,ruta);
				cout<<"Lista de Trenes1: "<<endl;
				tiposTrenes->listaDeTrenes.Mostrar();
				cout<<endl;
				cout<<endl;
			}
			else{
				pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false;
				while(buscarCod!=NULL){
					if(buscarCod->codTren==codTren){
						codRepetido = true;
						break;
					}
					else{
						buscarCod=buscarCod->siguiente;
					}
				}
				if(!codRepetido){
					tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos,ruta);
					cout<<"Lista de Trenes2: "<<endl;
					tiposTrenes->listaDeTrenes.Mostrar();
					cout<<endl;
					cout<<endl;
				}
				else{
					// por si el codigo esta repetido
					continue;
				}
			}
		}
		else{
			// por si no existe el tipo de tren
			continue;
		}
        
	}
	//llave del while del archivo
	archivoT.close();
}
void listaDT::llenarListaCodRutas(){
	ifstream archivoR;
    string texto;
    archivoR.open("Rutas.txt", ios::in);
    if (archivoR.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivoR.eof()) {
        getline(archivoR, texto);
        
        int posPC = texto.find(";");
        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        string Todo2 = Todo.substr(posPC2 + 1, Todo.length());
        int posPC3 = Todo2.find(";");
        int codRuta = atoi((Todo2.substr(0, posPC3).c_str()));
        cout << "Codigo Ruta: " << codRuta << endl;
        
        
	}
	archivoR.close();
}
void listaDT::InsertarTipoTren(){
	int codNuevo;string nombreNuevo;
	cout<<"Ingrese el codigo del nuevo tipo de tren: "<<endl;
	cin>>codNuevo;
	cout<<"Ingrese el nombre del nuevo tipo de tren: "<<endl;
	cin>>nombreNuevo;
	pnodoDobleT verificar = primero;bool codRepetido = false;
	while(verificar!=NULL){
		if(verificar->codTren==codNuevo){
			codRepetido = true;
			break;
		}
		else{
			verificar=verificar->siguiente;
		}
	}
	if(!codRepetido){
		InsertarFinalDT(codNuevo,nombreNuevo);
		cout<<"Nuevo tipo de tren agregado con exito."<<endl;
	}
	else{
		cout<<"No se pudo ingresar el nuevo tipo de tren."<<endl;
		cout<<"Este mismo se encuentra repetido. Recuerde usar caracteres numericos solamente."<<endl;
	}
}
void listaDT::MostrarUnTipoDeTren(){
	int codTipTren;
	cout<<"Ingrese el codigo del tipo de tren para mostrar todos los trenes de ese tipo."<<endl;
	cin>>codTipTren;
	pnodoDobleT mostrar = primero;bool existeTipTren = false;
	while(mostrar!=NULL){
		if(mostrar->codTren==codTipTren){
			existeTipTren = true;
			break;
		}
		else{
			mostrar=mostrar->siguiente;
		}
	}
	if(existeTipTren){
		if(mostrar->listaDeTrenes.ListaVacia()){
			cout<<"No hay trenes registrados de ese tipo."<<endl;
		}
		else{
			mostrar->listaDeTrenes.Mostrar();
		}
	}
	else{
		cout<<"El codigo ingresado no corresponde a ningun tipo de tren."<<endl;
	}
}

void listaDT::ConsultarAsientos(){
	int codTipTren;
	int codTren;
	cout<<"Ingrese el codigo del tipo de tren para mostrar los trenes de ese tipo."<<endl;
	cin>>codTipTren;
	cout<<"Ingrese el codigo del tren para mostrar los asientos disponibles."<<endl;
	cin>>codTren;
	pnodoDobleT mostrar = primero;bool existeTipTren = false;
	while(mostrar!=NULL){
		if(mostrar->codTren==codTipTren){
			existeTipTren = true;
			break;
		}
		else{
			mostrar=mostrar->siguiente;
		}
	}
	if(existeTipTren){	
	pnodoSimpTrenes buscarCod = mostrar->listaDeTrenes.primero;bool codRepetido = false;
		while(buscarCod!=NULL){
			if(buscarCod->codTren==codTren){
				cout<<"Se dispone de "<<buscarCod->numAsientos<<" asientos disponibles."<<endl;
				codRepetido=true;
				break;
			}
			else{
				buscarCod=buscarCod->siguiente;
			}
		}if(!codRepetido){
			cout<<"El codigo de Tren digitado es incorrecto"<<endl;
		}
	}else{
		cout<<"El codigo del tipo de tren no existe"<<endl;
	}
}

void listaDT::ModificarNumAsientos(){
		int codTipTren;
		int codTren;
		int numAsientos;
		cout<<"Ingrese el codigo del tipo de tren ."<<endl;
		cin>>codTipTren;
		cout<<"Ingrese el codigo de tren."<<endl;
		cin>>codTren;
		cout<<"Ingrese la nueva cantidad de asientos disponibles."<<endl;
		cin>>numAsientos;
		pnodoDobleT mostrar = primero;bool existeTipTren = false;
		while(mostrar!=NULL){
			if(mostrar->codTren==codTipTren){
				existeTipTren = true;
				break;
			}
			else{
				mostrar=mostrar->siguiente;
			}
		}
		if(existeTipTren){	
		pnodoSimpTrenes buscarCod = mostrar->listaDeTrenes.primero;bool codRepetido = false;
			while(buscarCod!=NULL){
				if(buscarCod->codTren==codTren){
					buscarCod->numAsientos=numAsientos;
					cout<<"Se actualizaron la cantidad de trenes a "<<buscarCod->numAsientos<<" asientos disponibles."<<endl;
					codRepetido=true;
					break;
				}
				else{
					buscarCod=buscarCod->siguiente;
				}
			}if(!codRepetido){
				cout<<"El codigo de Tren digitado es incorrecto"<<endl;
			}
		}else{
			cout<<"El codigo del tipo de tren no existe"<<endl;
		}
}

void listaDT::RegistrarTren(){
		int codTipTren;
		int codTren;
		string nomTren;
		int numAsientos;
		int ruta;
		cout<<"Ingrese el codigo del tipo de tren ."<<endl;
		cin>>codTipTren;
		cout<<"Ingrese el codigo de tren."<<endl;
		cin>>codTren;
		cout<<"Ingrese el nombre del tren."<<endl;
		cin>>nomTren;
		cout<<"Ingrese la cantidad de asientos."<<endl;
		cin>>numAsientos;
		cout<<"Ingrese las posibles rutas."<<endl;
		cin>>ruta;
		pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false;
        while(tiposTrenes!=NULL){
        	if(tiposTrenes->codTren==codTipTren){
        		existeTipoTren = true;
        		break;
			}
			else{
				tiposTrenes=tiposTrenes->siguiente;
			}
		}
		if(existeTipoTren){
			if(tiposTrenes->listaDeTrenes.primero==NULL){
				tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos,ruta);
				cout<<"La lista de Trenes fue registrada con exito "<<endl;
				cout<<endl;
			}
			else{
				pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false;
				while(buscarCod!=NULL){
					if(buscarCod->codTren==codTren){
						codRepetido = true;
						break;
					}
					else{
						buscarCod=buscarCod->siguiente;
					}
				}
				if(!codRepetido){
					tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos,ruta);
					cout<<"La lista de Trenes fue registrada con exito "<<endl;
					cout<<endl;
				}
				else{
					// por si el codigo esta repetido
					cout<<"El codigo del tren ya existe"<<endl;
				}
			}
		}
		else{
			cout<<"El codigo de tipo de tren no existe"<<endl;
			// por si no existe el tipo de tren
		}
	}	

void listaDT:: ModificarTren(){
	int codTipTren;cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl;
	int codTren; cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl;
	string nuevoNomTren; cout<<"Ingrese el nuevo nombre de tren: "; cin>>nuevoNomTren; cout<<endl;
	int nuevoAsientos; cout<<"Ingrese la nueva cantidad de asientos: "; cin>>nuevoAsientos; cout<<endl;
	int rutas;cout<<"Ingrese la ruta del tren: "; cin>>rutas; cout<<endl;
	pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false;
        while(tiposTrenes!=NULL){
        	if(tiposTrenes->codTren==codTipTren){
        		existeTipoTren = true;
        		break;
			}
			else{
				tiposTrenes=tiposTrenes->siguiente;
			}
		}
		if(existeTipoTren){
			pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false;
			while(buscarCod!=NULL){
				if(buscarCod->codTren==codTren){
					codRepetido = true;
					break;
				}else{
					buscarCod=buscarCod->siguiente;
				}
			}if(buscarCod->codTren==codTren){
				codRepetido= true;
				if(codRepetido){
					 buscarCod->nombre=nuevoNomTren;
					 buscarCod->numAsientos= nuevoAsientos;
					 buscarCod->rutasP= rutas;
					 cout<<"El tren fue modificado correctamente"<<endl;	
				}else{
					cout<<"El codigo de tren no existe"<<endl;
				}
		}else{
			cout<<"El codigo del tipo de tren ingresado no existe"<<endl;
		}
	}
}

void listaDT::llenarListaRutas(listaDC paises) {
    ifstream archivo2;
    string texto;
    listaC listaRutas;
    archivo2.open("Rutas.txt", ios::in);
    if (archivo2.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo2.eof()) {
    	
        getline(archivo2, texto);
        cout<<"TEXTO PUTO"<<texto<<endl;
		
        int posPC = texto.find(";");
        int codTipTren = atoi(texto.substr(0, posPC).c_str());
        //cout << "Tipo Tren: " << codTipTren << endl;
        
        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        int codTren = atoi(Todo.substr(0, posPC2).c_str());
        //cout << "Codigo Tren: " << codTren << endl;

        string Todo2 = Todo.substr(posPC2 + 1, Todo.length());
        int posPC3 = Todo2.find(";");
        int codRuta = atoi((Todo2.substr(0, posPC3).c_str()));
        //cout << "Codigo Ruta: " << codRuta << endl;

        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length());
        int posPC4 = Todo3.find(";");
        int codPais = atoi((Todo3.substr(0, posPC4).c_str()));
        //cout << "Codigo Pais: " << codPais << endl;

        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length());
        int posPC5 = Todo4.find(";");
        int codCiudad = atoi((Todo4.substr(0, posPC5).c_str()));
        //cout << "Codigo Ciudad: " << codCiudad << endl;

        string Todo5 = Todo4.substr(posPC5 + 1, Todo4.length());
        int posPC6 = Todo5.find(";");
        int codPais2 = atoi((Todo5.substr(0, posPC6).c_str()));
        //cout << "Codigo Pais: " << codPais2 << endl;

        string Todo6 = Todo5.substr(posPC6 + 1, Todo5.length());
        int posPC7 = Todo6.find(";");
        int codCiudad2 = atoi((Todo6.substr(0, posPC7).c_str()));
       // cout << "Codigo Ciudad: " << codCiudad2 << endl;

        string Todo7 = Todo6.substr(posPC7 + 1, Todo6.length());
        int posPC8 = Todo7.find(";");
        int codPrecio = atoi((Todo7.substr(0, posPC8).c_str()));
        //cout << "Precio: " << codPrecio << endl;
        
        pnodoDobleT buscarTipTren =  primero;bool existeTipTren = false;
        while(buscarTipTren!=NULL){
        	if(buscarTipTren->codTren == codTipTren){
        		existeTipTren = true;
        		break;
			}
			else{
				buscarTipTren = buscarTipTren->siguiente;
			}
		}
		if(existeTipTren){
			pnodoSimpTrenes buscarTren = buscarTipTren->listaDeTrenes.primero;bool existeTren = false;
			while(buscarTren!=NULL){
				if(buscarTren->codTren==codTren){
					existeTren = true;
					break;
				}
				else{
					buscarTren = buscarTren->siguiente;
				}
			}
			if(existeTren){
				pnodo buscarPais = paises.primero; bool existePais1 = false;
				while(buscarPais->siguiente != paises.primero ){
					if(buscarPais->valor==codPais){
						existePais1 = true;
						break;
					}
					else{
						buscarPais = buscarPais->siguiente;
					}
				}
				if(buscarPais->valor == codPais){
					existePais1 = true;
				}
				if(existePais1){
					pnodo buscarCiudad1 = buscarPais->ciudad; bool existeCiudad1 = false;
					while(buscarCiudad1->ciudad != buscarPais ){
						if(buscarCiudad1->valor==codCiudad){
							existeCiudad1 = true;
							break;
						}
						else{
							buscarCiudad1 = buscarCiudad1->ciudad;
						}
					}
					if(buscarCiudad1->valor == codCiudad){
						existeCiudad1 = true;
					}
					if(existeCiudad1){
						pnodo buscarPais2 = paises.primero; bool existePais2 = false;
						while(buscarPais2->siguiente != paises.primero ){
							if(buscarPais2->valor==codPais2){
								existePais2 = true;
								break;
							}
							else{
								buscarPais2 = buscarPais2->siguiente;
							}
						}
						if(buscarPais2->valor == codPais){
							existePais2 = true;
						}
						if(existePais2){
							pnodo buscarCiudad2 = buscarPais2->ciudad; bool existeCiudad2 = false;
							while(buscarCiudad2->ciudad != buscarPais2 ){
								if(buscarCiudad2->valor==codCiudad2){
									existeCiudad2 = true;
									break;
								}
								else{
									buscarCiudad2 = buscarCiudad2->ciudad;
								}
							}
							if(buscarCiudad2->valor == codCiudad2){
								existeCiudad2 = true;
							}
							if(existeCiudad2){
								if(listaRutas.ListaVacia()){
									listaRutas.InsertarInicio(codTipTren,codTren,codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);
									listaRutas.Mostrar();
								}
								else{
									pnodoCir buscarRuta = listaRutas.primero;bool existeRuta = false;
									while(buscarRuta->siguiente!=primero){
										if(buscarRuta->codRutas==codRuta){
											existeRuta = true;
										}
										else{
											buscarRuta=buscarRuta->siguiente;
										}
									}
									if(buscarRuta->codRutas==codRuta){
										existeRuta = true;
									}
									if(!existeRuta){
										listaRutas.InsertarFinal(codTipTren,codTren,codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);
										listaRutas.Mostrar();
									}
								}
							}
							else{
								//por si no existe la ciudad 2
								continue;
							}
						}
						else{
							//por si no existe el pais 2
							continue;
						}	
					}
					else{
						//por si no existe ciudad 1
						continue;
					}
				}
				else{
					//no existe Pais 1
					continue;
				}
			}
			else{
				//por si no existe el tren
				continue;
			}
		}
		else{
			//por si no existe el tipo de tren
			continue;
		}
     
    }
    archivo2.close();
}	
