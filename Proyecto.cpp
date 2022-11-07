//Librerias
#include <iostream>

#include "./Functions.cpp"
#include "./Fecha.cpp"
#include "./Persona.cpp"
#include "./Postulante.cpp"
#include "./OfertaLaboral.cpp"
#include "./Reservacion.cpp"
#include "./login.cpp"
#include "./Pila.cpp"
#include "./Cola.cpp"
#include "./Lista.cpp"
#include <string.h>
#include <typeinfo>

// Estructuras colas, pilas, listas, arbol
//#include "./ColaPersona.cpp"

using namespace std;

// Prototipos
template <typename T>
void ingresarPostulante(Lista<T> *&);
template <typename T>
void ingresarOfertaLaboral(Lista<T> *&);
template <typename T, typename A, typename B>
void asociarPostulanteOferta(Cola<T> *&, Cola<T> *&, Lista<A> *&, Lista<B> *&);

template <typename T>
void recorrerPostulantes(Lista<T> *&);
template  <typename T>
void recorrerOfertas(Lista<T> *&);
template<typename A, typename B>
void mostrarPostulanteOferta(Lista<A> *&, Lista<B> *&);
template <typename T>
void mostrarEntrevistados(Pila<T> *&);
int main () {
	bool flag = true, entrevistaFlag;
	string aux;
//	Fecha fecha1 = pedirFecha();
//	mostrarFecha(fecha1);
//	system("pause");
	int opcion = 0, subopcion = 0, opcionEntrevista;
    string menuItem[] = {
        "Ingresar postulante",
        "Ingresar oferta laboral",
        "Asociar postulante con oferta laboral",
        "Entrevistar",
        "Mostrar datos",
        "Salir"
    };
    string menuMostrarDatos[] = {
        "Mostrar postulantes",
        "Mostrar oferta laborales",
        "Mostrar entrevistados",
        "Salir"
    };
    
    int menuSize = sizeof(menuItem)/sizeof(menuItem[0]);
    int menuMostrarDatosSize = sizeof(menuMostrarDatos)/sizeof(menuMostrarDatos[0]);

    // Estructura cola que almacena postulantes
    Lista<Postulante> *postulantes = NULL;
    Lista<OfertaLaboral> *ofertasLaborales = NULL;
    Cola<Reservacion> *primeraReservacion = NULL;
    Cola<Reservacion> *ultimaReservacion = NULL;
	Pila<Reservacion> *entrevistados;
    // Estructura lista que almacena ofertas laborales
    
    // Variables auxiliares
    Reservacion auxReservacion;
    int auxReservacionOpcion = 0;
        
    while(flag) {
        limpiarPantalla();
    	menu(menuItem, "RECURSOS HUMANOS", menuSize);
        cout << "Ingrese una opcion: " ;
        aux = pedirCadena();
        opcion = convertirEntero(aux);
        if(opcion > 0) {    
            if(opcion == 1) {
                ingresarPostulante(postulantes);
            }else if(opcion == 2) {
				ingresarOfertaLaboral(ofertasLaborales);
			}else if(opcion == 3) {
                asociarPostulanteOferta(primeraReservacion, ultimaReservacion, postulantes, ofertasLaborales);
            }else if(opcion == 4) {
            	entrevistaFlag = true;
                while(entrevistaFlag) {
                    entrevistaFlag = true;
                    limpiarPantalla();
                    cout << endl << "----------- ENTREVISTA -----------" << endl;
                    cout << endl << "Desea entrevistar?" << endl;
                    cout << "1. SI" << endl << "2. No" ;
                    aux = pedirCadena();
                    opcionEntrevista = convertirEntero(aux);
                    if(opcionEntrevista == 2) {
                        entrevistaFlag = false;
                    }
                    if(opcionEntrevista == 1) {
                        auxReservacion = popCola(&primeraReservacion, &ultimaReservacion);
                        if(!(auxReservacion.postulante.codigo <= 0 || auxReservacion.ofertaLaboral.codigo <=0)) {
                            cout << endl << "Entrevistando a" << endl;
                            mostrarPostulante(auxReservacion.postulante);
                            cout << endl << "Para la oferta laboral" << endl;
                            mostrarOfertaLaboral(auxReservacion.ofertaLaboral);
                            while(true) {
                                cout << endl << "Al terminar la entrevista seleccione: ";
                                cout << endl << "1. Es contratado" << endl << "2. No es contratado";
                                aux = pedirCadena();
                                auxReservacionOpcion = convertirEntero(aux);
                                if(auxReservacionOpcion == 1) {
                                    cout << endl << "Se contrato a " << endl;
                                    mostrarPostulanteInline(auxReservacion.postulante);
                                    cout << endl << "Para la oferta de "<< endl;
                                    mostrarOfertaInline(auxReservacion.ofertaLaboral);
                                    auxReservacion.esContratado = true;
                                    pushStack(entrevistados, auxReservacion);
                                    break;
                                }else if(auxReservacionOpcion == 2) {
                                    cout << endl << "Se decidio no contratarlo";
                                    auxReservacion.esContratado = false;
                                    break;
                                }else { 
                                    cout << endl << "Debe seleccionar una opcion valida"<<endl;
                                    system("PAUSE");
                                }
                            }
                            system("PAUSE");
                        } else {
                        	cout << endl;
                            system("PAUSE");
                        }
                    }else {
                        cout << endl << "Debe ingresar una opcion valida";
                    }
                }
			}else if(opcion == 5) {
            	
                while(true) {
                    limpiarPantalla();
                    menu(menuMostrarDatos, "MOSTRAR DATOS", menuMostrarDatosSize);
                    cout << "Ingrese una opcion: " ;
                    aux = pedirCadena();
                    subopcion = convertirEntero(aux);
                    if(subopcion == 1) {
                        recorrerPostulantes(postulantes);
                        system("PAUSE");
                    }
                    if(subopcion == 2) {
                        recorrerOfertas(ofertasLaborales);
                        system("PAUSE");
                    } 
                    if(subopcion == 3) {
                        mostrarEntrevistados(entrevistados);
                        system("PAUSE");
                    }
                    if(subopcion == 4) {
                        break;
                    }
                }
			} else if (opcion == 6) {
				flag = false;
			} else if(opcion == 7) {
                system("PAUSE");
            }
        }else {
            cout << endl << "Debe ingresar una opcion valida" << endl;

        }
    	
	}
	
// 	}
    

    return 0;
}


