
#include <iostream>
using namespace std;

class nodoDobleT {
public:
    nodoDobleT(int codConexion, int codPais, int codCiudad, int tiempo)
    {
        codConexion = codConexion;
        codPais = codPais;
        codCiudad = codCiudad;
        tiempo = tiempo;
        siguiente = NULL;
        anterior = NULL;
    }

    nodoDobleT(int codConexion, int codPais, int codCiudad, int tiempo, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble)
    {
        codConexion = codConexion;
        codPais = codPais;
        codCiudad = codCiudad;
        tiempo = tiempo;
        siguiente = signodoDoble;
        anterior = sigantDoble;
    }
private:
    int codConexion;
    int codPais;
    int codCiudad;
    int tiempo;
    nodoDobleT* siguiente;
    nodoDobleT* anterior;

    friend class listaDT;
};

typedef nodoDobleT* pnodoDobleT;

class listaDT {
public:
    listaDT() { primero = NULL; }
    ~listaDT();

    void InsertarInicio(int codConexion, int codPais, int codCiudad, int tiempo);
    void InsertarFinal(int codConexion, int codPais, int codCiudad, int tiempo);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    int largoLista();
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

void listaDT::InsertarInicio(int codConexion, int codPais, int codCiudad, int tiempo)
{
    if (ListaVacia()) {
        primero = new nodoDobleT(codConexion, codPais, codCiudad, tiempo);
    }
    else
    {
        pnodoDobleT aux = primero;
        primero = new nodoDobleT(codConexion, codPais, codCiudad, tiempo);
        aux->anterior = primero;
    }

}

void listaDT::InsertarFinal(int codConexion, int codPais, int codCiudad, int tiempo)
{
    if (ListaVacia()) {
        primero = new nodoDobleT(codConexion, codPais, codCiudad, tiempo);
    }
    else
    {
        pnodoDobleT aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        pnodoDobleT nuevo = new nodoDobleT(codConexion, codPais, codCiudad, tiempo);
        aux->siguiente = nuevo;
        nuevo->anterior = aux;

    }
}
void listaDT::Mostrar()
{
    nodoDobleT* aux;

    aux = primero;
    while (aux) {
        cout << aux->codConexion << "-" << aux->codPais << "-" << aux->codCiudad << aux->tiempo << "->";
        aux = aux->siguiente;
    }
    cout << endl;
}

