#include "move.h"


int Move::getOldRow() const
{
    return oldRow;
}

void Move::setOldRow(int value)
{
    oldRow = value;
}

int Move::getOldCol() const
{
    return oldCol;
}

void Move::setOldCol(int value)
{
    oldCol = value;
}

int Move::getNewRow() const
{
    return newRow;
}

void Move::setNewRow(int value)
{
    newRow = value;
}

int Move::getNewCol() const
{
    return newCol;
}

void Move::setNewCol(int value)
{
    newCol = value;
}

QChar Move::getNameTrFigure() const
{
    return nameTrFigure;
}

void Move::setNameTrFigure(const QChar &value)
{
    nameTrFigure = value;
}

Move::Move()
{
    capturedFigure = nullptr;
    transformedFigure = nullptr;
}
