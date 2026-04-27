
#include <string>
using namespace std;

class Nodo {
private:
    string valor;
    Nodo* sig;

public:
    // constructor
    Nodo(const string& v);

    // getters y setters
    string getValor();
    void setValor(const string& v);

    Nodo* getSig();
    void setSig(Nodo* siguiente);
};

