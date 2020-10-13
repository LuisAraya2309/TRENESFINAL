#include <iostream>
using namespace std;
#pragma once
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar
class nodoSimpTrenes { //clase NODO

public:
    nodoSimpTrenes(int cTren, string cnomTren,int cnumAsientos, int crutasP) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
        codTren=cTren;
        nombre= cnomTren;
        numAsientos= cnumAsientos;
        rutasP= crutasP;
        siguiente = NULL;
        listaRutas= lista();
    }

    nodoSimpTrenes(int cTren, string cnomTren,int cnumAsientos, int crutasP, nodoSimpTrenes* signodo) // 2 dirprimero direccion de memoria
    {
        codTren=cTren;
        nombre= cnomTren;
        numAsientos= cnumAsientos;
        rutasP= crutasP;
        siguiente = signodo;//primero
    }

public: // atributos
    int codTren;
    string nombre;
    int numAsientos;
    int rutasP;
    lista listaRutas;
	nodoSimpTrenes* siguiente; // tipo de la clase, clase autoreferencia. Direccion 

    friend class listaTrenes; // telefono, son amigas lista con la clase. Solo los metodos, constructores
    friend class listaDT;
    friend class nodoDobleT;

};
typedef nodoSimpTrenes* pnodoSimpTrenes; //alias redefinir los punteros

class listaTrenes {
public:
    listaTrenes()
    {
        primero = NULL;

    }
    ~listaTrenes();
    void InsertarInicio(int codTren, string nomTren,int numAsientos, int rutasP);
    void InsertarFinal(int codTren, string nomTren,int numAsientos, int rutasP);
    void InsertarPos(int codTren, string nomTren,int numAsientos, int rutasP, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

public:
    pnodoSimpTrenes primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo

};

listaTrenes::~listaTrenes() //Destructor
{
    pnodoSimpTrenes aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaTrenes::largoLista() { //largo
    int cont = 0;

    pnodoSimpTrenes aux; //nodo *aux;
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

void listaTrenes::InsertarInicio(int codTren, string nomTren,int numAsientos, int rutasP)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTren,  nomTren, numAsientos,  rutasP);
    else
        primero = new nodoSimpTrenes( codTren,  nomTren, numAsientos,  rutasP, primero);
}

void listaTrenes::InsertarFinal( int codTren, string nomTren,int numAsientos, int rutasP)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTren,  nomTren, numAsientos,  rutasP);
    else
    {
        pnodoSimpTrenes aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = new nodoSimpTrenes(   codTren,  nomTren, numAsientos,  rutasP);
    }
}

void listaTrenes::InsertarPos(int codTren, string nomTren,int numAsientos, int rutasP, int pos)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTren,  nomTren, numAsientos,  rutasP);
    else {
        if (pos <= 1) {                     //InsertarInicio(v);
            pnodoSimpTrenes nuevo = new nodoSimpTrenes( codTren,  nomTren, numAsientos,  rutasP);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            if (pos >= largoLista())
                InsertarFinal(  codTren,  nomTren, numAsientos,  rutasP);
            else
            {

                pnodoSimpTrenes aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != NULL)) {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoSimpTrenes nuevo = new nodoSimpTrenes(  codTren,  nomTren, numAsientos,  rutasP); //1 NODO
                nuevo->siguiente = aux->siguiente; // 2 Nuevo con el valor siguiente 20
                aux->siguiente = nuevo;// 3 aux con nuevo
            }

        }
    }
}

void listaTrenes::BorrarFinal()
{
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else {
        if (primero->siguiente == NULL) {
            primero = NULL;
        }
        else {

            pnodoSimpTrenes aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;

            }

            pnodoSimpTrenes temp = aux->siguiente;
            aux->siguiente = NULL;


            delete temp;
        }
    }
}

void listaTrenes::BorrarInicio()
{
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoSimpTrenes temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {

            pnodoSimpTrenes aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}



void listaTrenes::borrarPosicion(int pos) {
    if (ListaVacia()) {
        cout << "Lista vacia" << endl;
    }
    else {
        if ((pos > largoLista()) || (pos < 0)) {
            cout << "Error en posicion" << endl;
        }
        else {
            if (pos == 1) {
                primero = primero->siguiente;
            }
            else {
                int cont = 2;
                pnodoSimpTrenes aux = primero;
                while (cont < pos) {
                    aux = aux->siguiente;
                    cont++;
                }
                aux->siguiente = aux->siguiente->siguiente;
            }
        }
    }

}


void listaTrenes::Mostrar()
{
    nodoSimpTrenes* aux;
    if (primero == NULL)
        cout << "No hay elementos";
    else
    {
        aux = primero;
        while (aux){
			cout<<aux->codTren<<"-"<<aux->nombre<<"-"<<aux->numAsientos<<"-"<<aux->rutasP<<"->";
            aux = aux->siguiente;
        }
    }
}


	

