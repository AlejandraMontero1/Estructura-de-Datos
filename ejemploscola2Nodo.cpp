#include "nodo.h"

Nodo::Nodo(DATA_TYPE valor) {
    data = valor;
    next = NULL;
}

DATA_TYPE Nodo::getData() {
    return data;
}

void Nodo::setData(DATA_TYPE valor) {
    data = valor;
}

Nodo* Nodo::getNext() {
    return next;
}

void Nodo::setNext(Nodo* siguiente) {
    next = siguiente;
}
