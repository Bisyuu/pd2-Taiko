#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1280,720);

    selectMode = new QGraphicsScene();
    selectMode->setSceneRect(0,0,1280,720);
    vi_selectMode = new QGraphicsView(selectMode);
    vi_selectMode->setFixedSize(1280,720);
    vi_selectMode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_selectMode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Game = new QGraphicsScene();
    Game->setSceneRect(0,0,1280,720);
    vi_Game = new QGraphicsView(Game);
    vi_Game->setFixedSize(1280,720);
    vi_Game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_Game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Grade = new QGraphicsScene();
    Grade->setSceneRect(0,0,1280,720);
    vi_Grade = new QGraphicsView(Grade);
    vi_Grade->setFixedSize(1280,720);
    vi_Grade->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_Grade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    gameBN = new QLabel();
    modeBK = new QLabel();
    gradeBK = new QLabel();
    gameButtom = new QLabel();
    button1 = new QLabel();
    button2 = new QLabel();

    gameBN->setGeometry(0,198,1280,165);
    modeBK->setGeometry(0,0,1280,720);
    gradeBK->setGeometry(0,0,1280,720);
    gameButtom->setGeometry(0,357,1280,363);
    button1->setGeometry(50,50,124,232);
    button2->setGeometry(224,50,124,232);

    QPixmap p1("IMAGES/menuBK.jpg");
    QPixmap p2("IMAGES/gradeBK.jpg");
    QPixmap p3("IMAGES/modeBK.png");
    QPixmap p4("IMAGES/notes9.png");
    QPixmap p5("IMAGES/notes10.png");
    QPixmap p6("IMAGES/Buttom.jpg");

    ui->BK->setPixmap(p1);
    gradeBK->setPixmap(p2);
    modeBK->setPixmap(p3);
    gameButtom->setPixmap(p6);
    button1->setPixmap(p4);
    button2->setPixmap(p5);

    button1->setAttribute(Qt::WA_TranslucentBackground);
    button2->setAttribute(Qt::WA_TranslucentBackground);

    selectMode->addWidget(modeBK);
    selectMode->addWidget(button1);
    selectMode->addWidget(button2);
    Game->addWidget(gameButtom);
    Grade->addWidget(gradeBK);

    mode1 = new QPushButton();
    mode2 = new QPushButton();
    mode3 = new QPushButton();
    playagain = new QPushButton();
    exit = new QPushButton();

    mode1->setGeometry(290,600,200,80);
    mode2->setGeometry(540,600,200,80);
    mode3->setGeometry(790,600,200,80);
    playagain->setGeometry(50,200,200,80);
    exit->setGeometry(300,200,200,80);

    mode1->setText(QObject::tr("NORMAL"));
    mode2->setText(QObject::tr("HARD"));
    mode3->setText(QObject::tr("MANIAC"));
    playagain->setText(tr("Play again"));
    exit->setText(tr("Exit"));

    mode1->setFont(QFont("Times",16));
    mode2->setFont(QFont("Times",16));
    mode3->setFont(QFont("Times",16));
    playagain->setFont(QFont("Times",16));
    exit->setFont(QFont("Times",16));

    selectMode->addWidget(mode1);
    selectMode->addWidget(mode2);
    selectMode->addWidget(mode3);
    Grade->addWidget(playagain);
    Grade->addWidget(exit);



    connect(mode1,SIGNAL(clicked(bool)),this,SLOT(NormalMode()));
    connect(mode2,SIGNAL(clicked(bool)),this,SLOT(HardMode()));
    connect(mode3,SIGNAL(clicked(bool)),this,SLOT(ManiacMode()));
    connect(ui->p,SIGNAL(clicked(bool)),this,SLOT(changeScene()));
    connect(ui->p_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(playagain,SIGNAL(clicked(bool)),this,SLOT(reStart()));
    connect(exit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeScene()
{
    setCentralWidget(vi_selectMode);
}

void MainWindow::NormalMode()
{    
    whichMode = 1;
    setCentralWidget(vi_Game);

    gameBN1.load("IMAGES/gameBN1.jpg");
    gameBN->setPixmap(gameBN1);

    count = new countdown();

    myscore = new score();

    Game->addWidget(gameBN);
    Game->addItem(myscore);
    Game->addItem(count);

    for(int j=0,delay=0;j<25;j++){
        delay += qrand()%200+15;
        note1[j] = new note(delay,1);
        Game->addWidget(note1[j]);
    }
}

void MainWindow::HardMode()
{
    whichMode = 2;
    setCentralWidget(vi_Game);

    gameBN1.load("IMAGES/gameBN2.jpg");
    gameBN->setPixmap(gameBN1);

    count = new countdown();

    myscore = new score();

    Game->addWidget(gameBN);
    Game->addItem(myscore);
    Game->addItem(count);

    for(int i=0,delay=0;i<50;i++){
        delay += qrand()%200+10;
        note2[i] = new note(delay,1.5);
        Game->addWidget(note2[i]);
    }
}

void MainWindow::ManiacMode()
{
    whichMode = 3;
    setCentralWidget(vi_Game);

    gameBN1.load("IMAGES/gameBN3.jpg");
    gameBN->setPixmap(gameBN1);

    count = new countdown();

    myscore = new score();

    Game->addWidget(gameBN);
    Game->addItem(myscore);
    Game->addItem(count);

    for(int i=0,delay=0;i<75;i++){
        delay += qrand()%100+10;
        note3[i] = new note(delay,2);
        Game->addWidget(note3[i]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D){
        if(whichMode==1){
            if(j<25&&note1[j]->x()>320&&note1[j]->x()<480){
                if(note1[j]->color==1){
                    myscore->getScroe();
                    note1[j]->hide();
                    j++;
                }
           }
            else if(j<25&&note1[j]->x()<320) j++;
        }
        else if(whichMode==2){
            if(j<50&&note2[j]->x()>320&&note2[j]->x()<480){
                if(note2[j]->color==1){
                    myscore->getScroe();
                    note2[j]->hide();
                    j++;
                }
            }
            else if(j<50&&note2[j]->x()<320) j++;
        }

        else if(whichMode==3){
            if(j<75&&note3[j]->x()>320&&note3[j]->x()<480){
                if(note3[j]->color==1){
                    myscore->getScroe();
                    note3[j]->hide();
                    j++;
                }
            }
            else if(j<75&&note3[j]->x()<320) j++;
        }
    }

    if(event->key() == Qt::Key_K){
        if(whichMode==1){
            if(j<25&&note1[j]->x()>320&&note1[j]->x()<480){
                if(note1[j]->color==0){
                    myscore->getScroe();
                  note1[j]->hide();
                    j++;
                }
            }
            else if(j<25&&note1[j]->x()<320) j++;
        }

        else if(whichMode==2){
            if(j<50&&note2[j]->x()>320&&note2[j]->x()<480){
                if(note2[j]->color==0){
                    myscore->getScroe();
                    note2[j]->hide();
                    j++;
               }
            }
            else if(j<50&&note2[j]->x()<320) j++;
        }

        else if(whichMode==3){
            if(j<75&&note3[j]->x()>320&&note3[j]->x()<480){
                if(note3[j]->color==0){
                    myscore->getScroe();
                    note3[j]->hide();
                    j++;
                }
            }
            else if(j<75&&note3[j]->x()<320) j++;
        }
    }
}

void MainWindow::reStart()
{
    j=0;
    whichMode = 0;
    delete myscore;
    delete count;

    vi_selectMode = new QGraphicsView(selectMode);
    vi_selectMode->setFixedSize(1280,720);
    vi_selectMode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_selectMode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vi_Game = new QGraphicsView(Game);
    vi_Game->setFixedSize(1280,720);
    vi_Game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_Game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vi_Grade = new QGraphicsView(Grade);
    vi_Grade->setFixedSize(1280,720);
    vi_Grade->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vi_Grade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(vi_selectMode);
}
