#include "GUIBullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "GUIEnemy.h"
#include <errno.h>
#include "GameGUI.h"
#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <QDebug>
#include <unistd.h>
#include <pthread.h>
#include <chrono>
#include <time.h>
using namespace std;
extern GameGUI * gameGUI; // Crea un objeto del tipo game
#define NUM_THREADS     5



static void *hello_helper(void *context)
    {

           return ((GUIBullet*)context)->move();


    }




GUIBullet::GUIBullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/bullet.png"));// indica que cada bala va a ser cierta imagen.



    int param = 4;

     pthread_create(&tl,NULL, &hello_helper,this);
     std::cout<<&tl<<endl;
     //pthread_join(tl,NULL);
     //pthread_exit(NULL);
    //return 1;
}




 void *GUIBullet::move(void){
    int vida = 1;
    //pthread_mutex_lock(&mutex);
     while(vida == 1){
      //   pthread_mutex_unlock(&mutex);
         usleep(100000);
         // pthread_mutex_lock(&mutex);

         //pthread_cond_wait(t < 100);
        std::cout<<y()-2<<endl;
        if(y()-0 > 0)
            setPos(x(),y()-2);
        //if (pos().y() + pixmap().height() < 100){

           //  scene()->removeItem(this);
             //pthread_mutex_unlock(&mutex);
             //delete this;

             //std::cout<<"se salio la bala"<<endl;

             //usleep(200000);
             //return 0;
             //vida = 0;
             //vida--;

         //}
        //pthread_mutex_unlock(&mutex);

     }


         //Lista de los objetos que colisionan con esta bala
         // *******************************************************************Aqui entra abraham con sus listas y hay que hacer
         //un codigo para no utilizar esto de collindeing_items, entonces pienso que hay que hacer hilos para comparar las balas
         //QList<QGraphicsItem *> colliding_items = collidingItems();

         //Si una de las colisiones es contra un enemigo se destruyen ambos
//         for (int i = 0, n = colliding_items.size(); i < n; ++i){
//             if (typeid(*(colliding_items[i])) == typeid(Enemy)){
//                 // Se incrementa el puntaje
//                 game->score->increase();

//                 // remueve ambos elementos de la pantalla
//                 scene()->removeItem(colliding_items[i]);
//                 scene()->removeItem(this);

//                 // Elimina los elementos y asi no permanecen en memoria
//                 delete colliding_items[i];
//                 delete this;


//                 return;
//             }
//         }

//         // mueve la bala hacia arriba
//         setPos(x(),y()-10);// es -10 porque el origen(0) es la parte de arriba de la pantalla
//         // Destruir la bala una vez salga del area de juego para que no haga nada despues de esta
//         if (pos().y() + pixmap().height() < 0){
//             scene()->removeItem(this);
//             delete this;
//         }
//         std::cout<<"Final"<<endl;
//             //return 0;
 }





