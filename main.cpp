#include <QCoreApplication>
#include <iostream>

#include "lista.h"
#include "nodo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    lista l;

    l.insertar(1);
    l.insertar(2);
    l.insertar(3);

    l.eliminar(3);

    cout<<"\n";
    l.ver();
    return a.exec();
}
