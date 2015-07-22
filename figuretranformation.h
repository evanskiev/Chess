#ifndef FIGURETRANFORMATION_H
#define FIGURETRANFORMATION_H

#include <QDialog>
#include <QPushButton>

#include "pawn.h"

namespace Ui {
class FigureTranformation;
}

class FigureTranformation : public QDialog
{
    Q_OBJECT

public:
    explicit FigureTranformation(bool whiteColor, Pawn *pawn, QWidget *parent = 0);
    ~FigureTranformation();

private slots:
    void queenButtonClicked();
    void rookButtonClicked();
    void knightButtonClicked();
    void bishopButtonClicked();


private:
    Ui::FigureTranformation *ui;

    QPushButton *queenButton;
    QPushButton *rookButton;
    QPushButton *knightButton;
    QPushButton *bishopButton;

    Pawn *pawn;
    bool whiteColor;
};

#endif // FIGURETRANFORMATION_H
