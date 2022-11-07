#include <string.h>
int codigoPostulanteId = 0;
struct Postulante{
	int codigo;
	Persona persona;
	int codigoOferta;
	bool operator==(const Postulante &item) const {
		return codigo == item.codigo;
	}; 
};

/**
 * Funcion que pide los datos de una persona y crea una nueva estructura Postulante
*/
Postulante pedirPostulante() {
	Postulante nuevoPostulante;
	nuevoPostulante.codigo = ++codigoPostulanteId;
	nuevoPostulante.persona = pedirPersona();
	return nuevoPostulante;
}
/** 
 * Funcion que muestra los datos de un postulante
*/
void mostrarPostulante(Postulante postulante) {
	std::cout << std::endl << "Codigo postulante: " << postulante.codigo << std::endl;
	std::cout << "Nombres: " << postulante.persona.nombres << std::endl;
	std::cout << "Apellidos: " << postulante.persona.apellidos << std::endl;
	std::cout << "Direccion: " << postulante.persona.direccion << std::endl;
	std::cout << "Genero: " << postulante.persona.genero << std::endl;
	std::cout << "Edad: " << postulante.persona.edad << std::endl;
}

/**
 * que genera un portulante teniendo existente una persona
*/
Postulante generarPostulante(Persona persona) {
	Postulante nuevoPostulante;
	nuevoPostulante.persona = persona;
	nuevoPostulante.codigoOferta = 0;
	return nuevoPostulante;
}
/**
 * Función que imprime los datos de un postulante en una sola linea
*/
void mostrarPostulanteInline(Postulante postulante) {
	std::cout << std::endl << "Codigo: " << postulante.codigo << " -- ";
	std::cout << "Nombre: " << postulante.persona.nombres << " " << postulante.persona.apellidos;
	std::cout << " -- Direccion: " << postulante.persona.direccion;
	std::cout << " -- Genero: " <<  postulante.persona.genero << " -- Edad: " << postulante.persona.edad;
}

/**
 * Función que compara dos postulantes
*/
bool comparePostulante(Postulante p1, Postulante p2) {
	return p1.codigo == p2.codigo;
}
/**
 * Funcion que compara un postulante con respecto a un código
*/
bool compareCodigo(Postulante p, int codigo) {
	return p.codigo == codigo;
}