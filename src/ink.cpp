#include "ink.h"
#include "octopus.h"
#include "fish.h"
#include "health.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsView>

ink::ink(){
    // drew the rect


    QPixmap i("/Users/yaraomar/Desktop/figures/ink.png");
    i=i.scaledToWidth(40);
    i=i.scaledToHeight(40);
    setPixmap(i);
   //scene()->addItem(this);
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}


void ink::move()
{ //set random position

    srand((unsigned) time(NULL));
       int random_number_x = rand() % 360;
       int random_number_y= rand()% 320;
       setPos(random_number_x,random_number_y);

       QPixmap seaweed("/Users/yaraomar/Desktop/figures/seaweed2.png");
    // if net collides with octopus, destroy both

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(fish))
        {qDebug()<<"colliding";
            // remove ink
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

