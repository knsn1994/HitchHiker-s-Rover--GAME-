#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "new_game.h"
#include "high_score.h"
#include "about_game.h"
#include "instructions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->showFullScreen();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    new_game *newgame = new new_game();
    newgame->showFullScreen();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    high_score *highscore = new high_score();
    highscore->readScores();
    highscore->showFullScreen();
    this->close();

}

void MainWindow::on_pushButton_3_clicked()
{
    instructions *ins = new instructions();
    ins->showFullScreen();
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    about_game *about = new about_game();
    about->showFullScreen();
    this->close();
}
