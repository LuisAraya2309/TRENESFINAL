#include <fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodoCir2 {
public:
    nodoCir2(int v, string nNombre)
    {
        valor = v;
        nombre = nNombre;
        siguiente = NULL;
    }

    nodoCir2(int v, string nNombre, nodoCir2* signodo)
    {
        valor = v;
        nombre = nNombre;
        siguiente = signodo;
    }
private:
    int valor;
    string nombre;
    nodoCir2* siguiente;


    friend class listaC2;
};

typedef nodoCir2* pnodoCir2;

class listaC2 {
public:
    listaC2() { primero = NULL; }
    ~listaC2();

    void InsertarInicio(int v, string nombre);
    void InsertarFinal(int v, string nombre);
    void InsertarPos(int v, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void llenarListaAdmin();
    bool VerificarAdmin(int codAdmin);

private:
    pnodoCir2 primero;

};

listaC2::~listaC2()
{
    pnodoCir2 aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaC2::largoLista() {
    int cont = 0;

    pnodoCir2 aux = primero;
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

void listaC2::InsertarInicio(int v, string nombre)
{
    if (ListaVacia())
    {
        pnodoCir2 nuevo = new nodoCir2(v, nombre);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir2 nuevo = new nodoCir2(v, nombre);
        pnodoCir2 aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;
        primero = nuevo;
    }
}

void listaC2::InsertarFinal(int v, string nombre)
{
    if (ListaVacia())
    {
        pnodoCir2 nuevo = new nodoCir2(v, nombre);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir2 nuevo = new nodoCir2(v, nombre);
        pnodoCir2 aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;

    }
}


void listaC2::InsertarPos(int v, string nombre, int pos)
{
    if (ListaVacia())
    {
        pnodoCir2 nuevo = new nodoCir2(v,nombre);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
        {
            InsertarInicio(v,nombre);
        }
        else
        {
            pnodoCir2 aux = primero;
            int i = 2;
            while ((i != pos) && (aux->siguiente != primero))
            {
                i++;
                aux = aux->siguiente;
            }
            pnodoCir2 nuevo = new nodoCir2(v,nombre);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void listaC2::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir2 temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir2 aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoCir2 temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC2::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir2 temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir2 aux = primero;
            pnodoCir2 temp = primero;
            while (aux->siguiente != primero)
                aux = aux->siguiente;
            primero = primero->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC2::borrarPosicion(int pos)
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
                pnodoCir2 aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoCir2 temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaC2::Mostrar()
{
    pnodoCir2 aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->nombre << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->nombre << "->";
    cout << endl;
}

void listaC2::llenarListaAdmin() {
    ifstream archivo2;
    string texto;
    archivo2.open("Administradores.txt", ios::in);
    if (archivo2.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo2.eof()) {
        getline(archivo2, texto);
        int posPC = texto.find(";");
        int codAdmin = atoi(texto.substr(0, posPC).c_str());
        string nomAdmin = texto.substr(posPC + 1, texto.length());
        if (ListaVacia()) {
            InsertarFinal(codAdmin, nomAdmin);
        }
        else {
            pnodoCir2 puntero = primero; bool flag = true;
            while (puntero->siguiente != primero) {
                if (puntero->valor == codAdmin) {
                    flag = false;
                    break;
                }
                else {
                    puntero = puntero->siguiente;
                }
            }
            if (flag) {
                InsertarFinal(codAdmin, nomAdmin);
            }

        }
    }
    archivo2.close();
}

bool listaC2::VerificarAdmin(int codAdmin){
	pnodoCir2 puntero=primero;
	bool flag= false;
	while(puntero->siguiente != primero){
		if (puntero->valor==codAdmin){
			return true;
		}else{
			puntero=puntero->siguiente;
		}
	}if (puntero->valor==codAdmin){
		return true;
	}else{
		return false;	
	}
}
