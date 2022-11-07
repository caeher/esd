#include <string>
/**
 * Limpia la pantalla en consola
*/
void limpiarPantalla() {
	system("cls");
}
/**
 * Función que se encarga de imprimir un menu
*/
void menu (std::string *menu, std::string title, int size) {
    std::cout << "*******************" << title << "*******************" << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << (i + 1) << ". " << menu[i] << std::endl;
    }
}
/**
 * Se encarga de validar que una  cadena insertada no este vacia
*/
bool validarCadena(std::string cadena) {
	return cadena != "";
}
std::string pedirCadena() {
	std::string cadena = "";
	bool flag = true;
	while(flag) {
		std::cout << std::endl << "Escriba aqui: " ;
		getline(std::cin, cadena);
		if(cadena.length() > 0) 
			flag = false;
		else 
			std::cout << std::endl << "No debe ingresar un texto vacia" << std::endl;
	}
	return cadena;
}
/**
 * Convierte un número flotante_cadena a un número flotante
*/
float convertirFlotante (std::string cadena) {
	float num = 0.0;
	sscanf(cadena.c_str(), "%f", &num);
	return num;
}
/**
 * Convierte un número entero_cadena a un número entero
*/
float convertirEntero(std::string cadena) {
	int num = 0;
	sscanf(cadena.c_str(), "%d", &num);
	return num;
}
