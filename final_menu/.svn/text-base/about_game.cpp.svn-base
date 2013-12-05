#include "about_game.h"
#include "ui_about_game.h"
#include "mainwindow.h"

about_game::about_game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about_game)
{
    ui->setupUi(this);
}

about_game::~about_game()
{
    delete ui;
}

void about_game::on_pushButton_clicked()
{
    MainWindow * main = new MainWindow();
    main->showFullScreen();
    this->close();
}
