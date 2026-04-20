Pila.h
#pragma once
#include <string>
#include "nodo.h"
using namespace std;

class Pila {
private:
    nodo* inicio;

public:
    Pila();
    void push();
    void pop();
    void show();
    void top();
    void size();
};
