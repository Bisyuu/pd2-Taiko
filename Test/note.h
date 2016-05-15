#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QImage>
#include <QPixmap>

class note:public QLabel
{
    Q_OBJECT
public:
    int color;
    note(int dis = 0,int bpm =0);
private:
    QTimer *timer;
private slots:
    void move();
};

#endif // NOTE_H
