#include <string.h>
// #include <iostream>
// using namespace std;
// #include "./Persona.cpp"
typedef struct {
	// char nombrePost[50];
	// char apellidosPost[50];
	// char direccion[50];
	// char genero[10];
	// int edad;
	// char gmail[50];
	// char telefono[10];
	Persona datos;
	int codigoOferta;
} Postulante;


Postulante pedirPostulante() {
	Postulante newPostulante;
	newPostulante.datos = pedirPersona();
	return newPostulante;
}

void mostrarPostulante(Postulante postulante) {
	std::cout << std::endl << "Nombres: " << postulante.datos.nombres << std::endl;
	std::cout << "Apellidos: " << postulante.datos.apellidos << std::endl;
	std::cout << "Direccion: " << postulante.datos.direccion << std::endl;
	std::cout << "Genero: " << postulante.datos.genero << std::endl;
	std::cout << "Edad: " << postulante.datos.edad << std::endl;
}