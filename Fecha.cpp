#include <string> 

struct Fecha{
    int dia;
    int mes;
    int year;
    std::string hora;
    bool operator==(const Fecha &item) {
        return (dia == item.dia && mes == item.mes && year == item.year);
    };
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
    std::cout << fecha.dia << "/" << fecha.mes << "/" << fecha.year << " - " << fecha.hora;
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
            std::cout << std::endl << "Digite el year: ";
            cadena = pedirCadena();
            aux = convertirEntero(cadena);
            if(validYear(aux)) {
                nuevaFecha.year = aux;
                who = 2;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un year valido";
            }
        }
        if(who == 2) {
            std::cout << std::endl << "Digite el mes: ";
            cadena = pedirCadena();
            aux = convertirEntero(cadena);
            if(validMes(aux)) {
                nuevaFecha.mes = aux;
                who = 3;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un mes valido";
            }
        }
        if(who == 3) {
            std::cout << std::endl << "Digite el dia: ";
            cadena = pedirCadena();
            aux = convertirEntero(cadena);
            nuevaFecha.dia = aux;
            if(validDia(nuevaFecha)) {
                who = 4;
                continue;
            }else {
                std::cout << std::endl << "Debe ingresar un dia valido";
            }
        }
        if(who == 4) {
            std::cout << std::endl << "Digite la hora: ";
            cadena = pedirCadena();
            if(cadena != "") {
                nuevaFecha.hora = cadena;
            }else {
                std::cout << std::endl << "No se aceptan datos vacios";
            }
            flag = false;
        }
    }

    return nuevaFecha;
}
