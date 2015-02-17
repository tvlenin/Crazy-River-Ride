#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // libreria para utilizar el metodo rand()
#include "Game.h"

extern Game * game; // Crea un objeto del tipo game
//Crea un Enemy del tipo QGraphicsPixmap
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //posiciona el Enemy en una posicion aleatoria
    int random_number = rand() % 700;
    setPos(random_number,0);

    //Crea un objeto Pixmap que seria un enemigo
    setPixmap(QPixmap(":/images/enemy.png"));
    //***********************************************Buscar que hace esto
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // empieza el temporizador
    timer->start(50);
}
// Maneja los movimientos de los enemigos *******Aqui hay que agregar distintos tipos de movimientos
void Enemy::move(){
    // En este caso el enemigo solo se mueve hacia abajo
    setPos(x(),y()+5);

    // Destruye el enemigo una vez se salio de la pantalla*************hay que tomar mas casos en consideracion
    if (pos().y() > 600){
        //*********************************En este caso la vida baja si el enemigo sale de la pantalla, tenemos que hacer que baje cuando hayh impacto o nos disparen
        game->health->decrease();
        //elimina la nave enemiga
        scene()->removeItem(this);
        delete this;
    }
}
