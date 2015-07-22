#include "tile.h"
#include "handler.h"
#include "gamewindow.h"

extern bool colorMoveFlag;
extern bool isMoveFlag;

Handler *handler = new Handler();


void Tile::setTileColor(int value)
{
    tileColor = value;
}

int Tile::getRow() const
{
    return row;
}

void Tile::setRow(int value)
{
    row = value;
}

int Tile::getCol() const
{
    return col;
}

void Tile::setCol(int value)
{
    col = value;
}
Tile::Tile(QWidget *pParent, Qt::WindowFlags f) : QLabel(pParent, f)
{
    figure = nullptr;
}

void Tile::drawTile()
{
    if (this->tileColor)
    {
        this->setStyleSheet("background-color:#FFA473");//light
    }
    else
    {
        this->setStyleSheet("background-color:#FF8240");//dark
    }
}

void Tile::drawFigure()
{
    if (figure != nullptr) {
        this->setPixmap(figure->getImage());
        this->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    }
}

void Tile::setFigure(ChessFigure *newFigure)
{
    figure = newFigure;
    figure->setPosX(col);
    figure->setPosY(row);

    drawFigure();
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    if (isMoveFlag)
    {
        validation(this);
    }
}

void Tile::validation(Tile *tile)
{
    if (tile->figure != nullptr)
    {
        if (tile->figure->getWhiteColor() == colorMoveFlag)
        {
            handler->setCurrentFigure(tile);
            return;
        }
    }

    if (handler->getCurrentFigure() != nullptr)
    {
        handler->moveCheck(tile);
    }
}

