template<typename T>
struct Lista {
    T dato;
    Lista *siguiente;
};

template<typename T>
void pushLista(Lista<T> *&lista, T dato) {
    Lista<T> *nueva = new Lista<T>();

    Lista<T> *temp1, *temp2;
    temp1 = lista;
    nueva->dato = dato;
    while(temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->siguiente;
    }
    if(lista == temp1){
        lista = nueva;
    }else {
        temp2->siguiente= nueva;
    }

    nueva->siguiente = temp1;
}

template <typename T>
void deleteLista(Lista<T> *&lista, T dato) {
    if(lista != NULL) {
        Lista<T> *tempBorrar;
        Lista<T> *anterior = NULL;
        tempBorrar = lista;

        while((tempBorrar != NULL) && tempBorrar->dato == dato) {
            anterior = tempBorrar;
            tempBorrar = tempBorrar->siguiente;
        }

        if(tempBorrar == NULL) {
            std::cout << std::endl << "El valor buscado no existe";
        }else if(anterior == NULL) {
            lista = lista->siguiente;
            delete (tempBorrar);
        } else {
            anterior->siguiente = tempBorrar->siguiente;
            delete (tempBorrar);
        }
    }
}


template <typename T>
bool isLista(Lista<T> *&lista, T dato) {
    bool isIn = false;
    Lista<T> *aux = lista;
    while(lista != NULL) {
        if(lista->dato == dato)
            isIn = true;
        lista = lista->siguiente;
    }
    lista = aux;
    return isIn;
}

template <typename T>
T getLista(Lista<T> *&lista, T dato) {
    T resultado;
    Lista<T> *aux = lista;
    while(lista != NULL) {
        if(lista->dato == dato) {
            resultado = lista->dato;
        }
        lista = lista->siguiente;
    }
    lista = aux;
    return resultado;
}

