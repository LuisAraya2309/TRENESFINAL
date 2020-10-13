//Clase Main

//Incluimos todos los headers

#include <iostream>
#include "CodigosRuta.hpp"
#include "Rutas.hpp"
#include "Pais-Ciudad.hpp"
#include "Conexiones.hpp"
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
	//------------------------------------------------------------Creación de listas-------------------------------------------
	listaDC paises;
	listaDT tipoTren;
    listaC rutas;
    listaC2 admin;
	listaDCUsuario usuario;
	listaTrenes trenes;
	lista codigoRuta;
	
	listaDC actividadInsertP;
	listaDC actividadInsertC;
	//-----------------------------------------------------Llamar a las funciones de crear la estructura------------------------
    
	//PRIMERA ESTRUCTURA PAIS-CIUDAD-CONEXION
	paises.llenarListaPais();
    paises.llenarListaCiudad();
    paises.llenarListaConexiones();
    //SEGUNDA ESTRUCTURA TIPO DE TRENES TRENES CODIGOS DE RUTAS
    tipoTren.llenarListaTipotrenes();
    tipoTren.llenarListaTrenes();
    paises.BorrarConexion();
    paises.ConsultarConexiones(); VOY A IR A ALMORZAR
    
    
    
    //codigoRuta.llenarlistaCodigosR();
    //TERCERA USUARIO ADMINISTRADOR RUTAS
    /*
	usuario.llenarListaUsuario(paises);
	rutas.llenarListaRutas(paises,tipoTren);
    //admin.llenarListaAdmin();
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    rutas.InsertarRuta(paises,tipoTren);
    */
    //rutas.Mostrar();
    //rutas.ConsultarPrecio(tipoTren);
    //------------------------------------------------------Inicializar Variables----------------------------------------------
	int opcion;
	int codPais;
	string nomPais;
	int codCiudad;
	string nomCiudad;
	int codConexion;
	int codPais2;
	int codCiudad2;
	int codTiempo;
