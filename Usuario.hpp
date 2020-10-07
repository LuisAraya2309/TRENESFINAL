#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodoUsuario {
public:
    nodoUsuario(int v, string cpais)
    {
        valor = v;
        pais = cpais;
        siguiente = NULL;
        anterior = NULL;
        ciudad = NULL;
    }

    nodoUsuario(int v, string cpais, nodoUsuario* signodo, nodoUsuario* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

private:
    int valor;
    string pais;
    nodoUsuario* ciudad;
    nodoUsuario* siguiente;
    nodoUsuario* anterior;
    friend class listaDCUsuario;
};
typedef nodoUsuario* pnodoUsuario;

class listaDCUsuario {
public:
    listaDCUsuario() { primero = NULL; }

    void InsertarInicio(int v, string pais);
    void InsertarFinal(int v, string pais);
    void InsertarPos(int v, string pais, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    void llenarListaPais();
    void llenarListaCiudad();
    void llenarListaConexiones();
    void llenarListaUsuario();

private:
    pnodoUsuario primero;

};

int listaDCUsuario::largoLista()
{
    int cont = 0;

    pnodoUsuario aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (aux != primero)
        {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDCUsuario::InsertarInicio(int v, string pais)
{

    if (ListaVacia())
    {
        primero = new nodoUsuario(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodoUsuario nuevo = new nodoUsuario(v, pais);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDCUsuario::InsertarFinal(int v, string pais)
{
    if (ListaVacia())
    {
        primero = new nodoUsuario(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodoUsuario nuevo = new nodoUsuario(v, pais);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDCUsuario::InsertarPos(int v, string pais, int pos)
{
    if (ListaVacia())
    {
        primero = new nodoUsuario(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(v, pais);
        else
        {
            if (pos == largoLista())
                InsertarFinal(v, pais);
            else
            {
                pnodoUsuario aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoUsuario nuevo = new nodoUsuario(v, pais);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDCUsuario::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoUsuario temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoUsuario aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoUsuario temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDCUsuario::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoUsuario temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoUsuario aux = primero->anterior;
            pnodoUsuario temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDCUsuario::BorrarPosicion(int pos)
{

    if (ListaVacia())
        cout << "Lista vacia" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posicion" << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                int cont = 2;
                pnodoUsuario aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoUsuario temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDCUsuario::Mostrar()
{
    pnodoUsuario aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->pais << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->pais << "->";
    cout << endl;
}

void listaDCUsuario::llenarListaUsuario(){
    ifstream archivo2;
    string texto;
    archivo2.open("Usuarios.txt", ios::in);
    if (archivo2.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo2.eof()) {
        getline(archivo2, texto);

        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        cout << "Pais: " << codPais << endl;

        string Todo = texto.substr(posPC + 1, texto.length());
        int posPC2 = Todo.find(";");
        int codCiudad = atoi(Todo.substr(0, posPC2).c_str());
        cout << "Ciudad: " << codCiudad << endl;

        string Todo2 = Todo.substr(posPC2 + 1, Todo.length());
        int posPC3 = Todo2.find(";");
        int codPasaporte = atoi((Todo2.substr(0, posPC3).c_str()));
        cout << "Pasaporte: " << codPasaporte << endl;

        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length());
        int posPC4 = Todo3.find(";");
        string nombre = (Todo3.substr(0, posPC4));
        cout << "Nombre: " << nombre << endl;

        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length());
        int posPC5 = Todo4.find(";");
        int estMigracion = atoi((Todo4.substr(0, posPC5).c_str()));
        cout << "Migración: " << estMigracion << endl;
    }
    archivo2.close();
}
