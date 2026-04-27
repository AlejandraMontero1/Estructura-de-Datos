#include <string>
using namespace std;

#define MAX 10

class ColaCircular {
private:
    string datos[MAX];
    int frente;
    int fin;
    int cantidad;

public:
    ColaCircular();

    bool estaLlena();
    bool estaVacia();

    bool encolar(string valor);
    string desencolar();

    void mostrar();
};

#endif
