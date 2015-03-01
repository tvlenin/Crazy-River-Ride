#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
// Clase Enemy, indica que es un QObject y es un Pixmap, o sea se puede poner una imagen en el.
class GUIEnemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    GUIEnemy(QGraphicsItem * parent=0);
//public slots:
    //Metodo para mover los enemigos por la pantalla****************En el contructor hay que hacer diferentes tipos de balas
    void *move(void);
    pthread_t tl;
};

#endif // ENEMY_H
