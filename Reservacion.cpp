#include <string>

int contadorId = 0;

struct Reservacion{
	int codigo;
	OfertaLaboral ofertaLaboral;
	Fecha fecha;
	Postulante postulante;
	bool esContratado;
	bool operator==(const Reservacion& item) const{
		return codigo == item.codigo;
	}
} ;

/**
 * Genera una revervación nueva
*/
Reservacion generarReservacion(OfertaLaboral oferta, Postulante postulante, Fecha fecha) {
	
	Reservacion nuevaReservacion;
	nuevaReservacion.codigo = ++contadorId;
	nuevaReservacion.ofertaLaboral = oferta;
	nuevaReservacion.postulante = postulante;
	nuevaReservacion.fecha = fecha;
	nuevaReservacion.esContratado = false;

	return nuevaReservacion;
}
/**
 * Muestra los datos de una reservación
*/
void mostrarReservacion(Reservacion reservacion) {
	std::cout << std::endl << "Identificador: " << reservacion.codigo << std::endl;
	mostrarOfertaLaboral(reservacion.ofertaLaboral);
	mostrarFecha(reservacion.fecha);
	mostrarPostulante(reservacion.postulante);
}
