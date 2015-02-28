#ifndef NODO_H //guards
#define NODO_H //guards

#include <iostream>
using namespace std;

/*
 * Clase Nodo
 * Forma parte de una lista simple
 * atributos : dato, next
 * metodos nodo(), getData(), setData(), printData(), setNext(); getNext();
 */
template <typename T> class nodo {

private:
    T dato = NULL;          // tipo de dato propio
    nodo<T>* next = NULL;   //puntero al siguiente nodo

public:

    /*
    *Constructor
    * argumentos: T pData
    */
    nodo(T pData){    dato = pData;};


    /*
     * Retorna el dato almacenado en el nodo
    */
    T getData()
    {
        return dato;
    }

    /*
    * Modifica directamente el dato guardado en el nodo
    */
    void setData(T pData)
    {
        dato = pData;
    };

    /*
     * Por medio de iostrem, imprimimos el dato del nodo
    */
    void printData()
    {
        cout << dato << "\n";
    };

    /*
     * Modificar el puntero hacia el siguiente nodo
     * argumentos: nodo<T>* puntero hacia otro nodo
    */
    void setNext(nodo<T> *pData)
    {
        next = pData;
    };

    /*
     * Retorna el puntero hacia el siguiente nodo
    */
    nodo<T>* getNext()
    {
        return next;
    }

};



#endif // NODO_H guards
