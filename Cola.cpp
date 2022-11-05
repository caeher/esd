/**
 * 
 * 
 * */

template<typename T>
struct Cola {
    T dato;
    Cola<T> *siguiente;
};

template<typename T>
bool emptyCola(Cola<T> ** cola) {
    return *cola == NULL;
}

template<typename T>
void pushCola(Cola<T> ** primero, Cola<T> **ultimo, T dato) {
    Cola<T> * nuevo = new Cola<T>();
    if(nuevo != NULL) {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        if(emptyCola(primero)) {
            *primero = nuevo;
            
        } else {
            (*ultimo)->siguiente = nuevo;
        }
        *ultimo = nuevo;
    }else {
        std::cout << std::endl << "Elemento no agregado. Memoria insuficiente." << std::endl;
    }
}

template<typename T>
T popCola(Cola<T> **primero, Cola<T> **ultimo) {
    Cola<T> * pc, *fc, *q = new Cola<T>();
    T dato;
    pc = *primero;
    fc = *ultimo;

    if(pc != NULL) {
        q = pc;
        dato = q->dato;
        pc = pc->siguiente;
        if(pc == NULL)
            fc = NULL;
        delete(q);
        *primero = pc;
        *ultimo = fc;
    }else {
        std::cout << std::endl << "No hay elementos";
    }
    return dato;
}
