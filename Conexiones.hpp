
#include <iostream>
using namespace std;
#pragma once

class nodoDoble {
public:
    nodoDoble(int Conexionc,int Paisc,int Ciudadc,int tiempoc)
    {
        codConexion = Conexionc;
        codPais = Paisc;
        codCiudad = Ciudadc;
        tiempo = tiempoc;
        siguiente = NULL;
        anterior = NULL;
    }

    nodoDoble(int Conexionc, int Paisc, int Ciudadc, int tiempoc, nodoDoble* signodoDoble, nodoDoble* sigantDoble)
    {
        codConexion = Conexionc;
        codPais = Paisc;
        codCiudad = Ciudadc;
        tiempo = tiempoc;
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
    friend class listaDC;
};

typedef nodoDoble* pnodoDoble;

class listaD {
public:
    listaD() { primero = NULL; }
    ~listaD();

    void InsertarInicioD(int codConexion, int codPais, int codCiudad, int tiempo);
    void InsertarFinalD(int codConexion, int codPais, int codCiudad, int tiempo);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    int largoLista();
    
public:
    pnodoDoble primero;
    
    friend class listaDC;

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

void listaD::InsertarInicioD(int codConexion, int codPais, int codCiudad, int tiempo)
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

void listaD::InsertarFinalD(int codConexion, int codPais, int codCiudad, int tiempo)
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
    while (aux!=NULL) {
        cout << aux->codConexion << "-" << aux->codPais << "-" << aux->codCiudad <<"-"<< aux->tiempo << "->";
        aux = aux->siguiente;
    }
    cout << endl;
}

