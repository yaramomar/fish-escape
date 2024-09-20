#include <QKeyEvent>
#include <shark.h>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QList>
#include <QObject>
#include <poison.h>
#include <QKeyEvent>
#include <QTimer>


shark::shark(): QObject(), QGraphicsPixmapItem()
{
    QPixmap sh("/Users/yaraomar/Desktop/figures/Shark.png");
    sh=sh.scaledToWidth(40);
    sh=sh.scaledToHeight(40);
    setPixmap(sh);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);

    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(spray()));
    timer2->start(50);
}


void shark::move()
{  // move shark random
    srand((unsigned) time(NULL));
    int random_number_x = rand() % 1680;
    int random_number_y =  rand() % 320;
    setPos(random_number_x,random_number_y);
 }

void shark::spray()
{
  poison p;
   p.setPos(200,520);
    scene()->addItem(&p);
     p.move();
}
