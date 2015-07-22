#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessfigure.h"


class Knight : public ChessFigure
{
public:
    Knight(bool color);

    bool isMove(int newPosX, int newPosY);
};

#endif // KNIGHT_H
