#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

Tile* chessBoard[8][8];
bool colorMoveFlag = true;
bool isMoveFlag = true;
QList<Move> listOfMoves;
QList<ChessFigure*> listOfFigures;

King *whiteKing;
King *blackKing;

extern Handler *handler;

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chess");
    this->setGeometry(350,50,580,620);
    this->setFixedSize(580,620);
    this->setWindowIcon(QIcon(":/Sprites/black_knight.png"));


    startGameButton = new QPushButton("Start Game", this);
    startGameButton->setGeometry(50,580,200,25);

    loadGameButton = new QPushButton("Load Game", this);
    loadGameButton->setGeometry(330,580,200,25);

    stopGameButton = new QPushButton("Stop Game", this);
    stopGameButton->setGeometry(50,580,200,25);
    stopGameButton->hide();

    saveGameButton = new QPushButton("Save Game", this);
    saveGameButton->setGeometry(330,580,200,25);
    saveGameButton->hide();

    prevMoveButton = new QPushButton("Prev Move", this);
    prevMoveButton->setGeometry(10,580,120,25);
    prevMoveButton->hide();

    nextMoveButton = new QPushButton("Next Move", this);
    nextMoveButton->setGeometry(150,580,120,25);
    nextMoveButton->hide();

    newGameButton = new QPushButton("New Game", this);
    newGameButton->setGeometry(310,580,120,25);
    newGameButton->hide();

    connect(startGameButton, SIGNAL(clicked(bool)), this, SLOT(startGameButtonClicked()));
    connect(loadGameButton, SIGNAL(clicked(bool)), this, SLOT(loadGameButtonClicked()));
    connect(stopGameButton,SIGNAL(clicked(bool)), this, SLOT(stopGameButtonClicked()));
    connect(saveGameButton, SIGNAL(clicked(bool)), this, SLOT(saveGameButtonClicked()));
    connect(newGameButton, SIGNAL(clicked(bool)), this, SLOT(newGameButtonClicked()));
    connect(prevMoveButton, SIGNAL(clicked(bool)), this, SLOT(prevMoveButtonClicked()));
    connect(nextMoveButton, SIGNAL(clicked(bool)), this, SLOT(nextMoveButtonClicked()));
    connect(handler, SIGNAL(sendGameInfo()), this, SLOT(updateGameInfo()));

    createChessBoard();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::startGameButtonClicked()
{
    fillChessBoard();

    startGameButton->hide();
    loadGameButton->hide();

    stopGameButton->show();
    saveGameButton->show();
}

void GameWindow::loadGameButtonClicked()
{
    QString url = QFileDialog::getOpenFileName(this, tr("Select a file"), "./Save/");

    QFile inputFile(url);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QString buffer = in.readAll();

        clearChessBoard();
        fillChessBoard();

        parsingFile(buffer);

        startGameButton->hide();
        loadGameButton->setGeometry(440,580,120,25);

        prevMoveButton->show();
        nextMoveButton->show();
        newGameButton->show();

        cursor = listOfMoves.end();
        isMoveFlag = false;

        inputFile.close();
    }
}

void GameWindow::saveGameButtonClicked()
{
    QString url = QFileDialog::getSaveFileName(this, tr("Save File"), "./Save/");

    QFile outputFile(url);
    if (outputFile.open(QIODevice::WriteOnly))
    {
        QByteArray buffer;

        for (Move temp : listOfMoves)
        {
            buffer.append(QByteArray::number(temp.getOldRow())+'-'+QByteArray::number(temp.getOldCol())+'-');
            buffer.append(QByteArray::number(temp.getNewRow())+'-'+QByteArray::number(temp.getNewCol())+'-');
            if (temp.transformedFigure != nullptr)
            {
                buffer.append(temp.getNameTrFigure());
                buffer.append('\n');
            }
            else
            {
                buffer.append("0\n");
            }
        }
        outputFile.write(buffer);

        outputFile.close();
    }
}

void GameWindow::prevMoveButtonClicked()
{
    if (cursor == listOfMoves.begin())
    {
        return;
    }
    --cursor;
    int fromRow = (*cursor).getNewRow();
    int fromCol = (*cursor).getNewCol();
    int toRow = (*cursor).getOldRow();
    int toCol = (*cursor).getOldCol();

    if ((*cursor).transformedFigure != nullptr)
    {
        qSwap(chessBoard[fromRow][fromCol]->figure, (*cursor).transformedFigure);
    }

    handler->move(chessBoard[fromRow][fromCol], chessBoard[toRow][toCol]);

    if ((*cursor).capturedFigure != nullptr)
    {
        chessBoard[fromRow][fromCol]->figure = (*cursor).capturedFigure;
        chessBoard[fromRow][fromCol]->drawFigure();
    }
}

