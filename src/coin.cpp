#include "coin.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QFont>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "fish.h"
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QTimer>


coin::coin()
{
  QPixmap c("/Users/Lina/Desktop/PROJECT PART A/CS Project/coin.jpg");
  c=c.scaledToWidth(20);
  c=c.scaledToHeight(20);
  setPixmap(c);




   QList<QGraphicsItem *> co = collidingItems();
   for (int i = 0, n = co.size(); i < n; ++i){
       if (typeid(*(co[i])) == typeid(fish))
       {
           scene()->removeItem(co[i]);
           delete co[i];
           coins ++;
           return;
       }

     //  QTimer * timer = new QTimer();
    //   connect(timer,SIGNAL(timeout()),this,scene()->removeItem(c);
     //  timer->start(10);
}

}

/*void coin::disp_coins()
{
    coins = 0;
    setPlainText(QString("Coins=") + QString::number(coins));
    setFont(QFont("arial",20));
    setDefaultTextColor(Qt::red);

}*/

