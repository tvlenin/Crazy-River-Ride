
#include "Health.h"
#include <QFont>
//**************************************************************
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //Inicializa las vidas en 3
    health = 3;

    // Dibuja el texto sobre la escena
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
// Metodo que decrementa las vidas de la nave******************mas adelante hay que hacer que si es igual a cero acabe el juegoo!!!!!!!!
void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}
// Metodo para obtener las vidas que nos queda
int Health::getHealth(){
    return health;
}
