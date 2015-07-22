#ifndef PAWN_H
#define PAWN_H

#include "chessfigure.h"


class Pawn : public ChessFigure
{
public:
    Pawn(bool color);

    bool isMove(int newPosX, int newPosY);

private:
    bool firstTurn;
    bool moveValidation(int newPosX, int newPosY);

};

#endif // PAWN_H
