#include "countdown.h"

countdown::countdown(QGraphicsTextItem *parent):
    QGraphicsTextItem(parent)
{
    time = 30;
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));

    setPlainText(QString("Time: ") + QString::number(time));
    setFont(QFont("Times",25));
    this->setPos(1000,0);
}

void countdown::decrease()
{
    if(time==0){
        delete timer;
        gameover *over = new gameover();
    }
    else time--;
    setPlainText(QString("Time: ") + QString::number(time));
}
