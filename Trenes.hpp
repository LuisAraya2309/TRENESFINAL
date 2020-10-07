#include <iostream>
using namespace std;
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar

class nodoSimpTrenes { //clase NODO

public:
    nodoSimpTrenes(int v) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
        valor = v;//20
        siguiente = NULL;
    }


    nodoSimpTrenes(int v, nodoSimpTrenes* signodo) // 2 dirprimero direccion de memoria
    {
        valor = v;//2
        siguiente = signodo;//primero
    }


private: // atributos
    int valor; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    nodoSimpTrenes* siguiente; // tipo de la clase, clase autoreferencia. Direccion 


    friend class listaTrenes; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoSimpTrenes* pnodoSimpTrenes; //alias redefinir los punteros

class listaTrenes {
public:
    listaTrenes()
    {
        primero = NULL;

    }
    ~listaTrenes();
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos(int v, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

private:
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

void listaTrenes::InsertarInicio(int v)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes(v);
    else
        primero = new nodoSimpTrenes(v, primero);
}

void listaTrenes::InsertarFinal(int v)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes(v);
    else
    {
        pnodoSimpTrenes aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = new nodoSimpTrenes(v);
    }
}

void listaTrenes::InsertarPos(int v, int pos)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes(v);
    else {
        if (pos <= 1) {                     //InsertarInicio(v);
            pnodoSimpTrenes nuevo = new nodoSimpTrenes(v);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            if (pos >= largoLista())
                InsertarFinal(v);
            else
            {

                pnodoSimpTrenes aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != NULL)) {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoSimpTrenes nuevo = new nodoSimpTrenes(v); //1 NODO
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
        while (aux)
        {
            cout << aux->valor << "-> ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

