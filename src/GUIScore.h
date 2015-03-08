#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class GUIScore: public QGraphicsTextItem{
public:
    GUIScore(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
