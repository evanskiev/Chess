#include "queen.h"
#include "gamewindow.h"

extern Tile* chessBoard[8][8];

Queen::Queen(bool color) : ChessFigure(color)
{
    name = 'Q';

    if (whiteColor)
    {
        image.load(":/Sprites/white_queen.png");
    }
    else
    {
        image.load(":/Sprites/black_queen.png");
    }
}

bool Queen::isMove(int newPosX, int newPosY)
{
    if (newPosX == posX) //vertical
    {
        if (posY < newPosY)
        {
            for (int i = posY + 1; i < newPosY; i++)
            {
                if (chessBoard[i][posX]->figure != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = posY - 1; i > newPosY; i--)
            {
                if (chessBoard[i][posX]->figure != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
    }

    if (newPosY == posY) //horizontal
    {
        if (posX < newPosX)
        {
            for (int i = posX + 1; i < newPosX; i++)
            {
                if (chessBoard[posY][i]->figure != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = posX - 1; i > newPosX; i--)
            {
                if (chessBoard[posY][i]->figure != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
    }

    if (newPosX > posX && newPosY > posY)
    {
        int i = posX + 1;
        int j = posY + 1;

        for (; i < newPosX; i++, j++)
        {
            if (chessBoard[j][i]->figure != nullptr)
            {
                return false;
            }
        }
        if (newPosX == i && newPosY == j){
            return true;
        }

    }

    if (newPosX < posX && newPosY > posY)
    {
        int i = posX - 1;
        int j = posY + 1;

        for (; i > newPosX; i--, j++)
        {
            if (chessBoard[j][i]->figure != nullptr)
            {
                return false;
            }
        }
        if (newPosX == i && newPosY == j){
            return true;
        }
    }

    if (newPosX > posX && newPosY < posY)
    {
        int i = posX + 1;
        int j = posY - 1;

        for (; i < newPosX; i++, j--)
        {
            if (chessBoard[j][i]->figure != nullptr)
            {
                return false;
            }
        }
        if (newPosX == i && newPosY == j){
            return true;
        }
    }

    if (newPosX < posX && newPosY < posY)
    {
        int i = posX - 1;
        int j = posY - 1;

        for (; i > newPosX; i--, j--)
        {
            if (chessBoard[j][i]->figure != nullptr)
            {
                return false;
            }
        }
        if (newPosX == i && newPosY == j){
            return true;
        }
    }

    return false;
}
