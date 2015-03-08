#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "GUIPlayer.h"
#include "GUIScore.h"
#include "GUIHealth.h"

using namespace std;

// Calse juego, es una GraphicsView en el cua se pueden poner los demas componentes
class GameGUI: public QGraphicsView
{
private:
    string name;
    string estado;



public:
    //Crea en panel como un widget donde se va a dibujar
    GameGUI(QWidget * parent=0);

    QGraphicsScene * scene;// crea escena
    QGraphicsScene * scenefondo;// crea escena

    GUIPlayer * player;//Crea un jugador
    GUIScore* score;//Crea una objeto de la clase score para el puntaje
    GUIHealth * health; // Crea una objeto de la clase health para la vida
    pthread_t tl;
    void * move(void);

    void Update(string pData);
};

#endif // GAME_H
