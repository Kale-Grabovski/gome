#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class QPushButton;

namespace Ui {
class TicTacToeWidget;
}

enum Player {
    Invalid, Player1, Player2, Draw
};

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Player)
    Q_PROPERTY(Player currentPlayer READ currentPlayer WRITE setCurrentPlayer NOTIFY currentPlayerChanged)

public:
    explicit TicTacToeWidget(QWidget *parent = 0);
    ~TicTacToeWidget();
    
    void initNewGame();
    Player currentPlayer() const;
    void setCurrentPlayer(Player);

private:
    void setupBoard();
    Player checkWinConditions() const;
    Ui::TicTacToeWidget *ui;
    QList<QPushButton*> board;
    Player m_currentPlayer;

public slots:
    void handleButtonClick(int);

signals:
    void currentPlayerChanged(Player);
    void gameOver(Player);
};

#endif // TICTACTOEWIDGET_H
