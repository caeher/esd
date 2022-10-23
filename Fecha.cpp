typedef struct {
    int dia;
    int mes;
    int year;
} Fecha;

bool isBisiestro (int year) {
    return (year % 4 && (year%100 != 0 || year%400 == 0));
}

Fecha pedirFecha() {
    Fecha nuevaFecha;
    return nuevaFecha;
}

bool validMes(int mes) {
    return mes >0 && mes <=12;
}

bool validDia(Fecha fecha) {
    if(isBisiestro(fecha.year)) 
        return fecha.dia > 0 && fecha.dia <= 28;
    else 
        return fecha.dia > 0 && fecha.dia <= 31;
}

bool validYear(int year) {
    return year > 2000;
}