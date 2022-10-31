#include <string.h>

typedef struct
{
	std::string nombres;
	std::string apellidos;
	std::string direccion;
	std::string genero;
	int edad;

} Persona;


bool validarGenero (std::string genero) {
	return genero == "M" || genero == "F";
}

Persona pedirPersona() {
	std::string aux;
	bool flag = true;
	Persona newPersona;
	int edadAux = 0;
	while(flag) {
		std::cout << std::endl << "Ingrese el nombre: ";
		aux = pedirCadena();
		if(validarCadena(aux)) {
			flag = false;
		}else {
			std::cout << std::endl << "Debe ingresar un nombre valido" << std::endl;
		}
	}
	newPersona.nombres = aux;
	flag = true;
	while(flag) {
		std::cout << std::endl << "Ingrese los apellidos: ";
		aux = pedirCadena();
		if(validarCadena(aux)) {
			flag = false;
		}else {
			std::cout << std::endl << "Debe ingresar apellidos validos" << std::endl;
		}
	}
	newPersona.apellidos = aux;
	flag = true;

	while(flag) {
		std::cout << std::endl << "Ingrese la direccion: ";
		aux = pedirCadena();
		if(validarCadena(aux)) {
			flag = false;
		}else {
			std::cout << std::endl << "Debe ingresar una direccion valida" << std::endl;
		}
	}
	newPersona.direccion = aux;
	flag = true;

	while(flag) {
		std::cout << std::endl << "Ingrese el genero (M o F): ";
		aux = pedirCadena();
		if(validarGenero(aux)) {
			flag = false;
		}else {
			std::cout << std::endl << "Debe ingresar un genero valido" << std::endl;
		}
	}
	newPersona.genero = aux;
	flag = true;

	while(flag) {
		std::cout << std::endl << "Ingrese la edad: ";
		aux = pedirCadena();
		if(validarCadena(aux)) {
			if((edadAux = convertirEntero(aux)) >= 18) {
				flag = false;
			}
		}else {
			std::cout << std::endl << "Debe ingresar apellidos validos" << std::endl;
		}
	}
	newPersona.edad = edadAux;
	
	return newPersona;
}

