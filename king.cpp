#include "king.h"
#include "gamewindow.h"

extern QList<ChessFigure*> listOfFigures;
extern bool colorMoveFlag;
extern Tile* chessBoard[8][8];

King::King(bool color) : ChessFigure(color)
{
    name = 'K';

    if (whiteColor)
    {
        image.load(":/Sprites/white_king.png");
    }
    else
    {
        image.load(":/Sprites/balck_king.png");
    }
}

bool King::isMove(int newPosX, int newPosY)
{
    if (colorMoveFlag != whiteColor)
    {
        return false;
    }

    if (checkValidation(newPosX, newPosY))
    {
        return false;
    }

    if (newPosX == posX + 1 && newPosY == posY)
    {
        return true;
    }

    if (newPosX == posX - 1 && newPosY == posY)
    {
        return true;
    }

    if (newPosX == posX && newPosY == posY + 1)
    {
        return true;
    }

    if (newPosX == posX && newPosY == posY - 1)
    {
        return true;
    }

    if (newPosX == posX - 1 && newPosY == posY - 1)
    {
        return true;
    }

    if (newPosX == posX - 1 && newPosY == posY + 1)
    {
        return true;
    }

    if (newPosX == posX + 1 && newPosY == posY + 1)
    {
        return true;
    }

    if (newPosX == posX + 1 && newPosY == posY - 1)
    {
        return true;
    }

    return false;
}

bool King::check(int positionX, int positionY)
{
    for (ChessFigure *figure : listOfFigures)
    {
        if (figure->getWhiteColor() == !whiteColor)
        {
            if (figure->isAlive())
            {
                if (figure->isMove(positionX, positionY))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool King::movesAvaliability()
{
    if (posX < 7)
    {
        if (isMove(posX + 1, posY))
        {
            return true;
        }
    }

    if (posX > 0)
    {
        if (isMove(posX - 1, posY))
        {
            return true;
        }
    }

    if (posY < 7)
    {
        if (isMove(posX, posY + 1))
        {
            return true;
        }
    }

    if (posY > 0)
    {
        if (isMove(posX, posY - 1))
        {
            return true;
        }
    }

    if (posX < 7 && posY < 7)
    {
        if (isMove(posX + 1, posY + 1))
        {
            return true;
        }
    }

    if (posX < 7 && posY > 0)
    {
        if (isMove(posX + 1, posY - 1))
        {
            return true;
        }
    }

    if (posX > 0 && posY > 0)
    {
        if (isMove(posX - 1, posY - 1))
        {
            return true;
        }
    }

    if (posX > 0 && posY < 7)
    {
        if (isMove(posX - 1, posY + 1))
        {
            return true;
        }
    }
    return false;
}
