#include "note.h"

note::note(int dis,int bpm)
{
    setGeometry(1280+dis,245,30,30);
    setAttribute(Qt::WA_TranslucentBackground);

    color = qrand()%2;
    QPixmap p;
    if(color==0) p.load("IMAGES/notes5.png");
    else p.load("IMAGES/notes8.png");
    setPixmap(p);

    timer = new QTimer();
    timer->start(60*bpm);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void note::move()
{
    setGeometry(x()-10,y(),52,52);
    if(x()<-1){
        delete timer;
        delete this;
    }
}
