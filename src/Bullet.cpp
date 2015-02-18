#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>

extern Game * game; // Crea un objeto del tipo game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/bullet.png"));// indica que cada bala va a ser cierta imagen.

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // Empieza el temporizador
    timer->start(50);
}

void Bullet::move(){
    //Lista de los objetos que colisionan con esta bala
    // *******************************************************************Aqui entra abraham con sus listas y hay que hacer
    //un codigo para no utilizar esto de collindeing_items, entonces pienso que hay que hacer hilos para comparar las balas
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //Si una de las colisiones es contra un enemigo se destruyen ambos
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Se incrementa el puntaje
            game->score->increase();

            // remueve ambos elementos de la pantalla
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // Elimina los elementos y asi no permanecen en memoria
            delete colliding_items[i];
            delete this;


            return;
        }
    }

    // mueve la bala hacia arriba
    setPos(x(),y()-10);// es -10 porque el origen(0) es la parte de arriba de la pantalla
    // Destruir la bala una vez salga del area de juego para que no haga nada despues de esta
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
