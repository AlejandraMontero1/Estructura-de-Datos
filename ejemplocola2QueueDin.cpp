#include "QueueDin.h"

QueueDin::QueueDin() {
    cola = NULL;
    cabeza = NULL;
    ITEMS = 0;
}

QueueDin::~QueueDin() {}

DATA_TYPE QueueDin::put(DATA_TYPE valor)
{
    Nodo *temp = new Nodo(valor);

    if (temp == NULL) return -1;

    ITEMS++;

    if (cabeza == NULL) {
        cabeza = temp;
        cola = temp;
    } else {
        cola->setNext(temp);
        cola = temp;
    }

    return valor;
}

int QueueDin::empty() {
    return ITEMS == 0;
}

DATA_TYPE QueueDin::get()
{
    if (empty()) return -1;

    DATA_TYPE d = cabeza->getData();
    Nodo *temp = cabeza->getNext();

    delete cabeza;
    cabeza = temp;

    ITEMS--;

    return d;
}
