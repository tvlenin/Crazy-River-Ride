#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
// Calse de la vida, es una GraphicsTextItem en el cua para ver las vidas que le quedan a la nave
class Health: public QGraphicsTextItem{
public:

    Health(QGraphicsItem * parent=0);
    void decrease();// metodo para bajar las vidas
    int getHealth();// metodo para obtener las vidas
private:
    int health;
};

#endif // HEALTH_H
