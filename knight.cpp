#include "knight.h"

Knight::Knight(bool color) : ChessFigure(color)
{
    name = 'H';

    if (whiteColor)
    {
        image.load(":/Sprites/white_knight.png");
    }
    else
    {
        image.load(":/Sprites/black_knight.png");
    }
}

bool Knight::isMove(int newPosX, int newPosY)
{
    if (newPosX == posX - 1 && newPosY == posY + 2)
    {
        return true;
    }

    if (newPosX == posX + 1 && newPosY == posY + 2)
    {
        return true;
    }

    if (newPosX == posX - 1 && newPosY == posY - 2)
    {
        return true;
    }

    if (newPosX == posX + 1 && newPosY == posY - 2)
    {
        return true;
    }

    if (newPosX == posX - 2 && newPosY == posY + 1)
    {
        return true;
    }

    if (newPosX == posX - 2 && newPosY == posY - 1)
    {
        return true;
    }

    if (newPosX == posX + 2 && newPosY == posY + 1)
    {
        return true;
    }

    if (newPosX == posX + 2 && newPosY == posY - 1)
    {
        return true;
    }
    return false;
}
