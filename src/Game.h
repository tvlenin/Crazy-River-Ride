#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
// Calse juego, es una GraphicsView en el cua se pueden poner los demas componentes
class Game: public QGraphicsView{
public:
    //Crea en panel como un widget donde se va a dibujar
    Game(QWidget * parent=0);

    QGraphicsScene * scene;// crea escena
    Player * player;//Crea un jugador
    Score * score;//Crea una objeto de la clase score para el puntaje
    Health * health; // Crea una objeto de la clase health para la vida

};

#endif // GAME_H
