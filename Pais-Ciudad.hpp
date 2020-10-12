#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
#include "Conexiones.hpp"
#pragma once
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
        listaConexiones = listaD();
        primeraConexion = listaConexiones.primero;
    }

    nodo(int v, string cpais, nodo* signodo, nodo* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

public:
    int valor;
    string pais;
    nodo* ciudad;
    nodo* siguiente;
    nodo* anterior;
    listaD listaConexiones;
    nodoDoble *primeraConexion;
    friend class listaDC;
    friend class nodoDoble;
    friend class listaD;
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
    bool InsertarPais(int v, string pais);
    bool InsertarCiudades (int codPais,int codCiudad, string nomCiudad);
    void InsertarConexion(int codPais, int codCiudad, int codConexion, int codPais2, int codCiudad2, int tiempo);
    bool EliminarPais(int codPais,listaDC paises);
    bool EliminarCiudad(int codPais, int CodCiudad,listaDC paises);

public:
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
        pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        if(puntero->valor==codPais){
        	flag=true;
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
            if ((auxiliar->ciudad==NULL)) {
                pnodo nuevo = new nodo(codCiudad,nomCiudad);
                auxiliar->ciudad = nuevo;
                nuevo->anterior=auxiliar;
                nuevo->ciudad=auxiliar;
            }
            else {
            	bool bandera= false;
            	pnodo nuevo = new nodo(codCiudad,nomCiudad); 
            	pnodo recorrer = auxiliar->ciudad;
            	while(recorrer->ciudad!=auxiliar){
            		if(recorrer->valor==codCiudad){
            			bandera=true;
            			break;
					}else{
						recorrer=recorrer->ciudad;
					}
				}if(!bandera){
					recorrer->ciudad=nuevo;
					nuevo->anterior=recorrer;
					nuevo->ciudad=auxiliar;
				}
			}
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
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }if(puntero->valor==codPais){
        			flag=true;
        	        if (flag) {
			            //cout << "Estoy entrando al pais: "<<puntero->pais << endl;
			
			            string ConexionTotal = texto.substr(posPC + 1, texto.length());
			            int posPC2 = ConexionTotal.find(";");
			            int codCiudad = atoi((ConexionTotal.substr(0, posPC2).c_str()));
			
			            pnodo ciudades = puntero->ciudad; bool flag2=false; 
			            while (ciudades!= puntero) {
			                if (ciudades->valor == codCiudad) {
			                    flag2 = true;
			                    break;
			                }
			                else {
			                    ciudades = ciudades->siguiente;
			                }
			            }if(ciudades->valor==codCiudad){
			            	flag2=true;
			            	if (flag2) {
				                string Conexion = ConexionTotal.substr(posPC2 + 1, ConexionTotal.length());
				                int posPC3 = Conexion.find(";");
				                int codConexionAux = atoi((Conexion.substr(0, posPC3).c_str()));
				
				                string ConexionPais = Conexion.substr(posPC3 + 1, Conexion.length());
				                int posPC4 = ConexionPais.find(";");
				                int codPais = atoi((ConexionPais.substr(0, posPC4).c_str()));
				
				                string ConexionCiudad = ConexionPais.substr(posPC4 + 1, ConexionPais.length());
				                int posPC5 = ConexionCiudad.find(";");
				                int codCiudad = atoi((ConexionCiudad.substr(0, posPC5).c_str()));
				
				                string Tiempo = ConexionCiudad.substr(posPC5 + 1, ConexionCiudad.length());
				                int posPC6 = Tiempo.find(";");
				                int codTiempo = atoi((Tiempo.substr(0, posPC6).c_str()));
				                
				                cout << "Codigo conexion: "<<codConexionAux << endl;
				                cout << "Codigo de Pais: "<<codPais << endl;
				                cout << "Codigo Ciudad: "<<codCiudad << endl;
				                cout << "Tiempo: "<<codTiempo << endl;
				                
				                //Vamos a verificar de que exista el pais
				                pnodo buscarPais = primero->siguiente;bool existePais = false;
				                while(buscarPais!=primero){
				                	if(buscarPais->valor==codPais){
				                		existePais=true;
				                		break;
									}
									else{
										buscarPais=buscarPais->siguiente;
									}
								}if(buscarPais->valor==codPais){
									existePais=true;
									if(existePais){
										pnodo buscarCiudad = buscarPais->ciudad; bool existeCiudad = false;
										while(buscarCiudad!=buscarPais){
											if(buscarCiudad->valor==codCiudad){
												existeCiudad = true;
												break;
											}
											else{
												buscarCiudad=buscarCiudad->ciudad;
											}
										}if(buscarCiudad->valor==codCiudad){
											existeCiudad=true;
											if(existeCiudad){
												//Ahora vamos a ver que no se repita la conexionS
												bool conexionRepetida = false;
												pnodo paisesG = primero->siguiente;
												while(paisesG!=primero){
													pnodo ciudadesG = paisesG->ciudad;
													while(ciudadesG!=paisesG){
														pnodoDoble conexionG = ciudadesG->listaConexiones.primero;
														while(conexionG!=NULL){
															if(conexionG->codConexion==codConexionAux){
																conexionRepetida = true;
																break;
															}
															else{
																conexionG = conexionG->siguiente;
															}
														}
														ciudadesG = ciudadesG->ciudad;
													}
													paisesG=paisesG->siguiente;
												}
												if(!conexionRepetida){
													buscarCiudad->listaConexiones.InsertarFinalD(codConexionAux,codPais,codCiudad,codTiempo);
													cout<<"Lista Conexiones: "<<endl;
													buscarCiudad->listaConexiones.Mostrar();
													cout<<endl;
													continue;
												}
												else{
													// por si la conexion estaba repetida
													cout<<"Lista Conexiones: "<<endl;
													buscarCiudad->listaConexiones.Mostrar();
													cout<<endl;
													continue;
												}
											}else{
												//Else existe ciudad
											}
										}else{
											//este else buscar todo
											continue;
										}	
									}else{
										//Si no exite el pais
										continue;
									}
								}else{
									//Verificar el ultimo
									continue;
								}
				//No tocar estas llaves
				        	}else{
				        		//paso Ciudad
							}
						}else{
							//Verificartodo
						}
			            
			    	}else{
			    		//Paso el pais
					}
		}else{
			//Verificar ultimo
			cout<<"Pase el pais"<<endl;
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
    cout<<endl;
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
    	//cout<<"Prueba: "<<puntero->ciudad->pais<<endl;
    	flag=true;
	}
    //cout <<"Pais: "<<puntero->pais<< endl;
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

bool listaDC::InsertarPais(int v, string pais){
	if (ListaVacia()) {
	            InsertarFinal(v, pais);
	        }
	        else {
	            pnodo puntero = primero; bool flag = true;
	            while (puntero->siguiente != primero) {
	                if (puntero->valor == v) {
	                    flag = false;
	                    return false;
	                    break;
	                }
	                else {
	                    puntero = puntero->siguiente;
	                }
	            }
	            if (flag) {
	                InsertarFinal(v, pais);
	            }
			}
	    }
	    
bool listaDC::InsertarCiudades(int codPais, int codCiudad, string nomCiudad){
	pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        if(puntero->valor==codPais){
        	flag=true;
		}
        if (flag) {
            
            pnodo auxiliar = primero;
            while (auxiliar->siguiente != primero) {
                if (auxiliar->valor == codPais) {
                    break;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
            if ((auxiliar->ciudad==NULL)) {
                pnodo nuevo = new nodo(codCiudad,nomCiudad);
                auxiliar->ciudad = nuevo;
                nuevo->anterior=auxiliar;
                nuevo->ciudad=auxiliar;
            }
            else {
            	bool bandera= false;
            	pnodo nuevo = new nodo(codCiudad,nomCiudad); 
            	pnodo recorrer = auxiliar->ciudad;
            	while(recorrer->ciudad!=auxiliar){
            		if(recorrer->valor==codCiudad){
            			return true;
					}else{
						recorrer=recorrer->ciudad;
					}
				}if(!bandera){
					recorrer->ciudad=nuevo;
					nuevo->anterior=recorrer;
					nuevo->ciudad=auxiliar;
				}
			}
    }
}

void listaDC::InsertarConexion(int codPais, int codCiudad, int codConexion, int codPais2, int codCiudad2, int tiempo){
				pnodo buscarPais = primero;bool existePais = false;
                while(buscarPais->siguiente!=primero){
                	cout<<buscarPais->valor<<"=="<<codPais<<endl;
                	if(buscarPais->valor==codPais){
                		existePais=true;
                		break;
					}
					else{
						buscarPais=buscarPais->siguiente;
					}
					
					}if(buscarPais->valor==codPais){
						existePais=true;
						if(existePais){
							pnodo buscarPais2 = primero;bool existePais2 = false;
			                while(buscarPais2->siguiente!=primero){
			                	cout<<buscarPais2->valor<<"=="<<codPais2<<endl;
			                	if(buscarPais2->valor==codPais2){
			                		existePais2=true;
			                		break;
								}
								else{
									buscarPais2=buscarPais2->siguiente;
								}
							}if(buscarPais2->valor==codPais2){
								existePais2=true;
								if(existePais2){
									pnodo buscarCiudad = buscarPais->ciudad; bool existeCiudad = false;
									while(buscarCiudad!=buscarPais){
										if(buscarCiudad->valor==codCiudad){
											existeCiudad = true;
											break;
										}
										else{
											buscarCiudad=buscarCiudad->ciudad;
										}
									}if(buscarCiudad->valor==codCiudad){
										existeCiudad== true;
										if(existeCiudad){
											pnodo buscarCiudad2 = buscarPais2->ciudad; bool existeCiudad2 = false;
											while(buscarCiudad2!=buscarPais2){
												if(buscarCiudad2->valor==codCiudad2){
													existeCiudad2 = true;
													break;
												}
												else{
													buscarCiudad2=buscarCiudad2->ciudad;
												}
											}if(buscarCiudad2->valor==codCiudad2){
												existeCiudad2=true;
												if(existeCiudad2){
													cout<<"Paso ciudad"<<endl;
													//Ahora vamos a ver que no se repita la conexionS
													bool conexionRepetida = false;
													pnodo paisesG = primero->siguiente;
													while(paisesG!=primero){
														pnodo ciudadesG = paisesG->ciudad;
														while(ciudadesG!=paisesG){
															pnodoDoble conexionG = ciudadesG->listaConexiones.primero;
															while(conexionG!=NULL){
																if(conexionG->codConexion==codConexion){
																	conexionRepetida = true;
																	break;
																}
																else{
																	conexionG = conexionG->siguiente;
																}
															}
															ciudadesG = ciudadesG->ciudad;
														}
														paisesG=paisesG->siguiente;
													}
													if(!conexionRepetida){
														buscarCiudad->listaConexiones.InsertarFinalD(codConexion,codPais2,codCiudad2,tiempo);
														cout<<"Lista Conexiones: "<<endl;
														buscarCiudad->listaConexiones.Mostrar();
														cout<<endl;
														//return true;
													}
													else{
														// por si la conexion estaba repetida
														cout<<"Lista Conexiones: "<<endl;
														buscarCiudad->listaConexiones.Mostrar();
														cout<<endl;
														//return false;
													}
												}else{
												//Ciudad2
												}
											}
										}else{	
										}
									}
								}else{
									//Pais2
								}
							}
							
							else{
								//return false;
								//este else es de si no existe la ciudad			
							}
					}else{
					}
				}
				else{
					//return false;
					//Este else es de si no existe el pais
				}
}
bool listaDC::EliminarPais(int codPais,listaDC paises){
	pnodo puntero = primero; bool flag = false; int cont=1;
        while (puntero->siguiente != primero) {
		    if (puntero->valor == codPais) {
		    	cout<<"lo encontre: "<<puntero->valor<<endl;
		    	paises.BorrarPosicion(cont);
	            return true;
	        }else {
	        	puntero = puntero->siguiente;
	        	cont++;
	        }
	    }if (puntero->valor==codPais) {
	    		cout<<"lo encontre: "<<puntero->valor<<endl;
	    		paises.BorrarPosicion(cont);
	    		return true;
	    	}else{
	    		return false;
		}
	}





