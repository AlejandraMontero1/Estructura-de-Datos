#include <iostream>
#include "ColaCircular.h"

using namespace std;

ColaCircular::ColaCircular() {
    frente = nullptr;
    final = nullptr;
}

ColaCircular::~ColaCircular() {
    while (!estaVacia()) {
        desencolar();
    }
}

void ColaCircular::encolar(const string& valor) {
    Nodo* nuevo = new Nodo(valor);

    if (!frente) {
        frente = final = nuevo;
        nuevo->setSig(nuevo); // se apunta a sí mismo
    } else {
        nuevo->setSig(frente);
        final->setSig(nuevo);
        final = nuevo;
    }
}

string ColaCircular::desencolar() {
    if (estaVacia()) return "COLA VACÍA";

    string dato;

    if (frente == final) {
        dato = frente->getValor();
        delete frente;
        frente = final = nullptr;
    } else {
        Nodo* temp = frente;
        dato = temp->getValor();
        frente = frente->getSig();
        final->setSig(frente);
        delete temp;
    }

    return dato;
}

bool ColaCircular::estaVacia() {
    return frente == nullptr;
}

void ColaCircular::mostrar() {
    if (estaVacia()) {
        cout << "Cola vacía.\n";
        return;
    }

    Nodo* actual = frente;
    cout << "Cola: ";

    do {
        cout << "[" << actual->getValor() << "] ";
        actual = actual->getSig();
    } while (actual != frente);

    cout << endl;
}
