/*
 *
 */

#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

template <class T> class Lista
{
protected:
    Nodo<T>* cabeza = NULL;

public:
    Lista();
    void crearLista();
    void insertar(T* pData);
    void visualizar();
};


template <class T> void Lista<T>::insertar(T *pData)
{
    if(cabeza == NULL)
    {
        cabeza = new Nodo<T>(pData);
    }
    else
    {
        Nodo<T>* tmp = cabeza;
        cabeza = new Nodo<T>(pData);
        cabeza->setSiguiente() = tmp;
    }
}


#endif // LISTA_H
