#include <QDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "configurationdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionNewGame, SIGNAL(triggered()), this, SLOT(startNewGame()));
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->gameBoard, SIGNAL(currentPlayerChanged(Player)), this, SLOT(updateNameLabels()));
    
    // This bullshit doesn't working
    connect(this, SIGNAL(triggered()), this, SLOT(handleGameover(Player)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame() {
    ConfigurationDialog dlg(this);
    if (dlg.exec() == QDialog::Rejected) {
        return;
    }

    ui->player1->setText(dlg.player1Name());
    ui->player2->setText(dlg.player2Name());
    ui->gameBoard->initNewGame();
    ui->gameBoard->setEnabled(true);

    updateNameLabels();
}

void MainWindow::updateNameLabels() {
    QFont f = ui->player1->font();

    f.setBold(ui->gameBoard->currentPlayer() == Player1);
    ui->player1->setFont(f);
    f.setBold(ui->gameBoard->currentPlayer() == Player2);
    ui->player2->setFont(f);
}

void MainWindow::handleGameOver(Player winner) {
    ui->gameBoard->setEnabled(false);
    QString message;

    if (winner == Draw) {
        message = "Game ended with a draw.";
    } else {
        message = QString("%1 wins").arg(winner == Player1 ? ui->player1->text() : ui->player2->text());
    }

    QMessageBox::information(this, "Info", message);
}

