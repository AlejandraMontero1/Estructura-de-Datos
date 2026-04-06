#include <iostream>
#include "pila.h"

using namespace std;

Pila::Pila()
{
    cima = -1;
}

bool Pila::Apilar(TipoDato &elemento)
{
    if (cima == MAX - 1)
    {
        cout << "Overflow" << endl;
        return false;
    }

    cima++;
    pila[cima] = elemento;
    return true;
}

bool Pila::Desapilar()
{
    if (cima == -1)
    {
        cout << "Underflow" << endl;
        return false;
    }

    cima--;
    return true;
}

bool Pila::CimaPila(TipoDato &elemento)
{
    if (PilaVacia())
        return false;

    elemento = pila[cima]; // corregido
    return true;
}

bool Pila::PilaVacia()
{
    return cima == -1;
}

void Pila::LimpiarPila()
{
    cima = -1;
}

void Pila::VerPila()
{
    for (int i = 0; i <= cima; i++)
        cout << pila[i] << endl;
}

bool Pila::Iguales(Pila p)
{
    if (cima != p.cima)
        return false;

    for (int i = 0; i <= cima; i++)
    {
        if (pila[i] != p.pila[i])
            return false;
    }

    return true;
}
