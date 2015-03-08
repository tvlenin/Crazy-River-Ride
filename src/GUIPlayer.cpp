#include "GUIPlayer.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "GUIBullet.h"
#include "GUIEnemy.h"
#include <QDebug>
#include <GameGUI.h>
#include <thread>
#include <cstdlib>
#include <QDebug>
#include <pthread.h>
using namespace std;
extern GameGUI * gameGUI;
//*****************************************
GUIPlayer::GUIPlayer(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //Agrega sonido de disparo a cada vez que disparo******************Aqui hay que revisar lo del sonido que se detiene
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/disparo.wav"));

setPixmap(QPixmap(":/images/nave.png"));// Imagen que va a ser usada como la nave


}

//Aqui se capturan los eventos del teclado
void GUIPlayer::keyPressEvent(QKeyEvent *event){
    // Mueve la nave hacia la izquierda
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }

    //Mueve la nave hacia la derecha
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    //Mueve la nave hacia arriba
    else if (event->key() == Qt::Key_Up){
        //if (pos().y()  > 100)
        //game->scene->setSceneRect(0,y()-500, 800, 1000);


        setPos(x(),y()-10);
    }
    //Mueve la nave hacia abajo
    else if (event->key() == Qt::Key_Down){
        //if (pos().y()  < 500)
        setPos(x(),y()+10);
    }
    // Dispara con la barra espaciadora
    else if (event->key() == Qt::Key_Space){
        // se crea una bala cada vez que se presiona
                  GUIBullet * bullet = new GUIBullet();

        bullet->setPos(x() + 30,y());
        scene()->addItem(bullet);
        //bullet->move();
        //pthread_t t1;
        //pthread_create(&t1, NULL,bullet->move,NULL);








        //sonido al disparar
        if (bulletsound->state() == QMediaPlayer::PlayingState){

            bulletsound->setPosition(0);

        }else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {


          //bulletsound->play();


        }

    }
}

void GUIPlayer::spawn(){
    //******************************************************BUSCAR*************EN CODIGO*********
    GUIEnemy * enemy = new GUIEnemy();
    scene()->addItem(enemy);
}
