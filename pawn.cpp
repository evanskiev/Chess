#include "pawn.h"
#include "gamewindow.h"

#include <qdebug.h>
#include "figuretranformation.h"
#include "gamewindow.h"

extern Tile* chessBoard[8][8];
extern bool colorMoveFlag;


Pawn::Pawn(bool color) : ChessFigure(color)
{
    name = 'P';

    firstTurn = true;

    if (whiteColor)
    {
        image.load(":/Sprites/white_pawn.png");
    }
    else
    {
        image.load(":/Sprites/black_pawn.png");
    }

}

bool Pawn::isMove(int newPosX, int newPosY)
{
    if (moveValidation(newPosX, newPosY))
    {
        if (whiteColor)
            {
                if (newPosY == 7 && colorMoveFlag == whiteColor)
                {
                    FigureTranformation *dialog = new FigureTranformation(true, this);
                    dialog->exec();
                    delete dialog;
                }
            }
            else
            {
                if (newPosY == 0 && colorMoveFlag == whiteColor)
                {
                    FigureTranformation *dialog = new FigureTranformation(false, this);
                    dialog->exec();
                    delete dialog;
                }
            }
        return true;
    }
    return false;
}

bool Pawn::moveValidation(int newPosX, int newPosY)
{
    if (newPosX == posX)
    {
        if (chessBoard[newPosY][newPosX]->figure != nullptr)
        {
            return false;
        }

        if (firstTurn)
        {
            if (newPosY == posY + 2 || newPosY == posY - 2)
            {
                firstTurn = false;
                return true;
            }
        }

        if (whiteColor)
        {
            if (newPosY == posY + 1)
            {
                firstTurn = false;
                return true;
            }
        }
        else
        {
            if (newPosY == posY - 1)
            {
                firstTurn = false;
                return true;
            }
        }
    }

    if (newPosX == posX + 1 || newPosX == posX - 1)
    {
        if (chessBoard[newPosY][newPosX]->figure == nullptr)
        {
            return false;
        }

        if (chessBoard[newPosY][newPosX]->figure->getWhiteColor() == whiteColor)
        {
            return false;
        }

        if (whiteColor)
        {
            if (newPosY == posY + 1)
            {
                firstTurn = false;
                return true;
            }
        }
        else
        {
            if (newPosY == posY - 1)
            {
                firstTurn = false;
                return true;
            }
        }

    }
    return false;
}
