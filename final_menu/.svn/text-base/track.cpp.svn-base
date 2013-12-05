#include "track.h"
#include "ui_track.h"
#include "new_game.h"
#include <fstream>
using namespace std;
track::track(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::track)
{
    ui->setupUi(this);
}

track::~track()
{
    delete ui;
}
void track::setid(int n){
    id = n;
}
void track::on_pushButton_3_clicked()
{
    new_game *newgame = new new_game();
    newgame->showFullScreen();
    this->close();
}

void track::on_pushButton_clicked()
{
    writeFile(id,0);
    system("../makeFiles/physics");
}

void track::on_pushButton_2_clicked()
{
    writeFile(id,1);
    system("../makeFiles/physics");

}

void track::on_pushButton_4_clicked()
{
    writeFile(id,2);
    system("../makeFiles/physics");

}
void track::writeFile(int a,int b){
    ofstream f;
    f.open("../link/trackID.txt");
    f<<a<<" "<<b;
    f.close();
}