template <typename T>
void ingresarPostulante(Lista<T> *&lista) {
    Postulante nuevo ;
    nuevo = pedirPostulante();

    pushLista(lista, nuevo);

    cout << endl << "Se inserto el postulante correctamente" << endl;
    system("PAUSE");
}

template <typename T>
void recorrerPostulantes(Lista<T> *&lista) {
    Lista<T> *aux = lista;
    while(lista != NULL) {
        cout << endl << "-------------------------------------" << endl;
        mostrarPostulante(lista->dato);
        lista = lista->siguiente;
    }
    cout << endl;
    lista = aux;
}

template <typename T>
void ingresarOfertaLaboral(Lista<T> *& lista) {
    OfertaLaboral nuevo;
    nuevo = pedirOfertaLaboral();
    pushLista(lista, nuevo);
    cout << endl << "Se inserto la oferta laboral correctamente" << endl;
    system("PAUSE");
}
template <typename T>
void recorrerOfertas(Lista<T> *& lista) {
    Lista<T> *aux = lista;
    while(lista != NULL) {
        cout << endl << "-------------------------------------" << endl;
        mostrarOfertaLaboral(lista->dato);
        lista = lista->siguiente;        
    }
    cout << endl;
    lista = aux;
}
template<typename T, typename A, typename B>
void asociarPostulanteOferta(Cola<T> *& primero, Cola<T> *& ultimo, Lista<A> *&postulantes, Lista<B> *&ofertas) {
    Reservacion nuevo;
    Fecha fecha;
    Lista<A> *aux1 = postulantes;
    Lista<B> *aux2 = ofertas;
    A dato1;
    B dato2;
    int idSeleccion = 0, v;
    bool flag = true;
    string cad = "";
    
    mostrarPostulanteOferta(postulantes, ofertas);

    while(flag) {
        cout << endl << "Ingrese el codigo del postulante: ";
        cad = pedirCadena();
        idSeleccion = convertirEntero(cad);
        if(idSeleccion > 0) {
            postulantes = aux1;
            if(postulantes == NULL) {
            	cout << endl << "No hay postulantes";
            	break;
			}
            while(postulantes != NULL) {
                if(postulantes->dato.codigo == idSeleccion) {
                    flag = false; 
                    dato1 = postulantes->dato;
                }
                postulantes = postulantes->siguiente;
            }
            if(flag) {
                cout << endl << "El codigo que selecciono no existe en postulantes";
            }
        }
    }

    flag = true;
    while(flag) {
        cout << endl << "Ingrese el codigo de la Oferta: ";
        cad = pedirCadena();
        idSeleccion = convertirEntero(cad);
        if(idSeleccion > 0) {
            ofertas = aux2;
            if(ofertas == NULL) {
            	cout << endl<<  "No hay ofertas";
            	break;
			}
            while(ofertas != NULL) {
                if(ofertas->dato.codigo == idSeleccion) {
                    flag = false;
                    dato2 = ofertas->dato;
                }
                ofertas = ofertas->siguiente;
            }
            if(flag) {
                cout << endl << "El codigo que selecciono no existe en las ofertas";
            }
            
        }
    }

    if(!(aux1 == NULL && aux2 == NULL)) {
    	fecha = pedirFecha();
	    nuevo = generarReservacion(dato2, dato1, fecha);
	    pushCola(&primero, &ultimo, nuevo);
	    postulantes = aux1;
    	ofertas = aux2;

	}
    
    system("PAUSE");
}

template<typename A, typename B>
void mostrarPostulanteOferta(Lista<A> *& postulantes, Lista<B> *& ofertas) {
	Lista<A> *aux1 = postulantes;
    Lista<B> *aux2 = ofertas;
    cout << endl << "Datos sobre postulantes";
  
     while(postulantes != NULL) {
        mostrarPostulanteInline(postulantes->dato);        
        postulantes = postulantes->siguiente;
    }
    cout << endl << "Datos sobre las ofertas";
    while(ofertas != NULL) {
        mostrarOfertaInline(ofertas->dato);
        ofertas = ofertas->siguiente;
    }
    postulantes = aux1;
    ofertas = aux2;
}

template <typename T>
void mostrarEntrevistados(Pila<T> *&datos) {
    Reservacion r;
    Pila<T> *aux = datos;
    while(datos != NULL) {
        r = popStack(datos);
        if(r.esContratado) {
            cout << endl << "************* CONTRATADO *************" << endl; 
        }else {
            cout << endl << "************* NO CONTRATADO *************" << endl;
        }
        cout << endl << "POSTULANTE"<< endl;
        mostrarPostulante(r.postulante);
        cout << endl << "OFERTA" << endl;
        mostrarOfertaLaboral(r.ofertaLaboral);
        datos = datos->siguiente;
    }

    datos = aux;
}
