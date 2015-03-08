#include "GUIEnemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // libreria para utilizar el metodo rand()
#include "GameGUI.h"
#include <unistd.h>
#include <pthread.h>
#include <chrono>
#include<time.h>


extern GameGUI * gameGUI; // Crea un objeto del tipo game
static void *hello_helper(void *context)
    {
        return ((GUIEnemy *)context)->move();


    }
//Crea un Enemy del tipo QGraphicsPixmap
GUIEnemy::GUIEnemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //posiciona el Enemy en una posicion aleatoria
    int random_number = rand() % 700;
    setPos(random_number,random_number-300);

    //Crea un objeto Pixmap que seria un enemigo
    setPixmap(QPixmap(":/images/enemy.png"));
    //***********************************************Buscar que hace esto
    pthread_create(&tl,NULL, &hello_helper,this);

}
// Maneja los movimientos de los enemigos *******Aqui hay que agregar distintos tipos de movimientos
void *GUIEnemy::move(void){
    while(true){
        usleep(80000);
    setPos(x(),y()+10);
    // Destruye el enemigo una vez se salio de la pantalla*
    if (pos().y() > 600){

         //game->health->decrease();
        //elimina la nave enemiga
        scene()->removeItem(this);
        delete this;
        return 0 ;

    }
  }
}
