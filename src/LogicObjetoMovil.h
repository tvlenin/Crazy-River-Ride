#ifndef OBJETOMOVIL_H
#define OBJETOMOVIL_H

class LogicObjetoMovil
{
protected:

    int posX;
    int posY;
    int hp;

public:
    LogicObjetoMovil();
    void setPosX(int pX);
    void setPosY(int pY);
    void sethp(int pData);
    int getPosX();
    int getPosY();
    int gethp();
};

#endif // OBJETOMOVIL_H
