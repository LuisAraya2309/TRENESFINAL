
#include <iostream>
#include "Trenes.hpp"
using namespace std;
class nodoDobleT {
public:
    nodoDobleT(int codigoc, string cnombre)
    {
    	codTren= codigoc;
        nombre= cnombre;
        siguiente = NULL;
        anterior = NULL;
        listaDeTrenes = listaTrenes();
    }

    nodoDobleT(int codigoc ,string cnombre, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble)
    {
    	codTren= codigoc;
        nombre= cnombre;
        siguiente = signodoDoble;
        anterior = sigantDoble;
    }
private:
	int codTren;
	string nombre;
    nodoDobleT* siguiente;
    nodoDobleT* anterior;
    listaTrenes listaDeTrenes;
    friend class listaDT;
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

