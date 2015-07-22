#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H

#include <QPixmap>

class ChessFigure
{
protected:
    QChar name;
    int posX;
    int posY;
    bool alive;
    bool whiteColor;
    QPixmap image;

public:
    ChessFigure(bool color);
    virtual ~ChessFigure();

    virtual bool isMove(int newPosX, int newPosY) = 0;
    bool checkValidation(int newPosX, int newPosY);
    bool isAlive() const;
    QPixmap getImage() const;
    QChar getName() const;
    bool getWhiteColor() const;
    int getPosX() const;
    int getPosY() const;
    void setPosX(int value);
    void setPosY(int value);
    void setAlive(bool value);
};

#endif // CHESSFIGURE_H
