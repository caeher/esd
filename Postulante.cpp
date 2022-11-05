#include <string.h>
int codigoPostulanteId = 0;
struct Postulante{
	int codigo;
	Persona persona;
	int codigoOferta;
	bool operator==(const Postulante &item) const {
		return codigo == item.codigo;
	}
};


Postulante pedirPostulante() {
	Postulante nuevoPostulante;
	nuevoPostulante.codigo = ++codigoPostulanteId;
	nuevoPostulante.persona = pedirPersona();
	return nuevoPostulante;
}

void mostrarPostulante(Postulante postulante) {
	std::cout << std::endl << "Codigo postulante: " << postulante.codigo << std::endl;
	std::cout << "Nombres: " << postulante.persona.nombres << std::endl;
	std::cout << "Apellidos: " << postulante.persona.apellidos << std::endl;
	std::cout << "Direccion: " << postulante.persona.direccion << std::endl;
	std::cout << "Genero: " << postulante.persona.genero << std::endl;
	std::cout << "Edad: " << postulante.persona.edad << std::endl;
}


Postulante generarPostulante(Persona persona) {
	Postulante nuevoPostulante;
	nuevoPostulante.persona = persona;
	nuevoPostulante.codigoOferta = 0;
	return nuevoPostulante;
}
