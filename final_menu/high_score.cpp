#include "high_score.h"
#include "ui_high_score.h"
#include "mainwindow.h"
#include <fstream>
using namespace std;
high_score::high_score(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::high_score)
{
    ui->setupUi(this);
}

high_score::~high_score()
{
    delete ui;
}

void high_score::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow();
    main->showFullScreen();
    this->close();
}
void high_score::readScores(){
    char s[20];
    ifstream f;
     f.open("../link/1.txt");
    f>>s;
    f.close();
    ui->label_12->setText(s);

     f.open("../link/2.txt");
    f>>s;
    f.close();
    ui->label_13->setText(s);

     f.open("../link/3.txt");
    f>>s;
    f.close();
    ui->label_14->setText(s);

     f.open("../link/4.txt");
    f>>s;
    f.close();
    ui->label_15->setText(s);

     f.open("../link/5.txt");
    f>>s;
    f.close();
    ui->label_16->setText(s);

     f.open("../link/6.txt");
    f>>s;
    f.close();
    ui->label_17->setText(s);

     f.open("../link/7.txt");
    f>>s;
    f.close();
    ui->label_18->setText(s);

     f.open("../link/8.txt");
    f>>s;
    f.close();
    ui->label_19->setText(s);

     f.open("../link/9.txt");
    f>>s;
    f.close();
    ui->label_20->setText(s);

     f.open("../link/0.txt");
    f>>s;
    f.close();
    ui->label_21->setText(s);
}
