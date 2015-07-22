#include "handler.h"

#include "move.h"
#include "gamewindow.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"

#include <QDebug>
#include <QString>
#include <QMessageBox>

extern Tile* chessBoard[8][8];
extern bool colorMoveFlag;
extern bool isMoveFlag;
extern QList<Move> listOfMoves;
extern QList<ChessFigure*> listOfFigures;
extern King *whiteKing;
extern King *blackKing;

ChessFigure *transformedFigure = nullptr;


Tile *Handler::getCurrentFigure() const
{
    return currentFigure;
}

void Handler::setCurrentFigure(Tile *value)
{
    currentFigure = value;
}
Handler::Handler(QObject *parent) : QObject(parent)
{
    currentFigure = nullptr;
}

void Handler::moveCheck(Tile *temp)
{
    if (currentFigure->figure->isMove(temp->getCol(), temp->getRow()))
    {
        if (colorMoveFlag)
        {
            if (whiteKing->check(whiteKing->getPosX(), whiteKing->getPosX()))
            {
                if (currentFigure->figure != whiteKing)
                {
                    if (currentFigure->figure->checkValidation(temp->getCol(), temp->getRow()))
                        return;
                }
            }
        }
        else
        {
            if (blackKing->check(blackKing->getPosX(), blackKing->getPosY()))
            {
                if (currentFigure->figure != blackKing)
                {
                    if (currentFigure->figure->checkValidation(temp->getCol(), temp->getRow()))
                        return;
                }
            }
        }
        saveMove(currentFigure, temp);
        move(currentFigure, temp);

        emit sendGameInfo();

        currentFigure = nullptr;

//        if (colorMoveFlag)
//        {
//            if (whiteKing->check(whiteKing->posX, whiteKing->posY))
//            {
//                if (!whiteKing->movesAvaliability())
//                {
//                    QMessageBox *message = new QMessageBox(QMessageBox::Information, "Game Over", "THIS GAME WON BLACK SIDE!",
//                                                           QMessageBox::Ok);
//                    message->exec();
//                    delete message;
//                    isMoveFlag = false;

//                    return;
//                }
//            }
//        }
//        else
//        {
//            if (blackKing->check(blackKing->posX, blackKing->posY))
//            {
//                if (!blackKing->movesAvaliability())
//                {
//                    QMessageBox *message = new QMessageBox(QMessageBox::Information, "Game Over", "THIS GAME WON WHITE SIDE!",
//                                                           QMessageBox::Ok);
//                    message->exec();
//                    delete message;
//                    isMoveFlag = false;

//                    return;
//                }
//            }
//        }
    }
}

void Handler::move(Tile *from, Tile *to)
{
    to->clear();
    to->figure = from->figure;
    from->figure = nullptr;

    to->figure->setPosX(to->getCol());
    to->figure->setPosY(to->getRow());

    to->drawFigure();

    from->clear();

    colorMoveFlag = !colorMoveFlag;
}

void Handler::saveMove(Tile *oldPos, Tile *newPos)
{
    Move temp;

    temp.setOldRow(oldPos->getRow());
    temp.setOldCol(oldPos->getCol());
    temp.setNewRow(newPos->getRow());
    temp.setNewCol(newPos->getCol());

    if (newPos->figure != nullptr)
    {
        newPos->figure->setAlive(false);
        temp.capturedFigure = newPos->figure;
    }

    if (transformedFigure != nullptr)
    {
        transformedFigure->setPosX(oldPos->getRow());
        transformedFigure->setPosY(oldPos->getCol());

        listOfFigures.append(transformedFigure);
        temp.transformedFigure = transformedFigure;
        temp.setNameTrFigure(transformedFigure->getName());
        transformedFigure = nullptr;
        qSwap(oldPos->figure, temp.transformedFigure);
    }

    listOfMoves.append(temp);
}

void Handler::creatingTranformedFigure(QChar &name)
{
    if (name == 'Q')
    {
        transformedFigure = new Queen(colorMoveFlag);
        return;
    }
    if (name == 'R')
    {
        transformedFigure = new Rook(colorMoveFlag);
        return;
    }
    if (name == 'H')
    {
        transformedFigure = new Knight(colorMoveFlag);
        return;
    }
    if (name == 'B')
    {
        transformedFigure = new Bishop(colorMoveFlag);
        return;
    }

}

