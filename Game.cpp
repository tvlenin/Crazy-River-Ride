#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QImage>
// **************** en la demas escribi algo aqui pero hay que revisarlo porque no estoy seguro
Game::Game(QWidget *parent){
    // Crea la escena del tipo QgraphicsScene, con un tamano de 800x600********Tenemos que pasar estos numeros a constantes!!!!!!!
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg")));//Imagen de fondo
    setScene(scene);
    //Las siguientes dos lineas eliminan la posibilidad de ver
    //los scrollbar para que solo veamos el campo de juego definido
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);//*************************CONSTANTES

    // Crea  un jugador en la parte central inferior de la pantalla
    player = new Player();
    player->setPos(400,500);
    // Pone al jugador en la mira para capturar los eventos de teclado
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Agrega al jugador creado anteriormente en la escena del juego0
    scene->addItem(player);

    // Crea los elementos de puntaje y vida y los agrega a la escena
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // Hace que los enemigos aparezcan cada cierto tiempo********************************** aunque tenemos que investigar mas
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //Esto agrega la musica de fondo **********************Mi musica es perfecta pero mejor buscamos otra..hahahha!!!!!!!!!!!!!!!!!

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/musica.mp3"));
    music->play();

    show();
}
