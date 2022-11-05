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


// Estructuras colas, pilas, listas, arbol
//#include "./ColaPersona.cpp"

using namespace std;

// Prototipos
template <typename T>
void ingresarPostulante(Lista<T> *&);
template <typename T>
void ingresarOfertaLaboral(Lista<T> *&);
template <typename T>
void asociarPostulanteOferta(Cola<T> *, Lista<T>, Lista<T>);

template <typename T>
void recorrerPostulantes(Lista<T> *&);
template  <typename T>
void recorrerOfertas(Lista<T> *&);

int main () {
	bool flag = true;
	string aux;
//	Fecha fecha1 = pedirFecha();
//	mostrarFecha(fecha1);
//	system("pause");
	int opcion = 0, subopcion = 0;
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
        "Mostrar estadisticas",
        "Salir"
    };
    
    int menuSize = sizeof(menuItem)/sizeof(menuItem[0]);
    int menuMostrarDatosSize = sizeof(menuMostrarDatos)/sizeof(menuMostrarDatos[0]);

    // Estructura cola que almacena postulantes
    Lista<Postulante> *postulantes = NULL;
    Lista<OfertaLaboral> *ofertasLaborales = NULL;

    // Estructura lista que almacena ofertas laborales
   
        
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
                
                
            }else if(opcion == 5) {
            	limpiarPantalla();
                menu(menuMostrarDatos, "MOSTRAR DATOS", menuMostrarDatosSize);
                cout << "Ingrese una opcion: " ;
                aux = pedirCadena();
                opcion = convertirEntero(aux);
                if(opcion == 1) {
                    recorrerPostulantes(postulantes);
                    system("PAUSE");
                }
                if(opcion == 2) {
                    recorrerOfertas(ofertasLaborales);
                    system("PAUSE");
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
    cout << endl << "-------------------------------------" << endl;
    while(lista != NULL) {
        mostrarPostulante(lista->dato);
        lista = lista->siguiente;
        cout << endl << "-------------------------------------" << endl;
    }
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
    cout << endl << "-------------------------------------" << endl;
    while(lista != NULL) {
        mostrarOfertaLaboral(lista->dato);
        lista = lista->siguiente;
        cout << endl << "-------------------------------------" << endl;
    }
    lista = aux;
}