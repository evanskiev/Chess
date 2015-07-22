#ifndef KING_H
#define KING_H

#include "chessfigure.h"

class King : public ChessFigure
{
public:
    King(bool color);

    bool isMove(int newPosX, int newPosY);
    bool check(int positionX, int positionY);
    bool movesAvaliability();
};

#endif // KING_H
