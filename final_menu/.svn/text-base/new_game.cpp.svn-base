#include "new_game.h"
#include "ui_new_game.h"
#include "mainwindow.h"
#include "track.h"
#include <fstream>
#include "lockscreen.h"
using namespace std;
new_game::new_game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new_game)
{
    readScores();
    ui->setupUi(this);
}

new_game::~new_game()
{
    delete ui;
}

void new_game::on_pushButton_clicked()
{
    track *difficulty = new track();
    difficulty->setid(1);
    difficulty->showFullScreen();
    this->close();
}

void new_game::on_pushButton_11_clicked()
{
    MainWindow *main = new MainWindow();
    main->showFullScreen();
    this->close();
}

void new_game::on_pushButton_2_clicked()
{
    readScores();
    if(scores[1] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(2);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_3_clicked()
{
    readScores();
    if(scores[2] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(3);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_4_clicked()
{
    readScores();
    if(scores[3] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(4);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_5_clicked()
{
    readScores();
    if(scores[4] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(5);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_6_clicked()
{    readScores();
     if(scores[5] < 400){
         lockscreen *lock = new lockscreen();
         lock->showFullScreen();

     }
     else{
     track *difficulty = new track();
     difficulty->setid(6);
     difficulty->showFullScreen();
     }
     this->close();
}

void new_game::on_pushButton_7_clicked()
{
    readScores();
    if(scores[6] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(7);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_8_clicked()
{
    readScores();
    if(scores[7] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(8);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_9_clicked()
{
    readScores();
    if(scores[8] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(9);
    difficulty->showFullScreen();
    }
    this->close();
}

void new_game::on_pushButton_10_clicked()
{
    readScores();
    if(scores[9] < 400){
        lockscreen *lock = new lockscreen();
        lock->showFullScreen();

    }
    else{
    track *difficulty = new track();
    difficulty->setid(0);
    difficulty->showFullScreen();
    }
    this->close();
}
void new_game::readScores(){
    ifstream f;
     f.open("../link/1.txt");
     f>>scores[1];
    f.close();

     f.open("../link/2.txt");
    f>>scores[2];
    f.close();

     f.open("../link/3.txt");
    f>>scores[3];
    f.close();

     f.open("../link/4.txt");
    f>>scores[4];
    f.close();

     f.open("../link/5.txt");
    f>>scores[5];
    f.close();

     f.open("../link/6.txt");
    f>>scores[6];
    f.close();

     f.open("../link/7.txt");
    f>>scores[7];
    f.close();

     f.open("../link/8.txt");
    f>>scores[8];
    f.close();

     f.open("../link/9.txt");
    f>>scores[9];
    f.close();

     f.open("../link/0.txt");
    f>>scores[0];
    f.close();
}
