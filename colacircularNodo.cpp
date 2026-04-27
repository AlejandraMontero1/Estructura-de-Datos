#include "Nodo.h"

Nodo::Nodo(const string& v) {
    valor = v;
    sig = nullptr;
}

string Nodo::getValor() {
    return valor;
}

void Nodo::setValor(const string& v) {
    valor = v;
}

Nodo* Nodo::getSig() {
    return sig;
}

void Nodo::setSig(Nodo* siguiente) {
    sig = siguiente;
}