/*
	//---------------------------------------------------------Menu Principal-------------------------------------------------
    do {
        system("cls");      // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        cout << "\n\nSistema de Trenes" << endl;
        cout << "\n\nInicio de sesion" << endl;
        cout << "1. Iniciar como Administrador" << endl;
        cout << "2. Iniciar como Usuario" << endl;
        cout << "3. Salir" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // Lista de instrucciones de la opción 1
				int codAdmin;                
                cout<<"Ingrese el codigo de Administrador: ";
                cin>> codAdmin;
                if (admin.VerificarAdmin(codAdmin)){
                	cout<<"Bienvenido"<<endl;
                		int opcion;
                		
						do {
					        system("cls");      // Para limpiar la pantalla
					        
					        // Texto del menú que se verá cada vez
					        
					        cout << "\n\nSistema de Trenes" << endl;
					        cout << "\n\nMenu del Administrador" << endl;
					        cout << "1. Insertar" << endl;
					        cout << "2. Eliminar" << endl;
					        cout << "3. Modificar" << endl;
					        cout << "4. Consultar paises" << endl;
					        cout << "5. Consultar conexiones de una ciudad" << endl;
					        cout << "6. Consultar ciudades de un pais" << endl;
					        cout << "7. Consultar rutas de un tren" << endl;
					        cout << "8. Consultar trenes de un tipo" << endl;
					        cout << "9. Registrar trenes" << endl;
					        cout << "10. Consultar Precio" << endl;
					        cout << "11. Numero de asientos disponibles" << endl;
					        cout << "12. Salir" << endl;
					        cout << "\nIngrese una opcion: ";
					        cin >> opcion;
					        cout<<endl;
					        
					        switch (opcion) {
					            case 1:
					            	int opcion;
										do {
									        system("cls");      // Para limpiar la pantalla
									    
									        cout << "\n\nSistema de Trenes" << endl;
									        cout << "\n\nMenu de insertar" << endl;
									        cout << "1. Pais" << endl;
									        cout << "2. Ciudad" << endl;
									        cout << "3. Conexion" << endl;
									        cout << "4. Tipo de tren " << endl;
									        cout << "5. Ruta " << endl;
									        cout << "6. Reporte de actividad " << endl;
									        cout << "7. Salir" << endl;
									        cout << "\nIngrese una opcion: ";
									        cin >> opcion;
									        cout<<endl;
									        
									        switch (opcion) {
									        	
									            case 1:
									            	
									            	paises.InsertarPais();
													system("pause>nul");
													break;
													
									            case 2:
									            	
									            	paises.InsertarCiudades();
									            	system("pause>nul");
									                break;
									                
												case 3:
													
									                
									            	paises.InsertarConexion();
									                
									                system("pause>nul"); // Pausa
									                break; 
													                   
									    	 	case 4:
									    	 		tipoTren.InsertarTipoTren();
									                system("pause>nul"); // Pausa
									                break;
									                
									            case 5:
 
									                system("pause>nul"); // Pausa
									                break; 
												
												case 6:
													paises.MostrarActP();
									                system("pause>nul"); // Pausa
									                break;        
											}
										}while (opcion != 7);
									    system("pause>nul"); // Pausa
									    break;   
					            case 2:
					                int opcion2;
										do {
									        system("cls");      // Para limpiar la pantalla
									    
									        cout << "\n\nSistema de Trenes" << endl;
									        cout << "\n\nMenu de eliminar" << endl;
									        cout << "1. Pais" << endl;
									        cout << "2. Ciudad" << endl;
									        cout << "3. Conexion" << endl;
									        cout << "4. Tren " << endl;
									        cout << "5. Ruta " << endl;
									        cout << "6. Reporte de actividad " << endl;
									        cout << "7. Salir" << endl;
									        cout << "\nIngrese una opcion: ";
									        cin >> opcion2;
									        cout<<endl;
									        
									        switch (opcion2) {
									            case 1:
									            	cout<<"Digite el codigo del pais que desea eliminar: "; cin>> codPais; cout<<endl;
									                system("pause>nul"); // Pausa
									                break;
									                
									            case 2:
									                // Lista de instrucciones de la opción 2                
									                
									                system("pause>nul"); // Pausa
									                break;
									                
												case 3:
									                // Lista de instrucciones de la opción 2                
									                
									                system("pause>nul"); // Pausa
									                break;  
													                  
									    	 	case 4:
 
									                system("pause>nul"); // Pausa
									                break;
									                
									            case 5:
 
									                system("pause>nul"); // Pausa
									                break;
									                
												case 6:
 
									                system("pause>nul"); // Pausa
									                break;         
											}
										}while (opcion2 != 7);
									    system("pause>nul"); // Pausa
									    break;
								case 3:
					                int opcion3;
										do {
									        system("cls");      // Para limpiar la pantalla
									    
									        cout << "\n\nSistema de Trenes" << endl;
									        cout << "\n\nMenu de Modificar" << endl;
									        cout << "1. Precio" << endl;
									        cout << "2. Tiempo" << endl;
									        cout << "3. Numero de asientos" << endl;
									        cout << "4. Tren " << endl;
									        cout << "5. Ruta " << endl;
									        cout << "6. Estado migratorio " << endl;
									        cout << "7. Salir" << endl;
									        cout << "\nIngrese una opcion: ";
									        cin >> opcion3;
									        cout<<endl;
									        
									        switch (opcion3) {
									            case 1:
									            	
									                system("pause>nul"); // Pausa
									                break;									                
									            case 2:
									                // Lista de instrucciones de la opción 2                
									                paises.ModificarTiempo();
									                system("pause>nul"); // Pausa
									                break;
												case 3:
									                // Lista de instrucciones de la opción 2                
									                tipoTren.ModificarNumAsientos();
									                system("pause>nul"); // Pausa
									                break;                    
									    	 	case 4:
									    	 		tipoTren.ModificarTren();
									                system("pause>nul"); // Pausa
									                break;
									            case 5:
 
									                system("pause>nul"); // Pausa
									                break;      
												case 6:
													usuario.ModificarEstadoMigratorio();
									                system("pause>nul"); // Pausa
									                break;     
											}
										}while (opcion3 != 7);
									    system("pause>nul"); // Pausa
									    break;                    
					    	 	case 4:
					                paises.ConsultarPaises();           
					                
					                system("pause>nul"); // Pausa
					                break;
								case 5:
					                // Lista de instrucciones de la opción 2                
					                paises.ConsultarConexiones();
					                system("pause>nul"); // Pausa
					                break;
								case 6:
					                paises.ConsultarCiudades();              
					                
					                system("pause>nul"); // Pausa
					                break;
								case 7:
					                // Lista de instrucciones de la opción 2                
					               
					                system("pause>nul"); // Pausa
					                break;
								case 8:
					                // Lista de instrucciones de la opción 2                
					                tipoTren.MostrarUnTipoDeTren();
					                system("pause>nul"); // Pausa
					                break;                    
					    	 	case 9:
					                // Lista de instrucciones de la opción 2                
					                tipoTren.RegistrarTren();
					                system("pause>nul"); // Pausa
					                break;
								case 10:
					                // Lista de instrucciones de la opción 2                
					                rutas.ConsultarPrecio(tipoTren);
					                system("pause>nul"); // Pausa
					                break;
								case 11:
									tipoTren.ConsultarAsientos();
					                // Lista de instrucciones de la opción 2                
					                
					                system("pause>nul"); // Pausa
					                break;                      
						}
				}while (opcion != 12);
				
				}else{
					cout<<"El codigo ingresado no existe por favor vuelva a intentarlo"<<endl;
				}
                system("pause>nul");
                break;	
            case 2:
                int opcion;
						do {
					        system("cls");      // Para limpiar la pantalla
					    
					        cout << "\n\nSistema de Trenes" << endl;
					        cout << "\n\nMenu de Usuario" << endl;
					        cout << "1. Consultar paises" << endl;
					        cout << "2. Consultar ciudades de un pais" << endl;
					        cout << "3. Consultar conexiones de un pais" << endl;
					        cout << "4. Consultar rutas " << endl;
					        cout << "5. Consultar trenes" << endl;
					        cout << "6. Consultar Precio" << endl;
					        cout << "7. Numero de asientos disponibles" << endl;
					        cout << "8. Salir" << endl;
					        cout << "\nIngrese una opcion: ";
					        cin >> opcion;
					        cout<<endl;
					        
					        switch (opcion) {
					            case 1:
					            	paises.ConsultarPaises();
					                system("pause>nul"); // Pausa
					                break;
					                
					            case 2:
					                // Lista de instrucciones de la opción 2                
					                paises.ConsultarCiudades();
					                system("pause>nul"); // Pausa
					                break;
								case 3:
					                // Lista de instrucciones de la opción 2                
					                
					                system("pause>nul"); // Pausa
					                break;                    
					    	 	case 4:
					                paises.ConsultarPaises();          
					                
					                system("pause>nul"); // Pausa
					                break;
								case 5:
					                // Lista de instrucciones de la opción 2                
					                
					                system("pause>nul"); // Pausa
					                break;
								case 6:
					                paises.ConsultarCiudades();              
					                
					                system("pause>nul"); // Pausa
					                break;
								case 7:
					                // Lista de instrucciones de la opción 2                
					                
					                system("pause>nul"); // Pausa
					                break;     
						}
				}while (opcion != 8);
				               
                system("pause>nul"); // Pausa
                break;          
    	} 		
	}while (opcion != 3);*/
    	return 0;
}
