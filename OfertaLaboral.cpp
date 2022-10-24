////#include <string>
// #include "./Fecha.cpp"

typedef struct {
    int codigo;
    float  salarioBase;
    Fecha fechaPublicada;
    Fecha fechaInicio;
    std::string vacante;
    std::string ocupacion;
} OfertaLaboral;

void mostrarOfertaLaboral(OfertaLaboral oferta) {
    std::cout << std::endl << "OFERTA LABORAL " << oferta.codigo << std::endl;
    std::cout << "Salario base: " << oferta.salarioBase << std::endl;
    std::cout << "Fecha publicada: ";
    mostrarFecha(oferta.fechaPublicada);
    std::cout << std::endl;
    std::cout << "Fecha publicada: ";
    mostrarFecha(oferta.fechaPublicada);
    std::cout << std::endl;
    
}

