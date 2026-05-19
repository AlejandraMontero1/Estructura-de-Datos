#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Amigo {
private:
    string nombre;
    int edad;
    char sexo;
    char estado; // A = activo, E = eliminado

public:
    Amigo();
    Amigo(string nom, int ed, char sx);

    void setAmigo(string nom, int ed, char sx);

    string getNombre();
    int getEdad();
    char getSexo();
    char getEstado();

    void guardarArchivo(ofstream &fsalida);
    bool leerArchivo(ifstream &fentrada);

    bool buscar(ifstream &fentrada, int nroReg);
    bool eliminar(fstream &fes, int nroReg);
    bool modificar(fstream &fes, int nroReg);

    int getTamBytesRegistro();
};
