#include "LogicObjetoMovil.h"

LogicObjetoMovil::LogicObjetoMovil()
{
    this->hp = 100;
    this->posX = 0;
    this->posY = 0;
}

void LogicObjetoMovil::setPosX(int pX)
{
    this->posX = pX;
}

void LogicObjetoMovil::setPosY(int pY)
{
    this->posY = pY;
}

void LogicObjetoMovil::sethp(int pData)
{
    this->hp = pData;
}

int LogicObjetoMovil::getPosX()
{
    return this->posX;
}

int LogicObjetoMovil::getPosY()
{
    return this->posY;
}

int LogicObjetoMovil::gethp()
{
    return this->hp;
}
