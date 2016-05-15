#include "gameover.h"
#include "mainwindow.h"

extern MainWindow *w;

gameover::gameover(QGraphicsTextItem *parent):
    QGraphicsTextItem(parent)
{
    w->setCentralWidget(w->vi_Grade);

    setPlainText(QString("Total Score: ") + QString::number(w->myscore->totalscore));
    setFont(QFont("Times",28));
    w->Grade->addItem(this);
    w->Game->removeItem(w->myscore);
    w->Game->removeItem(w->count);
    this->setPos(100,100);
}
