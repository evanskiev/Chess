#ifndef TILE_H
#define TILE_H

#include "chessfigure.h"

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>


class Tile : public QLabel
{
private:
    int tileColor;
    int row;
    int col;

public:
    Tile(QWidget* pParent=0, Qt::WindowFlags f=0);
    ChessFigure *figure;

    void drawTile();
    void drawFigure();

    void setFigure(ChessFigure *newFigure);

    void mousePressEvent(QMouseEvent *event);
    void validation(Tile *tile);
    void setTileColor(int value);
    int getRow() const;
    int getCol() const;
    void setRow(int value);
    void setCol(int value);
};

#endif // TILE_H
