#include "fish.h"
#include "net.h"
#include "octopus.h"
#include "health.h"
#include <QGraphicsScene>
#include <QDebug>

fish::fish(int dataitem[8][42])
{
QPixmap f("/Users/yaraomar/Desktop/figures/fish2.png");
f=f.scaledToWidth(40);
f=f.scaledToHeight(40);
//setPos(645,78);
setPixmap(f);
row=1, column=1;
//R=10;
setPos(40+40*column,40+40*row);
          for(int i=0;i<8;i++)
              for (int j=0;j<42;j++)
                  data[i][j]=dataitem[i][j];



}

void fish::keyPressEvent(QKeyEvent* event)
{
   if(event->key()==Qt::Key_Up&&data[row-1][column]!=-1)
   {
       row--;
     //  qDebug() << " Hello";
   }
   else if(event->key()==Qt::Key_Down&&data[row+1][column]!=-1)
   {

       row++;
   }
   else if(event->key()==Qt::Key_Left&&data[row][column-1]!=-1)
   {

       column--;
   }
   else if(event->key()==Qt::Key_Right &&data[row][column+1]!=-1)
   {

       column++;
   }

   else if (event->key() == Qt::Key_Space)
   {
       // create a Net
       Net * N = new Net();
       N->move();
      scene()->addItem(N);
}
    setPos(40+40*column,40+40*row);



}
