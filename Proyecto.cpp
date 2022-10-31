//Librerias
#include <iostream>

#include "./Functions.cpp"
#include "./Persona.cpp"
#include "./Postulante.cpp"
#include "./Reservacion.cpp"
#include "./Fecha.cpp"
#include "./login.cpp"
#include <string.h>

using namespace std;



int main () {
	bool flag = true;
	string aux;
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
    Postulante postulantes[10];
    int postu = 0;
    // Estructura lista que almacena ofertas laborales
    

    
    //Validamos que si se logro iniciar sesion
//    if(login()){
    
//	Fecha nuevaFecha = pedirFecha();

//    mostrarFecha(nuevaFecha);
//	}

	
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
            }

            if(opcion == 3) {
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
            }
        }else {
            cout << endl << "Debe ingresar una opcion valida" << endl;

        }
    	
	}

    
    

    return 0;
}
