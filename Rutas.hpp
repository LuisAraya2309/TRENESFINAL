#include <fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodoCir {
public:
    nodoCir(int v)
    {
        valor = v;
        siguiente = NULL;
    }

    nodoCir(int v, nodoCir* signodo)
    {
        valor = v;
        siguiente = signodo;
    }

private:
    int valor;
    nodoCir* siguiente;


    friend class listaC;
};

typedef nodoCir* pnodoCir;

class listaC {
public:
    listaC() { primero = NULL; }
    ~listaC();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos(int v, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void llenarListaRutas();

private:
    pnodoCir primero;

};

listaC::~listaC()
{
    pnodoCir aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaC::largoLista() {
    int cont = 0;

    pnodoCir aux = primero;
    if (ListaVacia())
        return cont;
    else
    {
        while (aux->siguiente != primero)
        {
            cont++;
            aux = aux->siguiente;
        }
        cont = cont + 1;
        return cont;
    }
}

void listaC::InsertarInicio(int v)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir nuevo = new nodoCir(v);
        pnodoCir aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;
        primero = nuevo;
    }
}

void listaC::InsertarFinal(int v)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir nuevo = new nodoCir(v);
        pnodoCir aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;

    }
}


void listaC::InsertarPos(int v, int pos)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
        {
            InsertarInicio(v);
        }
        else
        {
            pnodoCir aux = primero;
            int i = 2;
            while ((i != pos) && (aux->siguiente != primero))
            {
                i++;
                aux = aux->siguiente;
            }
            pnodoCir nuevo = new nodoCir(v);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void listaC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoCir temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir aux = primero;
            pnodoCir temp = primero;
            while (aux->siguiente != primero)
                aux = aux->siguiente;
            primero = primero->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC::borrarPosicion(int pos)
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
                pnodoCir aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoCir temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaC::Mostrar()
{
    pnodoCir aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << aux->valor << "->";
    cout << endl;
}

void listaC::llenarListaRutas() {
    ifstream archivo2;
    string texto;
    archivo2.open("Rutas.txt", ios::in);
    if (archivo2.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo2.eof()) {
        getline(archivo2, texto);

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
        //cout << "Codigo Ciudad: " << codCiudad2 << endl;

        string Todo7 = Todo6.substr(posPC7 + 1, Todo6.length());
        int posPC8 = Todo7.find(";");
        int codPrecio = atoi((Todo7.substr(0, posPC8).c_str()));
        //cout << "Precio: " << codPrecio << endl;
        

    }
    archivo2.close();
}
