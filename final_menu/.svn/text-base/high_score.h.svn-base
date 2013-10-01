#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

#include <QMainWindow>

namespace Ui {
class high_score;
}

class high_score : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit high_score(QWidget *parent = 0);
    void readScores();
    ~high_score();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::high_score *ui;
};

#endif // HIGH_SCORE_H
