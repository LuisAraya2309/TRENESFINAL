
#include <iostream>
using namespace std;

class nodoDobleT {
public:
    nodoDobleT(int codTipo, string nombre)
    {
        codTipo= codTipo;
        nombre= nombre;
        siguiente = NULL;
        anterior = NULL;
    }

    nodoDobleT(int codTipo,string nombre, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble)
    {
        codTipo= codTipo;
        nombre= nombre;
        siguiente = signodoDoble;
        anterior = sigantDoble;
    }
private:
	int codTipo;
	string nombre;
    nodoDobleT* siguiente;
    nodoDobleT* anterior;

    friend class listaDT;
};

typedef nodoDobleT* pnodoDobleT;

class listaDT {
public:
    listaDT() { primero = NULL; }
    ~listaDT();

    void InsertarInicio(int codTipo, string nombre);
    void InsertarFinal(int codTipo, string nombre);
    bool ListaVacia() { return primero == NULL; }
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
    if (ListaVacia()) {
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

void listaDT::InsertarInicio(int codTipo, string nombre)
{
    if (ListaVacia()) {
        primero = new nodoDobleT(codTipo, nombre);
    }
    else
    {
        pnodoDobleT aux = primero;
        primero = new nodoDobleT( codTipo,  nombre);
        aux->anterior = primero;
    }

}

void listaDT::InsertarFinal(int codTipo, string nombre)
{
    if (ListaVacia()) {
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
    while (aux) {
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
        cout << "Tipo Tren: " << codTipTren << endl;
        
        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        string nombre = (Todo.substr(0, posPC2));
        cout << "Codigo Tren: " << nombre << endl;
        
	}
	archivoT.close();
}

