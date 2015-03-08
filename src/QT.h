#ifndef QT_H
#define QT_H

#include "GameGUI.h"
#include "string"

using namespace std;

class QT{

private:
    GameGUI* gui;

public:
    QT();
    void reaccionarALecturaQTDriver(string pData);
};

#endif // QT_H
