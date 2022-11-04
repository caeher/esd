//Librerias
#include <iostream>

#include "./Functions.cpp"
#include "./Fecha.cpp"
#include "./Persona.cpp"
#include "./Postulante.cpp"
#include "./OfertaLaboral.cpp"
#include "./Reservacion.cpp"
#include "./login.cpp"
#include <string.h>

// Estructuras colas, pilas, listas, arbol
//#include "./ColaPersona.cpp"

using namespace std;



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
        "Mostrar datos",
        "Entrevistar",
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
//    ColaPersona personas;
    Postulante postulantes[10];
    int postu = 0;
    
    OfertaLaboral ofertas[10];
    int ofer = 0;

    // Estructura lista que almacena ofertas laborales
    
    //Validamos que si se logro iniciar sesion
   if(login()){

        
    while(flag) {
        limpiarPantalla();
    	menu(menuItem, "RECURSOS HUMANOS", menuSize);
        cout << "Ingrese una opcion: " ;
        aux = pedirCadena();
        opcion = convertirEntero(aux);
        if(opcion > 0) {    
            if(opcion == 1) {
                postulantes[postu] = pedirPostulante();
                postu++;
            }else if(opcion == 2) {
				ofertas[ofer] = pedirOfertaLaboral();
				ofer++;
			}else if(opcion == 3) {
                limpiarPantalla();
                menu(menuMostrarDatos, "MOSTRAR DATOS", menuMostrarDatosSize);
                cout << "Ingrese una opcion: " ;
                aux = pedirCadena();
                opcion = convertirEntero(aux);
                if(opcion == 1) {
                    for (int i = 0; i < postu; i++)
                    {
                       mostrarPostulante(postulantes[i]); 
                       system("PAUSE");
                    }
                    
                }
                if(opcion == 2) {
                	for(int i = 0; i < ofer; i++) {
                		mostrarOfertaLaboral(ofertas[i]);
                		system("PAUSE");
					}
				}
                
            }else if(opcion == 5) {
            	flag = false;
			}
        }else {
            cout << endl << "Debe ingresar una opcion valida" << endl;

        }
    	
	}
	
	}
    

    return 0;
}
