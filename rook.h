#ifndef ROOK_H
#define ROOK_H

#include "chessfigure.h"


class Rook : public ChessFigure
{
public:
    Rook(bool color);

    bool isMove(int newPosX, int newPosY);
};

#endif // ROOK_H
