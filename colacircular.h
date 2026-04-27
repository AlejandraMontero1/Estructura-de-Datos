
#include "Nodo.h"

class ColaCircular {
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaCircular();
    ~ColaCircular();

    void encolar(const string& valor);
    string desencolar();

    bool estaVacia();
    void mostrar();
};

