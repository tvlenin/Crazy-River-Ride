#include "GameGUI.h"
#include <QTimer>

#include <QGraphicsTextItem>
#include <QFont>
#include "GUIEnemy.h"
#include "GUIScore.h"
#include <QMediaPlayer>
#include <QImage>
#include <iostream>
#include <cstdlib>
#include <QDebug>
#include <unistd.h>
#include <pthread.h>
#include <chrono>
#include<time.h>

using namespace std;
static void *hello_helper(void *context) {return ((GameGUI *)context)->move();}
// **************** en la demas escribi algo aqui pero hay que revisarlo porque no estoy seguro
GameGUI::GameGUI(QWidget *parent){

    // Crea la escena del tipo QgraphicsScene, con un tamano de 800x600********Tenemos que pasar estos numeros a constantes!!!!!!!
    scene = new QGraphicsScene();

    scene->setSceneRect(0,y(),800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg")));//Imagen de fondo
    setScene(scene);
    //scene->
    //Las siguientes dos lineas eliminan la posibilidad de ver
    //los scrollbar para que solo veamos el campo de juego definido
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);//*************************CONSTANTES

    // Crea  un jugador en la parte central inferior de la pantalla
    player = new GUIPlayer();
    player->setPos(400,500);
    // Pone al jugador en la mira para capturar los eventos de teclado
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Agrega al jugador creado anteriormente en la escena del juego0
    //scene->addItem(player); AL METODO PINTAR JUGADOR
    scene->addItem(player);

    // Crea los elementos de puntaje y vida y los agrega a la escena

    score = new GUIScore();
    health = new GUIHealth();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(score);
    scene->addItem(health);

     //Hace que los enemigos aparezcan cada cierto tiempo********************************** aunque tenemos que investigar mas
     //  pthread_create(&tl,NULL, &hello_helper,this);

    //Esto agrega la musica de fondo **********************Mi musica es perfecta pero mejor buscamos otra..hahahha!!!!!!!!!!!!!!!!!
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/musica.mp3"));
    music->play();

    show();

}



void *GameGUI::move(void){
    while(true){
    usleep(8000000);
    player->spawn();
    std::cout<<"Hola"<< endl;
    }
}




