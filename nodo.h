#ifndef NODO_H
#define NODO_H

template <class T> class Nodo
{

protected:
    T dato = NULL;
    Nodo<T>* siguiente = NULL;

public:
    Nodo(T* pData)
    {
        dato = pData;
        siguiente = 0;
    }

    Nodo(T pData, Nodo<T>* siguiente)
    {
        dato = pData;
        siguiente = siguiente;
    }

    void setSiguiente(Nodo<T>* pSiguiente)
    {
        siguiente = pSiguiente;
    }

    T* getDato() const
    {
        return dato;
    }

    Nodo<T>*& getSiguiente()const
    {
        return siguiente;
    }
};

#endif // NODO_H
