#ifndef MOVE_H
#define MOVE_H

#include "chessfigure.h"

class Move
{
private:
    int oldRow;
    int oldCol;
    int newRow;
    int newCol;
    QChar nameTrFigure;

public:
    Move();

    ChessFigure *capturedFigure;
    ChessFigure *transformedFigure;

    int getOldRow() const;
    int getOldCol() const;
    int getNewRow() const;
    int getNewCol() const;
    QChar getNameTrFigure() const;
    void setOldRow(int value);
    void setOldCol(int value);
    void setNewRow(int value);
    void setNewCol(int value);
    void setNameTrFigure(const QChar &value);
};

#endif // MOVE_H
