
#include <iostream>
#include "Trenes.hpp"
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

    nodoDobleT(int codigoc ,string cnombre, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble,nodoDobleT* sigTren)
    {
    	codTren= codigoc;
        nombre= cnombre;
        siguiente = signodoDoble;
        anterior = sigantDoble;
        tren = sigTren;
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

