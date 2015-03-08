
#include <cstdlib>
#include <iostream>

#include "lista.h"
#include "nodo.h"

using namespace std;

lista::lista()
{
    cabeza = NULL;
    tmp = NULL;
    current = NULL;
}

void lista::insertar(int pData)
{
    nodo* nuevo = new nodo(pData);
    if(cabeza == NULL)
    {
        cabeza = nuevo;
    }else{
        tmp = cabeza;
        cabeza = nuevo;
        cabeza->setSiguiente(tmp);
    }
}

void lista::eliminar(int pData)
{
    nodo* eliminar = NULL;
    tmp = cabeza;
    current = cabeza;

    while(current != NULL && current->getData() != pData)
    {
        tmp = current;
        current = current->getSiguiente();
    }

    if(current == NULL)
    {

        cout <<"No estaba \n";
        delete eliminar;
    }
    else
    {
        eliminar = current;
        current = current->getSiguiente();
        tmp->setSiguiente(current);
        if (eliminar == cabeza)
        {
            cabeza = cabeza->getSiguiente();
            tmp = NULL;
        }
        cout <<"Borramos: "<<eliminar->getData()<<" se borro\n";
        delete eliminar;
    }


}

nodo* lista::getCabeza()
{
    return cabeza;
}

void lista::ver()
{
    nodo* tmp1 = cabeza;
    while(tmp1 != NULL)
    {
        cout << tmp1->getData()<<"\n";
        tmp1 = tmp1->getSiguiente();
    }
    cout << "Impresa \n \n";

}
