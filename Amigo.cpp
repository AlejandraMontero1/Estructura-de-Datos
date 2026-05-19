#include "Amigo.h"

Amigo::Amigo() {
    nombre = "";
    edad = 0;
    sexo = ' ';
    estado = ' ';
}

Amigo::Amigo(string nom, int ed, char sx) {
    nombre = nom;
    edad = ed;
    sexo = sx;
    estado = 'A';
}

void Amigo::setAmigo(string nom, int ed, char sx) {
    nombre = nom;
    edad = ed;
    sexo = sx;
    estado = 'A';
}

string Amigo::getNombre() { return nombre; }
int Amigo::getEdad() { return edad; }
char Amigo::getSexo() { return sexo; }
char Amigo::getEstado() { return estado; }

void Amigo::guardarArchivo(ofstream &fsalida) {

    size_t tam;

    tam = nombre.size();
    fsalida.write((char*)&tam, sizeof(tam));
    fsalida.write(nombre.c_str(), tam);

    fsalida.write((char*)&edad, sizeof(edad));
    fsalida.write((char*)&sexo, sizeof(sexo));
    fsalida.write((char*)&estado, sizeof(estado));
}

bool Amigo::leerArchivo(ifstream &fentrada) {

    size_t tam;
    char buffer[100];

    if (!fentrada.read((char*)&tam, sizeof(tam)))
        return false;

    fentrada.read(buffer, tam);
    buffer[tam] = '\0';
    nombre = buffer;

    fentrada.read((char*)&edad, sizeof(edad));
    fentrada.read((char*)&sexo, sizeof(sexo));
    fentrada.read((char*)&estado, sizeof(estado));

    return true;
}

int Amigo::getTamBytesRegistro() {
    return sizeof(nombre) + sizeof(edad) + sizeof(sexo) + sizeof(estado);
}

// BUSCAR
bool Amigo::buscar(ifstream &fentrada, int nroReg) {

    fentrada.seekg(0, ios::beg);

    for (int i = 1; i <= nroReg; i++) {
        if (!leerArchivo(fentrada))
            return false;
    }
    return true;
}

// ELIMINAR
bool Amigo::eliminar(fstream &fes, int nroReg) {

    fes.seekg(0, ios::beg);

    streampos pos;

    for (int i = 1; i <= nroReg; i++) {

        pos = fes.tellg();

        size_t tam;
        if (!fes.read((char*)&tam, sizeof(tam)))
            return false;

        char buffer[100];
        fes.read(buffer, tam);

        fes.read((char*)&edad, sizeof(edad));
        fes.read((char*)&sexo, sizeof(sexo));
        fes.read((char*)&estado, sizeof(estado));
    }

    estado = 'E';

    fes.seekp(pos);

    size_t tam = nombre.size();

    fes.write((char*)&tam, sizeof(tam));
    fes.write(nombre.c_str(), tam);

    fes.write((char*)&edad, sizeof(edad));
    fes.write((char*)&sexo, sizeof(sexo));
    fes.write((char*)&estado, sizeof(estado));

    return true;
}

// MODIFICAR
bool Amigo::modificar(fstream &fes, int nroReg) {

    fes.seekg(0, ios::beg);

    streampos pos;

    for (int i = 1; i <= nroReg; i++) {

        pos = fes.tellg();

        size_t tam;
        if (!fes.read((char*)&tam, sizeof(tam)))
            return false;

        char buffer[100];
        fes.read(buffer, tam);

        fes.read((char*)&edad, sizeof(edad));
        fes.read((char*)&sexo, sizeof(sexo));
        fes.read((char*)&estado, sizeof(estado));
    }

    estado = 'A';

    fes.seekp(pos);

    size_t tam = nombre.size();

    fes.write((char*)&tam, sizeof(tam));
    fes.write(nombre.c_str(), tam);

    fes.write((char*)&edad, sizeof(edad));
    fes.write((char*)&sexo, sizeof(sexo));
    fes.write((char*)&estado, sizeof(estado));

    return true;
}
