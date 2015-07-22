#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "tile.h"

class Handler : public QObject
{
    Q_OBJECT

private:
    Tile *currentFigure;

public:
    explicit Handler(QObject *parent = 0);

    void moveCheck(Tile *temp);
    void move(Tile *from, Tile *to);
    void saveMove(Tile *oldPos, Tile *newPos);
    void creatingTranformedFigure(QChar &name);

    Tile *getCurrentFigure() const;
    void setCurrentFigure(Tile *value);

signals:
    void sendGameInfo();

public slots:
};

#endif // HANDLER_H
