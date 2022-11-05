#include <string> 

struct Fecha{
    int dia;
    int mes;
    int year;
    bool operator==(const Fecha &item) {
        return (dia == item.dia && mes == item.mes && year == item.year);
    }
};
/** 
 * Funcion que permite comprobar si un año en especifico es bisiestro
 * @return bool
*/
bool esBisiestro (int year) {
    return !(year % 4 && (year%100 != 0 || year%400 == 0));
}


/**
 * Funcion que valida que el mes ingresado se valido
 * @return bool
*/
bool validMes(int mes) {
    return mes >0 && mes <=12;
}

/**
 * Funcion que permite validar un dia insertado
 * @return bool
*/
bool validDia(Fecha fecha) {
    bool valid = false;
    if(esBisiestro(fecha.year)) {
        if(fecha.mes == 2) 
            valid = fecha.dia > 0 && fecha.dia <= 29;
        else 
            valid = fecha.dia > 0 && fecha.dia <=31;
        
    }else {
        if(fecha.mes == 2) 
            valid = fecha.dia > 0 && fecha.dia <= 28;
        else 
            valid = fecha.dia > 0 && fecha.dia <=31;
    }
    return valid;    
}

/**
 * Funcion que permite validar el año que se ha ingresado
 * @return bool
*/
bool validYear(int year) {
    return year > 2000;
}

/**
 * Funcion que imprime una fecha
*/
void mostrarFecha(Fecha fecha) {
    std::cout << fecha.dia << "/" << fecha.mes << "/" << fecha.year;
}


/** 
 * Funcion que permite pedir una fecha ya validada
 * @return Fecha
*/
Fecha pedirFecha() {
    Fecha nuevaFecha;
    bool flag = true;
    int who = 1, aux;
    std::string cadena;
    while(flag) {
        if(who == 1) {
            std::cout << std::endl << "Digite el año: ";
            std::getline(std::cin, cadena);
            sscanf(cadena.c_str(), "%d", &aux);
            if(validYear(aux)) {
                nuevaFecha.year = aux;
                who = 2;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un año valido";
            }
        }
        if(who == 2) {
            std::cout << std::endl << "Digite el mes: ";
            std::getline(std::cin, cadena);
            sscanf(cadena.c_str(), "%d", &aux);
            if(validMes(aux)) {
                nuevaFecha.mes = aux;
                who = 3;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un mes valido";
            }
        }
        if(who == 3) {
            std::cout << std::endl << "Digite el día: ";
            std::getline(std::cin, cadena);
            sscanf(cadena.c_str(), "%d", &aux);
            nuevaFecha.dia = aux;
            if(validDia(nuevaFecha)) {
                flag = false;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un día valido";
            }
        }
    }

    return nuevaFecha;
}
