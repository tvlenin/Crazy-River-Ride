#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>
//*****************************************
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //Agrega sonido de disparo a cada vez que disparo******************Aqui hay que revisar lo del sonido que se detiene
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/disparo.wav"));

setPixmap(QPixmap(":/images/nave.png"));// Imagen que va a ser usada como la nave

}

//Aqui se capturan los eventos del teclado
void Player::keyPressEvent(QKeyEvent *event){
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
    // Dispara con la barra espaciadora
    else if (event->key() == Qt::Key_Space){
        // se crea una bala cada vez que se presiona
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 30,y());
        scene()->addItem(bullet);

        //sonido al disparar
        if (bulletsound->state() == QMediaPlayer::PlayingState){

            bulletsound->setPosition(0);

        }else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {


          bulletsound->play();
        }

    }
}

void Player::spawn(){
    //******************************************************BUSCAR*************EN CODIGO*********
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
