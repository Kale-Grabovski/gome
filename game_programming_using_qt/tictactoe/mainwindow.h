#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tictactoewidget.h"

class TicTacToeWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void startNewGame();

private slots:
    void updateNameLabels();
    void handleGameOver(Player winner);
};

#endif // MAINWINDOW_H
