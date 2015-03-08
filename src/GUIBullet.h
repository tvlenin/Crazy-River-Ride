#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsItem>
#include <QObject>
// Clase Bullet, indica que es un QObject y es un Pixmap, o sea se puede poner una imagen en el.
class GUIBullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    GUIBullet(QGraphicsItem * parent=0);
//public slots:
    // Metodo con el cual se mueven las balas en la pantalla
   void *move(void);
    pthread_t tl;
    pthread_mutex_t    mutex = PTHREAD_MUTEX_INITIALIZER;

};

#endif // BULLET_H
