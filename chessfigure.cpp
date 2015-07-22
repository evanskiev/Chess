#include "chessfigure.h"
#include "gamewindow.h"
#include <QDebug>

extern King *whiteKing;
extern King *blackKing;
extern Tile* chessBoard[8][8];


bool ChessFigure::isAlive() const
{
    return alive;
}

void ChessFigure::setAlive(bool value)
{
    alive = value;
}

QPixmap ChessFigure::getImage() const
{
    return image;
}

QChar ChessFigure::getName() const
{
    return name;
}

bool ChessFigure::getWhiteColor() const
{
    return whiteColor;
}

int ChessFigure::getPosX() const
{
    return posX;
}

void ChessFigure::setPosX(int value)
{
    posX = value;
}

int ChessFigure::getPosY() const
{
    return posY;
}

void ChessFigure::setPosY(int value)
{
    posY = value;
}
ChessFigure::ChessFigure(bool color) : whiteColor(color)
{
    alive = true;
}

ChessFigure::~ChessFigure()
{
    //qDebug() << this->name << " was deleted!";
}

bool ChessFigure::checkValidation(int newPosX, int newPosY)
{
    if (chessBoard[newPosY][newPosX]->figure != nullptr && chessBoard[newPosY][newPosX]->figure->whiteColor == whiteColor)
    {
        return true;
    }

    ChessFigure *temp = chessBoard[newPosY][newPosX]->figure;
    if (temp != nullptr)
    {
        temp->setAlive(false);
    }

    chessBoard[newPosY][newPosX]->figure = nullptr;

    qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);

    if (whiteColor)
    {
        if (this == whiteKing)
        {
           if (whiteKing->check(newPosX, newPosY))
            {
               qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);
               if (temp != nullptr)
               {
                   temp->setAlive(true);
               }
               chessBoard[newPosY][newPosX]->figure = temp;
               return true;
            }
        }
        else if (whiteKing->check(whiteKing->posX, whiteKing->posY))
        {
            qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);
            if (temp != nullptr)
            {
                temp->setAlive(true);
            }
            chessBoard[newPosY][newPosX]->figure = temp;
            return true;
        }
    }
    else
    {
        if (this == blackKing)
        {
            if (blackKing->check(newPosX, newPosY))
             {
                qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);
                if (temp != nullptr)
                {
                    temp->setAlive(true);
                }
                chessBoard[newPosY][newPosX]->figure = temp;
                return true;
             }
        }
        else if (blackKing->check(blackKing->posX, blackKing->posY))
        {
            qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);
            if (temp != nullptr)
            {
                temp->setAlive(true);
            }
            chessBoard[newPosY][newPosX]->figure = temp;
            return true;
        }
    }

    qSwap(chessBoard[newPosY][newPosX]->figure, chessBoard[posY][posX]->figure);
    if (temp != nullptr)
    {
        temp->setAlive(true);
    }
    chessBoard[newPosY][newPosX]->figure = temp;
    return false;
}

