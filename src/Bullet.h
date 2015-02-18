#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsItem>
#include <QObject>
// Clase Bullet, indica que es un QObject y es un Pixmap, o sea se puede poner una imagen en el.
class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    // Metodo con el cual se mueven las balas en la pantalla
    void move();
};

#endif // BULLET_H