void GameWindow::nextMoveButtonClicked()
{
    if (cursor == listOfMoves.end())
    {
        return;
    }
    int fromRow = (*cursor).getOldRow();
    int fromCol = (*cursor).getOldCol();
    int toRow = (*cursor).getNewRow();
    int toCol = (*cursor).getNewCol();

    if ((*cursor).transformedFigure != nullptr)
    {
        qSwap(chessBoard[fromRow][fromCol]->figure, (*cursor).transformedFigure);
    }

    handler->move(chessBoard[fromRow][fromCol], chessBoard[toRow][toCol]);
    ++cursor;
}

void GameWindow::newGameButtonClicked()
{
    clearChessBoard();
    fillChessBoard();

    prevMoveButton->hide();
    nextMoveButton->hide();
    newGameButton->hide();
    loadGameButton->hide();

    stopGameButton->show();
    saveGameButton->show();
}

void GameWindow::updateGameInfo()
{
    if (colorMoveFlag)
    {
        this->setWindowTitle("White Turn");
    }
    else
    {
        this->setWindowTitle("Black Turn");
    }
}

void GameWindow::stopGameButtonClicked()
{
    stopGameButton->hide();
    saveGameButton->hide();

    startGameButton->show();
    loadGameButton->show();
    loadGameButton->setGeometry(330,580,200,25);

    clearChessBoard();
    this->setWindowTitle("Chess");
}

void GameWindow::createChessBoard()
{
    int hor = 10;
    int ver = 500;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Tile *tile = new Tile(this);

            chessBoard[i][j] = tile;
            tile->setTileColor((i+j)%2);
            tile->setRow(i);
            tile->setCol(j);
            tile->setGeometry(hor,ver,70,70);
            tile->drawTile();
            hor += 70;
        }
        hor = 10;
        ver -=70;
    }
}

void GameWindow::fillChessBoard()
{
    for (int i = 0; i < 8; i++) {
        chessBoard[6][i]->setFigure(new Pawn(false));

        chessBoard[1][i]->setFigure(new Pawn(true));
    }

    chessBoard[7][0]->setFigure(new Rook(false));
    chessBoard[7][1]->setFigure(new Knight(false));
    chessBoard[7][2]->setFigure(new Bishop(false));
    chessBoard[7][3]->setFigure(new Queen(false));
    blackKing = new King(false);
    chessBoard[7][4]->setFigure(blackKing);
    chessBoard[7][5]->setFigure(new Bishop(false));
    chessBoard[7][6]->setFigure(new Knight(false));
    chessBoard[7][7]->setFigure(new Rook(false));

    chessBoard[0][0]->setFigure(new Rook(true));
    chessBoard[0][1]->setFigure(new Knight(true));
    chessBoard[0][2]->setFigure(new Bishop(true));
    chessBoard[0][3]->setFigure(new Queen(true));
    whiteKing = new King(true);
    chessBoard[0][4]->setFigure(whiteKing);
    chessBoard[0][5]->setFigure(new Bishop(true));
    chessBoard[0][6]->setFigure(new Knight(true));
    chessBoard[0][7]->setFigure(new Rook(true));

    for (int i = 0; i < 8; i++)
    {
        listOfFigures.append(chessBoard[0][i]->figure);
        listOfFigures.append(chessBoard[1][i]->figure);
        listOfFigures.append(chessBoard[6][i]->figure);
        listOfFigures.append(chessBoard[7][i]->figure);
    }

    this->setWindowTitle("White Turn");
}

void GameWindow::clearChessBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessBoard[i][j]->clear();
            if (chessBoard[i][j]->figure)
            {
                chessBoard[i][j]->figure = nullptr;
            }
        }
    }

    for (ChessFigure *temp : listOfFigures)
    {
        delete temp;
    }
    listOfFigures.clear();
    listOfMoves.clear();
    colorMoveFlag = true;
    isMoveFlag = true;
}

void GameWindow::parsingFile(QString &buffer)
{
    QStringList moves = buffer.split('\n');
    moves.removeLast();

    for (QString temp : moves)
    {

        QStringList l = temp.split('-');
        Move move;
        move.setOldRow(l.at(0).toInt());
        move.setOldCol(l.at(1).toInt());
        move.setNewRow(l.at(2).toInt());
        move.setNewCol(l.at(3).toInt());

        QString n = l.at(4);
        QChar typeOfFigure = n.at(0);

        if (typeOfFigure != '0')
        {
            handler->creatingTranformedFigure(typeOfFigure);
        }



        handler->saveMove(chessBoard[move.getOldRow()][move.getOldCol()], chessBoard[move.getNewRow()][move.getNewCol()]);
        handler->move(chessBoard[move.getOldRow()][move.getOldCol()], chessBoard[move.getNewRow()][move.getNewCol()]);
    }
}
