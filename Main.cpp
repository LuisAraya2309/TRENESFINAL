//Clase Main

//Incluimos todos los headers

#include <iostream>
#include "CodigosRuta.hpp"
#include "Rutas.hpp"
#include "Pais-Ciudad.hpp"
#include "listaDoble.hpp"
#include "Admin.hpp"
#include "Usuario.hpp"
#include"Tipo-Tren.hpp"
#include "Trenes.hpp"
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
//Definicion de clases






//Definicion de Funciones






//Funcion main

int main() {
    listaDC paises;
    listaC rutas;
    listaC2 admin;
	listaDCUsuario usuario;
    paises.llenarListaPais();
    cout << "Lista de Paises: " << endl;
    paises.ConsultarPaises();
    cout<<endl;
    cout << "Ciudades" << endl;
    paises.llenarListaCiudad();
    cout << "Lista despues de aplicar ciudades: " << endl;
    paises.ConsultarPaises();
    cout<<endl;
    cout<<"Paises . mostrar()"<<endl;
    paises.Mostrar();
    cout<<"Consultar PAIS"<<endl;
    paises.ConsultarCiudades();	
    /*
    paises.ConsultarCiudades();
    cout << "Conexiones: " << endl;
    paises.llenarListaConexiones();
    cout << "Rutas: " << endl;
    rutas.llenarListaRutas();
    cout << "Administradores: " << endl;
    admin.llenarListaAdmin();
    admin.Mostrar();
    cout << "Usuarios: " << endl;
    usuario.llenarListaUsuario();
    */
	return 0;
}
