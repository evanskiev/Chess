#include "figuretranformation.h"
#include "ui_figuretranformation.h"
#include "gamewindow.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "handler.h"


extern Tile* chessBoard[8][8];
extern QList<ChessFigure*> listOfFigures;
extern ChessFigure *transformedFigure;

FigureTranformation::FigureTranformation(bool whiteColor, Pawn *pawn, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FigureTranformation)
{
    ui->setupUi(this);
    this->setModal(true);
    this->pawn = pawn;
    this->whiteColor = whiteColor;

    this->setGeometry(300, 300, 330, 105);

    this->setWindowTitle("Select figure");

    queenButton = new QPushButton(this);
    rookButton = new QPushButton(this);
    knightButton = new QPushButton(this);
    bishopButton = new QPushButton(this);

    queenButton->setGeometry(20, 20, 65, 65);
    rookButton->setGeometry(95, 20, 65, 65);
    knightButton->setGeometry(170, 20, 65, 65);
    bishopButton->setGeometry(245, 20, 65, 65);

    if (whiteColor)
    {
        queenButton->setIcon(QIcon(QPixmap(":/Sprites/white_queen.png")));
        queenButton->setIconSize(QSize(40, 40));
        rookButton->setIcon(QIcon(QPixmap(":/Sprites/white_rook.png")));
        rookButton->setIconSize(QSize(40, 40));
        knightButton->setIcon(QIcon(QPixmap(":/Sprites/white_knight.png")));
        knightButton->setIconSize(QSize(40, 40));
        bishopButton->setIcon(QIcon(QPixmap(":/Sprites/white_bishop.png")));
        bishopButton->setIconSize(QSize(40, 40));
    }
    else
    {
        queenButton->setIcon(QIcon(QPixmap(":/Sprites/black_queen.png")));
        queenButton->setIconSize(QSize(40, 40));
        rookButton->setIcon(QIcon(QPixmap(":/Sprites/black_rook.png")));
        rookButton->setIconSize(QSize(40, 40));
        knightButton->setIcon(QIcon(QPixmap(":/Sprites/black_knight.png")));
        knightButton->setIconSize(QSize(40, 40));
        bishopButton->setIcon(QIcon(QPixmap(":/Sprites/black_bishop.png")));
        bishopButton->setIconSize(QSize(40, 40));
    }

    connect(queenButton, SIGNAL(clicked(bool)), this, SLOT(queenButtonClicked()));
    connect(rookButton, SIGNAL(clicked(bool)), this, SLOT(rookButtonClicked()));
    connect(knightButton, SIGNAL(clicked(bool)), this, SLOT(knightButtonClicked()));
    connect(bishopButton, SIGNAL(clicked(bool)), this, SLOT(bishopButtonClicked()));
}

FigureTranformation::~FigureTranformation()
{
    delete ui;
}

void FigureTranformation::queenButtonClicked()
{
    transformedFigure = new Queen(whiteColor);
    this->close();
}

void FigureTranformation::rookButtonClicked()
{
    transformedFigure = new Rook(whiteColor);
    this->close();
}

void FigureTranformation::knightButtonClicked()
{
    transformedFigure = new Knight(whiteColor);
    this->close();
}

void FigureTranformation::bishopButtonClicked()
{
    transformedFigure = new Bishop(whiteColor);
    this->close();
}
