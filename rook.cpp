#include "rook.h"
#include "gamewindow.h"

extern Tile* chessBoard[8][8];

Rook::Rook(bool color) : ChessFigure(color)
{
    name = 'R';

    if (whiteColor)
    {
        image.load(":/Sprites/white_rook.png");
    }
    else
    {
        image.load(":/Sprites/black_rook.png");
    }
}

bool Rook::isMove(int newPosX, int newPosY)
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
    return false;
}
