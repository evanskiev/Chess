#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    GameWindow *gameWindow;
};

#endif // MAINWINDOW_H
