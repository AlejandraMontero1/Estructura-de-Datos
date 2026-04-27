#include "nodo.h"

class QueueDin {

    int ITEMS;
    Nodo *cola, *cabeza;

public:
    QueueDin();
    ~QueueDin();

    DATA_TYPE put(DATA_TYPE valor);
    int empty();
    DATA_TYPE get();
};
