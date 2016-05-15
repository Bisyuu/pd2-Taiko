#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QFont>
#include <QTimer>
#include <QGraphicsTextItem>
#include "gameover.h"

class countdown :public QGraphicsTextItem{
    Q_OBJECT
public:
    int time;
    countdown(QGraphicsTextItem *parent = 0);
private:
    QTimer *timer;
private slots:
    void decrease();
};

#endif // COUNTDOWN_H
