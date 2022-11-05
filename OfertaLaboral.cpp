////#include <string>
// #include "./Fecha.cpp"
#include <string.h>
int contadorIdOferta = 0;
struct OfertaLaboral{
    int codigo;
    float  salarioBase;
    Fecha fechaPublicada;
    Fecha fechaInicio;
    std::string vacante;
    std::string ocupacion;
    bool operator==(const OfertaLaboral &item) const{
        return codigo == item.codigo;
    }
} ;

void mostrarOfertaLaboral(OfertaLaboral oferta) {
    std::cout << std::endl << "OFERTA LABORAL " << oferta.codigo << std::endl;
    std::cout << "Salario base: " << oferta.salarioBase << std::endl;
    std::cout << "Fecha publicada: ";
    mostrarFecha(oferta.fechaPublicada);
    std::cout << std::endl;
    std::cout << "Fecha publicada: ";
    mostrarFecha(oferta.fechaPublicada);
    std::cout << std::endl << "Vacantes: " << oferta.vacante;
    std::cout << std::endl << "Ocupacion: " << oferta.ocupacion;
    std::cout << std::endl;
}

OfertaLaboral pedirOfertaLaboral() {
    OfertaLaboral nuevaOferta;
    bool flag = true;
    std::string auxCad = "", cad;
    int opcion = 0;
    float salario = 0.0;
    nuevaOferta.codigo = ++contadorIdOferta;
    while(flag) {
        std::cout << std::endl << "Ingrese el salario base: ";
        cad = pedirCadena();
        salario = convertirFlotante(cad);
        if(salario > 0) {
            flag = false;
        }else {
            std::cout << std::endl << "Debe ingresar un sallario valido";
        }
    }

    nuevaOferta.salarioBase = salario;
    std::cout << std::endl << "Ingrese la fecha de publicacion de la oferta";
    nuevaOferta.fechaPublicada = pedirFecha();
    std::cout << std::endl << "Ingrese la fecha de inicio del  trabajo de la oferta";
    nuevaOferta.fechaInicio = pedirFecha();
    std::cout << std::endl << "Ingrese el numero de vacantes";
    nuevaOferta.vacante = pedirCadena();
    std::cout << std::endl << "Ingrese la ocupacion necesaria de la oferta laboral";
    nuevaOferta.ocupacion = pedirCadena();

    return nuevaOferta;
}

