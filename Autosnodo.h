nodo.h
#pragma once
#include <string>
#include <iostream>
using namespace std;

class nodo {
public:
    int idAuto;
    string modelo;
    nodo* sig;
};
