#include "bigboss.h"
#include <QTimer>
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include <QPixmap>
#include <QList>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
#include "shark.h"
#include "octopus.h"

Bigboss::Bigboss(): QObject()
{
    QPixmap oct("/Users/yaraomar/Desktop/figures/boss.png");
    //set dimensions of octopus
    oct=oct.scaledToWidth(40);
    oct=oct.scaledToHeight(40);
    setPixmap(oct);
   // setPos(200,200);



    // connect
   QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spray()));
    timer->start(50);

    QTimer * timer2 = new QTimer(this);
     connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
     timer2->start(20);

}

void Bigboss::spray()
{
    shark * s = new shark();

   scene()->addItem(s);

   octopus * o = new octopus();

  scene()->addItem(o);

}

void Bigboss::move()
{

        srand((unsigned) time(NULL));
        int random_number_x = rand() % 1680;
        int random_number_y = rand() % 320;
        setPos(random_number_x,random_number_y);
}
