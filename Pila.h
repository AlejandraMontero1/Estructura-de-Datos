
#pragma once
#include "NODO.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class PILA {
    NODO* inicio;

public:
    PILA();
    void push();
    void pop();
    void show();
    void top();
    void size();
};
