#ifndef QUEEN_H
#define QUEEN_H

#include "chessfigure.h"

class Queen : public ChessFigure
{
public:
    Queen(bool color);

    bool isMove(int newPosX, int newPosY);
};

#endif // QUEEN_H
