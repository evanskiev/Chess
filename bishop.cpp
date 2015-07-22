#include "bishop.h"
#include "gamewindow.h"

extern Tile* chessBoard[8][8];

Bishop::Bishop(bool color) : ChessFigure(color)
{
    name = 'B';

    if (whiteColor)
    {
        image.load(":/Sprites/white_bishop.png");
    }
    else
    {
        image.load(":/Sprites/black_bishop.png");
    }
}

bool Bishop::isMove(int newPosX, int newPosY)
{
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
