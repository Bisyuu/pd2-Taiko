#ifndef SCORE_H
#define SCORE_H

#include <QFont>
#include <QGraphicsTextItem>

class score:public QGraphicsTextItem{
public:
    score(QGraphicsTextItem *parent = 0);
    int totalscore;
    void getScroe();
};

#endif // SCORE_H
