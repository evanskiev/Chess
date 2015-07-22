#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "tile.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "handler.h"
#include <move.h>
#include <QWidget>
#include <QPushButton>
#include <QList>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    void startGameButtonClicked();
    void loadGameButtonClicked();
    void stopGameButtonClicked();
    void saveGameButtonClicked();
    void prevMoveButtonClicked();
    void nextMoveButtonClicked();
    void newGameButtonClicked();

public slots:
    void updateGameInfo();

private:
    Ui::GameWindow *ui;

    QPushButton *startGameButton;
    QPushButton *loadGameButton;

    QPushButton *stopGameButton;
    QPushButton *saveGameButton;

    QPushButton *prevMoveButton;
    QPushButton *nextMoveButton;
    QPushButton *newGameButton;

    QList<Move>::iterator cursor;


    void createChessBoard();
    void fillChessBoard();
    void clearChessBoard();

    void parsingFile(QString &buffer);

};

#endif // GAMEWINDOW_H
