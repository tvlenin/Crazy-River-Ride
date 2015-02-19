#ifndef NODO_H
#define NODO_H

class nodo
{

private:
    int data;
    nodo* siguiente;

public:
    nodo(int pData)
    {
        data = pData;
        siguiente = NULL;
    }

    void setSiguiente(nodo* pSiguiente){
        siguiente = pSiguiente;
    }

    nodo* getSiguiente()
    {
        return siguiente;
    }

    int getData()
    {
        return data;
    }
};

#endif // NODO_H
