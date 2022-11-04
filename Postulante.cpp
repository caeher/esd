#include <string.h>
typedef struct {
	Persona persona;
	int codigoOferta;
} Postulante;


Postulante pedirPostulante() {
	Postulante nuevoPostulante;
	nuevoPostulante.persona = pedirPersona();
	return nuevoPostulante;
}

void mostrarPostulante(Postulante postulante) {
	std::cout << std::endl << "Nombres: " << postulante.persona.nombres << std::endl;
	std::cout << "Apellidos: " << postulante.persona.apellidos << std::endl;
	std::cout << "Direccion: " << postulante.persona.direccion << std::endl;
	std::cout << "Genero: " << postulante.persona.genero << std::endl;
	std::cout << "Edad: " << postulante.persona.edad << std::endl;
}


Postulante generarPostulante(Persona persona) {
	Postulante nuevoPostulante;
	nuevoPostulante.persona = persona;
	nuevoPostulante.codigoOferta = NULL;
	return nuevoPostulante;
}
