#ifndef TRACK_H
#define TRACK_H

#include <QMainWindow>

namespace Ui {
class track;
}

class track : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit track(QWidget *parent = 0);
    int id;
    void setid(int);
    void writeFile(int,int);
    ~track();
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::track *ui;
};

#endif // TRACK_H
