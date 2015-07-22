#ifndef BISHOP_H
#define BISHOP_H

#include "chessfigure.h"

class Bishop : public ChessFigure
{
public:
    Bishop(bool color);

    bool isMove(int newPosX, int newPosY);
};

#endif // BISHOP_H
