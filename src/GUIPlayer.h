#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
// Clase player del tipo QGraphicsPixmapItem, una imagen
class GUIPlayer:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    GUIPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;

};

#endif // PLAYER_H
