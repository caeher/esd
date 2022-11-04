#include <string>

int contadorId = 0;

typedef struct {
	int codigo;
	OfertaLaboral ofertaLaboral;
	Fecha fecha;
	Postulante postulante;
	bool esContratado;
} Reservacion;


Reservacion generarReservacion(OfertaLaboral oferta, Postulante postulante, Fecha fecha) {
	
	Reservacion nuevaReservacion;
	nuevaReservacion.codigo = ++contadorId;
	nuevaReservacion.ofertaLaboral = oferta;
	nuevaReservacion.postulante = postulante;
	nuevaReservacion.fecha = fecha;
	nuevaReservacion.esContratado = false;

	return nuevaReservacion;
}

void mostrarReservacion(Reservacion reservacion) {
	std::cout << std::endl << "Identificador: " << reservacion.codigo << std::endl;
	mostrarOfertaLaboral(reservacion.ofertaLaboral);
	mostrarFecha(reservacion.fecha);
	mostrarPostulante(reservacion.postulante);
}
