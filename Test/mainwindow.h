#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include <QThread>
#include <QPixmap>
#include <QLabel>
#include <QDebug>

#include "note.h"
#include "score.h"
#include "restart.h"
#include "countdown.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

    int j=0,whichMode = 0;
    score *myscore;
    countdown *count;

    QGraphicsScene *selectMode;
    QGraphicsScene *Grade;
    QGraphicsScene *Game;

    QGraphicsView *vi_selectMode;
    QGraphicsView *vi_Grade;
    QGraphicsView *vi_Game;
private:
    Ui::MainWindow *ui;

    QLabel *gameBK;
    QLabel *gradeBK;
    QLabel *modeBK;
    QLabel *gameBN;
    QLabel *gameButtom;
    QLabel *button1;
    QLabel *button2;

    QPixmap gameBN1;

    QPushButton *mode1;
    QPushButton *mode2;
    QPushButton *mode3;
    QPushButton *playagain;
    QPushButton *exit;

    note *note1[25];
    note *note2[50];
    note *note3[75];

private slots:
    void changeScene();
    void NormalMode();
    void HardMode();
    void ManiacMode();
    void reStart();
};

#endif // MAINWINDOW_H
