#include <fstream> 
#include <iostream> 
#include <stdlib.h> 
#include<string> 
#include "Pais-Ciudad.hpp" 
#include "Tipo-Tren.hpp" 
#include "Conexiones.hpp" 
#include "Trenes.hpp" 
# pragma once 
using namespace std; 
 
class nodoCir { 
public: 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c, int precioc) 
    { 
        codTipTren = v; 
        codTren= trenc; 
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = NULL; 
    } 
 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, nodoCir* signodo) 
    { 
        codTipTren = v; 
        codTren= trenc; 
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = signodo; 
    } 
     
public: 
    int codTipTren; 
    int codTren; 
    int codRutas ; 
    int codPais1 ; 
    int codCiudad1 ; 
    int codPais2 ; 
    int codCiudad2 ; 
    int precio; 
    nodoCir* siguiente; 
 
 
    friend class listaC; 
    friend class listaDC; 
    friend class listaDT; 
    friend class nodoDobleT; 
    friend class nodo; 
}; 
 
typedef nodoCir* pnodoCir; 
 
class listaC { 
public: 
    listaC() { primero = NULL; } 
    ~listaC(); 
 
    void InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, int pos); 
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar(); 
    void BorrarFinal(); 
    void BorrarInicio(); 
    void borrarPosicion(int pos); 
    int largoLista(); 
    void llenarListaRutas(listaDC paises, listaDT tipoTrenes); 
    void ConsultarPrecio(listaDT tipoTrenes); 
    void InsertarRuta(listaDC paises, listaDT tipoTrenes); 
 
public: 
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
 
void listaC::InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) 
{ 
     if (ListaVacia()){ 
    primero = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc, primero); 
    primero->siguiente=primero; 
    } 
   else{ // La funcionalidad de esta parte es que crea un nuevo nodo con el valor asignado y la direccion de primero, luego crea un aux con el valor de primero 
   // Al entrar al while con el parametro actualizado encontraremos el valor del aux que necesitamos para enlazar el nodo con la dirrecion anterior 
   // y posterior por lo que no se hara basura. 
       pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
       pnodoCir aux = primero; 
       while(aux->siguiente!=primero){ 
           aux=aux->siguiente; 
       } 
       aux->siguiente=nuevo; 
       primero=nuevo; 
   } 
} 
 
void listaC::InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) 
{ 
    if (ListaVacia()) 
    { 
    	cout<<"ListaVacia"<<endl; 
    	pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
    	primero= nuevo; 
    	primero->siguiente=primero; 
    } 
    else 
    { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        pnodoCir aux = primero; 
        while (aux->siguiente != primero){ 
        	aux = aux->siguiente; 
		} 
		aux->siguiente=nuevo; 
		nuevo->siguiente=primero; 
    } 
} 
 
