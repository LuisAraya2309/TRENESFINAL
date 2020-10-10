#include <iostream>
using namespace std;
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar
#pragma once
class nodoSimpTrenes { //clase NODO

public:
    nodoSimpTrenes(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
        codTipo=codTipo;//20
        codTren=codTren;
        nombre= nombre;
        numAsientos= numAsientos;
        rutasP= rutasP;
        siguiente = NULL;
        listaRutas= lista();
    }

    nodoSimpTrenes(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP, nodoSimpTrenes* signodo) // 2 dirprimero direccion de memoria
    {
        codTipo=codTipo;//20
        codTren=codTren;
        nombre= nombre;
        numAsientos= numAsientos;
        rutasP= rutasP;
        siguiente = signodo;//primero
    }

public: // atributos
    int codTipo; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    int codTren;
    string nombre;
    int numAsientos;
    int rutasP;
    lista listaRutas;
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
    void InsertarInicio(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP);
    void InsertarFinal(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP);
    void InsertarPos(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void llenarListaTrenes();

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

void listaTrenes::InsertarInicio(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
    else
        primero = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP, primero);
}

void listaTrenes::InsertarFinal(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
    else
    {
        pnodoSimpTrenes aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
    }
}

void listaTrenes::InsertarPos(int codTipo, int codTren, string nomTren,int numAsientos, int rutasP, int pos)
{
    if (ListaVacia())
        primero = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
    else {
        if (pos <= 1) {                     //InsertarInicio(v);
            pnodoSimpTrenes nuevo = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            if (pos >= largoLista())
                InsertarFinal( codTipo,  codTren,  nomTren, numAsientos,  rutasP);
            else
            {

                pnodoSimpTrenes aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != NULL)) {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoSimpTrenes nuevo = new nodoSimpTrenes( codTipo,  codTren,  nomTren, numAsientos,  rutasP); //1 NODO
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
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

void listaTrenes::llenarListaTrenes(){
	ifstream archivoT;
    string texto;
    archivoT.open("Trenes.txt", ios::in);
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
        int codTren = atoi(Todo.substr(0, posPC2).c_str());
        cout << "Codigo Tren: " << codTren << endl;

        string Todo2 = Todo.substr(posPC2 + 1, Todo.length());
        int posPC3 = Todo2.find(";");
        string nomTren = (Todo2.substr(0, posPC3));
        cout << "Tren: " << nomTren << endl;
        
        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length());
        int posPC4 = Todo3.find(";");
        int numAsientos = atoi((Todo3.substr(0, posPC4).c_str()));
        cout << "Numero de asientos: " << numAsientos << endl;
        
        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length());
        int posPC5 = Todo4.find(";");
        int ruta = atoi((Todo4.substr(0, posPC5).c_str()));
        cout << "Rutas:  " << ruta << endl;
        
        cout<<endl; cout<<endl;
	}
	archivoT.close();
}
	

