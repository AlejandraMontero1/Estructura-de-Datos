Pila.cpp
#include "Pila.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Pila::Pila() {
    inicio = NULL;
}

void Pila::push() {
    int id;
    string modelo;

    nodo* aux = new nodo;

    system("cls");
    cout << "Ingresa el ID del auto: ";
    cin >> id;
    cout << "Ingresa el modelo del auto: ";
    cin.ignore();
    getline(cin, modelo);

    aux->idAuto = id;
    aux->modelo = modelo;
    aux->sig = inicio;

    inicio = aux;

    cout << "Auto insertado en la pila!\n";
    system("pause");
}

void Pila::pop() {
    if (inicio == NULL) {
        cout << "\nLa pila esta vacia!\n";
    }
    else {
        nodo* temp = inicio;
        inicio = inicio->sig;

        cout << "\nAuto eliminado: " << temp->idAuto << " - " << temp->modelo << endl;

        delete temp;
    }
    system("pause");
}

void Pila::show() {
    if (inicio == NULL) {
        cout << "\nLa pila esta vacia!\n";
    }
    else {
        nodo* aux = inicio;
        cout << "\nAutos en la pila:\n";
        while (aux != NULL) {
            cout << aux->idAuto << " - " << aux->modelo << endl;
            aux = aux->sig;
        }
    }
    system("pause");
}

void Pila::top() {
    if (inicio == NULL) {
        cout << "\nLa pila esta vacia!\n";
    }
    else {
        cout << "\nAuto en el tope:\n";
        cout << inicio->idAuto << " - " << inicio->modelo << endl;
    }
    system("pause");
}

void Pila::size() {
    int contador = 0;
    nodo* aux = inicio;

    while (aux != NULL) {
        contador++;
        aux = aux->sig;
    }

    cout << "\nCantidad de autos: " << contador << endl;
    system("pause");
}
