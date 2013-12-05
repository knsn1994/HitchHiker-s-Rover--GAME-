include "practise_mode.h"
#include "ui_practise_mode.h"
#include "mainwindow.h"

practise_mode::practise_mode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::practise_mode)
{
    ui->setupUi(this);
}

practise_mode::~practise_mode()
{
    delete ui;
}

void practise_mode::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow();
    main->showFullScreen();
    this->close();
}
