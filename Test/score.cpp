#include "score.h"

score::score(QGraphicsTextItem *parent):
    QGraphicsTextItem(parent)
{
    totalscore = 0;
    setPlainText(QString("Score: ") + QString::number(totalscore));
    setFont(QFont("Times",25));
    this->setPos(50,0);
}

void score::getScroe()
{
    totalscore++;
    setPlainText(QString("Score: ") + QString::number(totalscore));
}
