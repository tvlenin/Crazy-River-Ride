#include <QApplication>
#include "UI.h"
#include "GameLogic.h"

/*
Tutorial Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/

int main(int argc, char *argv[]){

    //Ok new comment
    QApplication a(argc, argv);

    GameLogic* logica = new GameLogic();
    UI* ui = new UI();


    return a.exec();
}
