//Librerias
#include <iostream>

// #include "./Functions.cpp"
#include "./Reservacion.cpp"
#include "./Fecha.cpp"
#include "./login.cpp"

using namespace std;



int main () {
    
    
    //Validamos que si se logro iniciar sesion
    if(login()){
    
	Fecha nuevaFecha = pedirFecha();

    mostrarFecha(nuevaFecha);
	}
    
    
    

    return 0;
}
