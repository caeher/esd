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
    return false;
}

bool validDia(int dia) {
    return false;
}

bool validYear(int year) {
    return false;
}