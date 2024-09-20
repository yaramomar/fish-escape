#include "net.h"
#include <QTimer>
#include "fish.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QList>
#include "octopus.h"



Net::Net()
{
    // drew the rect
    //setRect(0,0,10,50);
    //graphic

  QPixmap nets("/Users/yaraomar/Desktop/figures/Net.png");

    // connect
   nets=nets.scaledToWidth(40);
   nets=nets.scaledToHeight(40);
   setPixmap(nets);
   //setPos(200,200);


    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);

}

void Net::move()
{
    //set random position

                int random_number_x = rand() % 480;
                int random_number_y = rand()% 320;
                setPos(random_number_x,random_number_y);

     QPixmap seaweed("/Users/yaraomar/Desktop/figures/seaweed2.png");
    // if net collides with octopus, destroy both
    QList<QGraphicsItem *> net = collidingItems();
    for (int i = 0, n = net.size(); i < n; ++i){
       if (typeid(*(net[i])) == typeid(octopus))
        {
            // remove them both
            scene()->removeItem(net[i]);
            scene()->removeItem(this);
            x=x+1;
           // qDebug()<<x;
            return;

        }
        if(typeid(*(net[i])) == typeid(seaweed))
                {
                    // remove net
                    scene()->removeItem(net[i]);
                    // delete net
                    delete net[i];
                    return;
                }

    }
}

int Net::dead()
{
    return x;
}
