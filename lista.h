#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class lista
{
protected:
    nodo* cabeza;
    nodo* tmp;
    nodo* current;

public:
    lista();

    void insertar(int pData);
    void eliminar(int pData);
    nodo* getCabeza();
    void ver();

};
#endif // LISTA_H
