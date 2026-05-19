#include "ABMamigo.h"

ABMamigo::ABMamigo(string nomArch) {
    nomArchivo = nomArch;
}

void ABMamigo::introducirDatos(Amigo *newReg) {

    string nombre;
    int edad;
    char sexo;

    cin.ignore();

    cout << "\nNombre: ";
    getline(cin, nombre);

    cout << "Edad: ";
    cin >> edad;

    cout << "Sexo (F/M): ";
    cin >> sexo;

    newReg->setAmigo(nombre, edad, sexo);
}

void ABMamigo::mostrarRegistro(int nroReg) {

    cout << "\n" << nroReg << ".- "
         << amig->getNombre() << " "
         << amig->getEdad() << " "
         << amig->getSexo() << " "
         << amig->getEstado();
}

void ABMamigo::adicionarNuevo() {

    ofstream fsalida(nomArchivo, ios::app | ios::binary);

    amig = new Amigo();

    introducirDatos(amig);

    amig->guardarArchivo(fsalida);

    fsalida.close();

    cout << "\nRegistro guardado";
}

void ABMamigo::listar() {

    int cr = 0;

    cout << "\n===== LISTA =====";

    amig = new Amigo();

    ifstream fentrada(nomArchivo, ios::in | ios::binary);

    while (amig->leerArchivo(fentrada)) {

        cr++;

        if (amig->getEstado() == 'A') {

            mostrarRegistro(cr);
        }
    }

    fentrada.close();
}

int ABMamigo::buscarReg() {

    int nroReg;

    cout << "\nNumero de registro: ";
    cin >> nroReg;

    amig = new Amigo();

    ifstream fentrada(nomArchivo, ios::in | ios::binary);

    if (amig->buscar(fentrada, nroReg)) {
        mostrarRegistro(nroReg);
    } else {
        cout << "\nRegistro no existe";
        nroReg = -1;
    }

    fentrada.close();

    return nroReg;
}

void ABMamigo::eliminarReg() {

    int nroReg = buscarReg();

    if (nroReg > 0) {

        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);

        amig = new Amigo();

        if (amig->eliminar(fes, nroReg)) {
            cout << "\nEliminado correctamente";
        }

        fes.close();
    }
}

void ABMamigo::modificarReg() {

    int nroReg = buscarReg();

    if (nroReg > 0) {

        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);

        amig = new Amigo();

        introducirDatos(amig);

        if (amig->modificar(fes, nroReg)) {
            cout << "\nModificado correctamente";
        }

        fes.close();
    }
}
