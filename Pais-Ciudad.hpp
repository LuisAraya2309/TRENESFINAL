#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodo {
public:
    nodo(int v, string cpais)
    {
        valor = v;
        pais = cpais;
        siguiente = NULL;
        anterior = NULL;
        ciudad = NULL;
    }

    nodo(int v, string cpais, nodo* signodo, nodo* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

private:
    int valor;
    string pais;
    nodo* ciudad;
    nodo* siguiente;
    nodo* anterior;
    friend class listaDC;
};
typedef nodo* pnodo;

class listaDC {
public:
    listaDC() { primero = NULL; }

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
    void ConsultarPaises();
    void ConsultarCiudades();

private:
    pnodo primero;

};

int listaDC::largoLista()
{
    int cont = 0;

    pnodo aux = primero;
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

void listaDC::InsertarInicio(int v, string pais)
{

    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDC::InsertarFinal(int v, string pais)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDC::InsertarPos(int v, string pais, int pos)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
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
                pnodo aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodo nuevo = new nodo(v, pais);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero->anterior;
            pnodo temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarPosicion(int pos)
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
                pnodo aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDC::Mostrar()
{
    pnodo aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->pais << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->pais << "->";
    cout << endl;
}

void listaDC::llenarListaPais() {
    ifstream archivo;
    string texto;
    archivo.open("Paises.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        string nomPais = texto.substr(posPC + 1, texto.length());
        if (ListaVacia()) {
            InsertarFinal(codPais, nomPais);
        }
        else {
            pnodo puntero = primero; bool flag = true;
            while (puntero->siguiente != primero) {
                if (puntero->valor == codPais) {
                    flag = false;
                    break;
                }
                else {
                    puntero = puntero->siguiente;
                }
            }
            if (flag) {
                InsertarFinal(codPais, nomPais);
            }
            else{
            	continue;
			}
            
        }
        
    }
    archivo.close();
}

void listaDC::llenarListaCiudad() {
    ifstream archivo;
    string texto;
    archivo.open("Ciudades.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        pnodo puntero = primero->siguiente; bool flag = false;
        while (puntero!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        
        if (flag) {
            string CiudadTotal = texto.substr(posPC + 1, texto.length());
            int auxPC = CiudadTotal.find(";");
            int codCiudad = atoi(CiudadTotal.substr(0, auxPC).c_str());
            string nomCiudad = CiudadTotal.substr(auxPC+1, CiudadTotal.length());
            pnodo auxiliar = primero;
            while (auxiliar->siguiente != primero) {
                if (auxiliar->valor == codPais) {
                    break;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
            cout<<"Pais: "<<auxiliar->pais<<endl;
            cout<<"Agregando la ciudad: "<<nomCiudad<<endl;
            if ((auxiliar->ciudad==NULL)) {
            	cout<<"Se agrega de primero!"<<endl;
                pnodo nuevo = new nodo(codCiudad,nomCiudad);
                auxiliar->ciudad = nuevo;
                nuevo->anterior=auxiliar;
                nuevo->ciudad=auxiliar;
            }
            else {
            	pnodo nuevo = new nodo(codCiudad,nomCiudad); 
            	pnodo recorrer = auxiliar->ciudad;
            	while(recorrer->ciudad!=auxiliar){
            		cout<<"Ciudad ya agregada: "<<recorrer->pais<<endl;
            		recorrer=recorrer->ciudad;
				}
				cout<<"Agregada de ultimo! "<<endl;
				recorrer->ciudad=nuevo;
				nuevo->anterior=recorrer;
				nuevo->ciudad=auxiliar;
				}
				cout<<"x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<<endl;
				cout<<endl;
            }
            else {
            	continue;
        	}
        }	
    }
void listaDC::llenarListaConexiones() {
    ifstream archivo;
    string texto;
    archivo.open("Conexiones.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente != primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        if (flag) {

            //cout << "Estoy entrando al pais: "<<puntero->pais << endl;

            string ConexionTotal = texto.substr(posPC + 1, texto.length());
            int posPC2 = ConexionTotal.find(";");
            int codCiudad = atoi((ConexionTotal.substr(0, posPC2).c_str()));

            pnodo ciudades = puntero->ciudad; bool flag2=false; 
            while (ciudades->siguiente != puntero) {
                if (ciudades->valor == codCiudad) {
                    flag2 = true;
                    break;
                }
                else {
                    ciudades = ciudades->siguiente;
                }
            }
            if (flag2) {

                //cout << "Estoy entrando a la ciudad: " << ciudades->pais << endl;

                string Conexion = ConexionTotal.substr(posPC2 + 1, ConexionTotal.length());
                int posPC3 = Conexion.find(";");
                int codConexion = atoi((Conexion.substr(0, posPC3).c_str()));

                string ConexionPais = Conexion.substr(posPC3 + 1, Conexion.length());
                int posPC4 = ConexionPais.find(";");
                int codPais = atoi((ConexionPais.substr(0, posPC4).c_str()));

                string ConexionCiudad = ConexionPais.substr(posPC4 + 1, ConexionPais.length());
                int posPC5 = ConexionCiudad.find(";");
                int codCiudad = atoi((ConexionCiudad.substr(0, posPC5).c_str()));

                string Tiempo = ConexionCiudad.substr(posPC5 + 1, ConexionCiudad.length());
                int posPC6 = Tiempo.find(";");
                int codTiempo = atoi((Tiempo.substr(0, posPC6).c_str()));
                /*
                cout << "Codigo conexion: "<<codConexion << endl;
                cout << "Codigo de Pais: "<<codPais << endl;
                cout << "Codigo Ciudad: "<<codCiudad << endl;
                cout << "Tiempo: "<<codTiempo << endl;
                */

                pnodo paisesAux = primero; bool bandera = false;
                while (paisesAux->siguiente!=primero) {
                    if (paisesAux->valor==codPais) {
                        bandera = true;
                        break;
                    }
                    else {
                        paisesAux = paisesAux->siguiente;
                    }

                }
                if (bandera) {
                    pnodo ciudadesAux = paisesAux->ciudad; bool banderix = false;
                    while (ciudadesAux->siguiente!=paisesAux) {
                        if (ciudadesAux->valor==codCiudad) {
                            banderix = true;
                            break;
                        }
                        else {
                            ciudadesAux = ciudadesAux->siguiente;
                        }

                    }
                    if (banderix) {
                        /*
                        pnodoDoble aux = ciudadesAux;
                        while (aux->siguiente != NULL) {
                            aux = aux->siguiente;
                        }
                        pnodoDoble nuevo = new nodoDoble(codConexion, codPais, codCiudad, codTiempo);
                        aux->siguiente = nuevo;
                        nuevo->anterior = aux;
                        */
                    }
                    else {
                        continue;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }
}

void listaDC::ConsultarPaises() {
    pnodo aux = primero;
    cout << "Paises: " << endl;
    while (aux->siguiente != primero)
    {
        cout << aux->pais << "  Codigo: " << aux->valor << endl;
        aux = aux->siguiente;
    }
    cout << aux->pais << "  Codigo: " << aux->valor << endl;
    cout << endl;
}


void listaDC::ConsultarCiudades() {
    int codPais;
    cout << "Ingrese el codigo del pais: ";
    cin >> codPais;
    pnodo puntero = primero->siguiente; bool flag = false;
    while (puntero!= primero) {
        if (puntero->valor == codPais) {
            flag = true;
            break;
        }
        else {
            puntero = puntero->siguiente;
        }
    }
    if(puntero->valor==codPais){
    	cout<<"Prueba: "<<puntero->ciudad->pais<<endl;
    	flag=true;
	}
    cout <<"Pais: "<<puntero->pais<< endl;
    if (flag) {
        pnodo ciudades = puntero->ciudad; bool flag2 = false;
        while (ciudades->ciudad != puntero) {
            cout << ciudades->pais << "  Codigo: " << ciudades->valor << endl;
            ciudades = ciudades->ciudad;
        }
        cout << ciudades->pais << "  Codigo: " << ciudades->valor << endl;
        cout << endl;
    }
    else {
        cout << "El codigo ingresado no existe" << endl;
    }
}
