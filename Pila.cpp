/**
 *  Como usar
 *  Crear una variable puntero especificando el tipo de datos que se va a procesar
 *  Pila<TYPOAQUI> * pilaTipo;
 * 	Para insertar datos
 *	pushStack(pilaTipo, DATO_DE_TYPOAQUI);
 *  Para Eliminar datos
 * 	TYPOAQUI dato = pop(pilaTipo);
 * 
 * */

template<typename T>

struct Pila{
    T dato;
    Pila<T> *siguiente;
};

/**
 * Se crea un nuevo nodo
*/
template<typename T>
Pila<T> * crearNodoStack(T dato) {
	Pila<T> *nuevoNodo = new Pila<T>;
	nuevoNodo->dato = dato;
	return nuevoNodo;
}

/**
 * Función que permite insertar un nuevo dato a la pila
*/
template<typename T>
void pushStack(Pila<T> *&pila, T dato) {
    Pila<T> *nuevo  = crearNodoStack(dato);
    nuevo->siguiente = pila;
    pila = nuevo;
}
/**
 * Función que borra un dato de la pila y devuelve el dato eliminado
*/
template<typename T>
T popStack(Pila<T> *&pila) {
    T dato;
    Pila<T> *aux;
    aux = pila;
    dato = aux->dato;
    pila = aux->siguiente;
    delete(aux);
    return dato; 
}


