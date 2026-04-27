typedef char DATA_TYPE;

class Nodo {
private:
    DATA_TYPE data;
    Nodo* next;

public:
    // constructor
    Nodo(DATA_TYPE valor);

    // getters y setters
    DATA_TYPE getData();
    void setData(DATA_TYPE valor);

    Nodo* getNext();
    void setNext(Nodo* siguiente);
};
