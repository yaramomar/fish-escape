#include "octopus.h"
#include <QTimer>
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include <QPixmap>
#include <QList>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>

octopus::octopus(): QObject()
{
    QPixmap oct("/Users/yaraomar/Desktop/figures/octopus.png");
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
     timer2->start(10);

}

void octopus::spray()
{
    ink * innk = new ink();
   innk->setPos(280,240);
   scene()->addItem(innk);
    innk->move();
}

void octopus::move()
{

        srand((unsigned) time(NULL));
        int random_number_x = rand() % 1680;
        int random_number_y = rand() % 320;
        setPos(random_number_x,random_number_y);
}