void listaC::InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc ,int pos) 
{ 
    if (ListaVacia()) 
    { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        primero = nuevo; 
        nuevo->siguiente = primero; 
    } 
    else 
    { 
        if (pos <= 1) 
        { 
            InsertarInicio(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
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
            pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
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
        cout << aux->codTipTren << "-" << aux->codTren << "-" << aux->codRutas << "-" << aux->codPais1 << "-"<< aux->codCiudad1 << "-"<< aux->codPais2 << "-"<< aux->codCiudad2 <<"-"<< aux->precio << "-> "; 
        aux = aux->siguiente; 
    } 
    cout << aux->codTipTren << "-" << aux->codTren << "-" << aux->codRutas << "-" << aux->codPais1 << "-"<< aux->codCiudad1 << "-"<< aux->codPais2 << "-"<< aux->codCiudad2 <<"-"<< aux->precio << "-> "; 
    cout << endl; 
} 
 
void listaC::llenarListaRutas(listaDC paises,listaDT listaTrenes) { 
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
         
        pnodo buscarPais = paises.primero; bool existePais = false; 
        while(buscarPais->siguiente!=paises.primero){ 
        	cout<<buscarPais->valor<<"=="<<codPais<<endl; 
        	if(buscarPais->valor==codPais){ 
        		existePais = true; 
        		break; 
			} 
			else{ 
				buscarPais=buscarPais->siguiente; 
			} 
		}if(buscarPais->valor==codPais){ 
			existePais=true; 
		} 
		if(existePais){ 
			cout<<"Pase pais1"<<endl; 
			pnodo buscarPais2 = paises.primero; bool existePais2 = false; 
        	while(buscarPais2->siguiente!=paises.primero){	 
        		if(buscarPais2->valor==codPais2){ 
        			existePais2 = true; 
        			break; 
				} 
				else{ 
					buscarPais2=buscarPais2->siguiente; 
				} 
			}if(buscarPais2->valor==codPais2){ 
				existePais2=true; 
			} 
			if(existePais2){ 
				cout<<"Pase pais2"<<endl; 
				pnodo buscarCiudad = buscarPais->ciudad;bool existeCiudad = false; 
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
				} 
				if(existeCiudad){ 
					cout<<"Pase ciudad1"<<endl; 
					pnodo buscarCiudad2 = buscarPais2->ciudad;bool existeCiudad2 = false; 
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
					} 
					bool existeCodTren = false;
					if(existeCiudad2){ 
						if(listaTrenes.Verificar(codTipTren,codTren)){
							existeCodTren=true;
						}
						if(existeCodTren){ 
								cout<<"Entre hasta el final"<<endl; 
								if(ListaVacia()){ 
									cout<<"if"<<endl; 
									InsertarInicio(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio); 
								}else{ 
									cout<<"else"<<endl; 
									pnodoCir buscarRepetidos = primero; bool repetido= false; 
									while(buscarRepetidos->siguiente!=primero){ 
										if(buscarRepetidos->codRutas==codRuta){ 
											repetido=true; 
											break; 
										}else{ 
											buscarRepetidos=buscarRepetidos->siguiente; 
										} 
									}if(!repetido){ 
										InsertarFinal(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);	 
									}else{ 
										cout<<"ESTOY repetido"<<endl; 
										// por si esta repetido 
										continue; 
									} 
								} 
							} 
						 
					} 
					else{ 
						cout<<"NO Pase ciudad2"<<endl; 
						// por si no existe la ciudad 2 
						continue; 
					}		 
				} 
				else{ 
					cout<<"NO Pase ciudad1"<<endl; 
					//por si no existe la ciudad 1 
					continue; 
				} 
			} 
			else{ 
				cout<<"NO Pase pais2"<<endl; 
				//por si no existe el pais2 
				continue; 
			} 
		} 
		else{ 
			cout<<"NO Pase pais1"<<endl; 
			// por si no existe el pais 
			continue; 
		} 
    } 
    archivo2.close(); 
} 
 
 
void listaC::ConsultarPrecio(listaDT tipoTrenes){ 
	int codTipTren; 
	int codTren; 
	int codRuta; 
	cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl; 
	pnodoDobleT buscarTipTren = tipoTrenes.primero;bool existeTipTren = false; 
	while(buscarTipTren!=NULL){ 
		if(buscarTipTren->codTren==codTipTren){ 
			existeTipTren=true; 
			break; 
		} 
		else{ 
			buscarTipTren=buscarTipTren->siguiente; 
		} 
	} 
	if(existeTipTren){ 
		cout<<"Pase tipo de tren"<<endl; 
		pnodoSimpTrenes buscarCodTren = buscarTipTren->listaDeTrenes.primero;bool existeCodTren = false; 
		while(buscarCodTren!=NULL){ 
			cout<<buscarCodTren->codTren<<"=="<<codTren<<endl; 
			if(buscarCodTren->codTren==codTren){ 
				existeCodTren = true; 
				break; 
			} 
			else{ 
				buscarCodTren=buscarCodTren->siguiente; 
			} 
		} 
		if(existeCodTren){ 
			cout<<"Entre hasta el final"<<endl; 
			cout<<"else"<<endl; 
			pnodoCir buscarRepetidos = primero; bool repetido= false; 
			while(buscarRepetidos->siguiente!=primero){ 
				if(buscarRepetidos->codRutas==codRuta){ 
					repetido=true; 
					break; 
				}else{ 
					buscarRepetidos=buscarRepetidos->siguiente; 
				} 
			}if(!repetido){ 
				cout<<"El codigo de ruta no existe"<<endl;	 
			}else{ 
				// por si esta repetido 
				cout<<"El precio de la ruta es "<<buscarRepetidos->precio<<endl; 
			} 
		} 
		else{ 
			cout<<"No pase tren"<<endl; 
			//por si no existe el tren 
		} 
	} 
	else{ 
		cout<<"NO Pase tipo de tren"<<endl; 
		// por si no existe el codTipotren 
	} 
} 
 
 
void listaC::InsertarRuta(listaDC paises, listaDT tipoTrenes){ 
	int codPais; 
	int codPais2; 
	int codCiudad; 
	int codCiudad2; 
	int codPrecio; 
	int codTipTren; 
	int codTren; 
	int codRuta; 
	cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl; 
	cout<<"Ingrese el codigo del primer pais: "; cin>>codPais; cout<<endl; 
	cout<<"Ingrese el codigo de la primera ciudad: "; cin>>codCiudad; cout<<endl; 
	cout<<"Ingrese el codigo del segundo pais: "; cin>>codPais2; cout<<endl; 
	cout<<"Ingrese el codigo de la segunda ciudad: "; cin>>codCiudad2; cout<<endl; 
	cout<<"Ingrese el precio de la ruta: "; cin>>codPrecio; cout<<endl; 
	
        pnodo buscarPais = paises.primero; bool existePais = false; 
        while(buscarPais->siguiente!=paises.primero){ 
        	cout<<buscarPais->valor<<"=="<<codPais<<endl; 
        	if(buscarPais->valor==codPais){ 
        		existePais = true; 
        		break; 
			} 
			else{ 
				buscarPais=buscarPais->siguiente; 
			} 
		}if(buscarPais->valor==codPais){ 
			existePais=true; 
		} 
		if(existePais){ 
			cout<<"Pase pais1"<<endl; 
			pnodo buscarPais2 = paises.primero; bool existePais2 = false; 
        	while(buscarPais2->siguiente!=paises.primero){	 
        		if(buscarPais2->valor==codPais2){ 
        			existePais2 = true; 
        			break; 
				} 
				else{ 
					buscarPais2=buscarPais2->siguiente; 
				} 
			}if(buscarPais2->valor==codPais2){ 
				existePais2=true; 
			} 
			if(existePais2){ 
				cout<<"Pase pais2"<<endl; 
				pnodo buscarCiudad = buscarPais->ciudad;bool existeCiudad = false; 
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
				} 
				if(existeCiudad){ 
					cout<<"Pase ciudad1"<<endl; 
					pnodo buscarCiudad2 = buscarPais2->ciudad;bool existeCiudad2 = false; 
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
					} 
					bool existeCodTren = false;
					if(existeCiudad2){ 
						if(tipoTrenes.Verificar(codTipTren,codTren)){
							existeCodTren=true;
						}
						if(existeCodTren){ 
								cout<<"Entre hasta el final"<<endl; 
								if(ListaVacia()){ 
									cout<<"if"<<endl; 
									InsertarInicio(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio); 
								}else{ 
									cout<<"else"<<endl; 
									pnodoCir buscarRepetidos = primero; bool repetido= false; 
									while(buscarRepetidos->siguiente!=primero){ 
										if(buscarRepetidos->codRutas==codRuta){ 
											repetido=true; 
											break; 
										}else{ 
											buscarRepetidos=buscarRepetidos->siguiente; 
										} 
									}if(!repetido){ 
										InsertarFinal(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);	 
									}else{ 
										cout<<"ESTOY repetido"<<endl; 
										// por si esta repetido 
									
									} 
								} 
							} 
						 
					} 
					else{ 
						cout<<"NO Pase ciudad2"<<endl; 
						// por si no existe la ciudad 2 
		 
					}		 
				} 
				else{ 
					cout<<"NO Pase ciudad1"<<endl; 
					//por si no existe la ciudad 1 
					
				} 
			} 
			else{ 
				cout<<"NO Pase pais2"<<endl; 
				//por si no existe el pais2 
			 
			} 
		} 
		else{ 
			cout<<"NO Pase pais1"<<endl; 
			// por si no existe el pais 
		} 
} 

