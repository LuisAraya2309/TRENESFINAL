
#include <iostream>
using namespace std;

class nodoDoble {
public:
    nodoDoble(int codConexion,int codPais,int codCiudad,int tiempo)
    {
        codConexion = codConexion;
        codPais = codPais;
        codCiudad = codCiudad;
        tiempo = tiempo;
        siguiente = NULL;
        anterior = NULL;
    }

    nodoDoble(int codConexion, int codPais, int codCiudad, int tiempo, nodoDoble* signodoDoble, nodoDoble* sigantDoble)
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
    nodoDoble* siguiente;
    nodoDoble* anterior;

    friend class listaD;
};

typedef nodoDoble* pnodoDoble;

class listaD {
public:
    listaD() { primero = NULL; }
    ~listaD();

    void InsertarInicio(int codConexion, int codPais, int codCiudad, int tiempo);
    void InsertarFinal(int codConexion, int codPais, int codCiudad, int tiempo);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    int largoLista();
    pnodoDoble primero;

};

listaD::~listaD()
{
    pnodoDoble aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaD::largoLista() {
    int cont = 0;

    pnodoDoble aux;
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

void listaD::InsertarInicio(int codConexion, int codPais, int codCiudad, int tiempo)
{
    if (ListaVacia()) {
        primero = new nodoDoble(codConexion, codPais, codCiudad, tiempo);
    }
    else
    {
        pnodoDoble aux = primero;
        primero = new nodoDoble(codConexion, codPais, codCiudad, tiempo);
        aux->anterior = primero;
    }

}

void listaD::InsertarFinal(int codConexion, int codPais, int codCiudad, int tiempo)
{
    if (ListaVacia()) {
        primero = new nodoDoble(codConexion, codPais, codCiudad, tiempo);
    }
    else
    {
        pnodoDoble aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        pnodoDoble nuevo = new nodoDoble(codConexion, codPais, codCiudad, tiempo);
        aux->siguiente = nuevo;
        nuevo->anterior = aux;

    }
}
void listaD::Mostrar()
{
    nodoDoble* aux;

    aux = primero;
    while (aux) {
        cout << aux->codConexion << "-" << aux->codPais << "-" << aux->codCiudad << aux->tiempo << "->";
        aux = aux->siguiente;
    }
    cout << endl;
}

