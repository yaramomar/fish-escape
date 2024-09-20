#include "poison.h"
#include "ink.h"
#include "octopus.h"
#include "fish.h"
#include "health.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsView>

poison::poison(){
    // drew the rect


    QPixmap p("/Users/yaraomar/Desktop/figures/poison.png");
    p=p.scaledToWidth(40);
    p=p.scaledToHeight(40);
    setPixmap(p);
   //scene()->addItem(this);
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}


void poison::move()
{ //set random position

    srand((unsigned) time(NULL));
       int random_number_x = 480+ rand() % 240;
       int random_number_y= rand()% 320;
       setPos(random_number_x,random_number_y);

       QPixmap seaweed("/Users/yaraomar/Desktop/figures/seaweed2.png");


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(fish))
        {qDebug()<<"colliding";

            scene()->removeItem(this);

          health h;
          h.decrease();
            return;
        }
       else if(typeid(*(colliding_items[i])) == typeid(seaweed))
                {
                    // remove net
                    scene()->removeItem(this);
                    // delete net
          //          delete colliding_items[i];
                    return;
                }

    }
}

