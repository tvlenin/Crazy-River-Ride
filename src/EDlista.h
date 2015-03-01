#ifndef LISTA_H
#define LISTA_H

#include "EDnodo.h"

/*
 * Clase template lista
 * atributos: nodo<T>* cabeza
 * metodos: lista(), insertar(), ver(), eliminar()
*/
template <typename T> class lista {

private:
    nodo<T>* cabeza;        //apuntador al nodo utilizado como cabeza

public:
    /*
     * Lista::lista()
     * constructor, apunta la cabeza a null
    */
    lista()
    {
        cabeza = 0;
    }

    /*
     * lista::insertar(T pData)
     * argumento: T pData
     * Sirve para insertar, ya sea el primer nodo o cualquier otro
    */
    void insertar(T* pData)
    {
        nodo<T> *newTmp = new nodo<T>(pData);
        if(cabeza == 0)
        {
            cabeza = newTmp;
        }else{
            newTmp->setNext(cabeza);
            cabeza = newTmp;
        };
    }

    /*
     * lista::ver()
     * por iostream imprimimos el valor de cada nodo
    */
    void ver()
    {
        nodo<T> *iterador = cabeza;
        while(iterador != NULL)
        {
            cout <<"Nodo :" << *(iterador->getData()) <<"\n";
            iterador = iterador->getNext();
        }
        cout << "Termine de imprimir la lista \n \n";
    }


    /*
     * lista::eliminar(T pData)
     * Busca el dato, si no esta se completa, de caso contrario
     * mantiene un apuntador al nodo previo para unirlo con el siguiente
     * al que se quiera eliminar
    */
    void eliminar(T pData)
    {
        nodo<T>* tmp = cabeza;
        nodo<T>* previo = cabeza;

        if (tmp == NULL){
            cout << "Elemento a borarr no esta, Lista eliminar";
            return;
        }

        while(tmp != NULL && ((*tmp).getData() != pData) )
        {
            previo = tmp;
            tmp = tmp->getNext();
        }
        if(tmp == cabeza){
            cabeza = cabeza->getNext();
            delete tmp;
            return;
        }
        if(tmp != NULL)
        {
            previo->setNext(tmp->getNext());
            delete tmp;
        }else{
            return;
        }
    }

    nodo<T>* getCabeza()
    {
        return this->cabeza;
    }
};

#endif // LISTA_H
