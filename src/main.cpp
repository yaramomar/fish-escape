#include "mainwindow.h"
#include "net.h"
#include"fish.h"
#include "health.h"
#include "octopus.h"
#include "shark.h"
#include "bigboss.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QGraphicsScene scene;
    QGraphicsView view;
    view.setFixedSize(2000,400);
    view.setWindowTitle("Fish Game");
    QBrush brush(Qt::black);
   // setPlainText(QString("Level 1"));
   // setFont(QFont("arial",20));
   // setDefaultTextColor(Qt::white);

    view.setBackgroundBrush(brush);
    health h;
    h.setPos(h.x(), h.y());
    scene.addItem(&h);
    QFile file("/Users/yaraomar/Desktop/figures/final board.txt");
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    int boarddata[8][42];
    QString temp;

    for (int i=0;i<8;i++)
        for (int j=0;j<42;j++)
        {
         stream>>temp;
         boarddata[i][j]=temp.toInt();
        }

    //adding other aspects
    QGraphicsPixmapItem dataimage[8][42];
    QPixmap Sea("/Users/yaraomar/Desktop/figures/Sea.jpeg");
    QPixmap seaweed("/Users/yaraomar/Desktop/figures/seaweed2.png");
    QPixmap starfish("/Users/yaraomar/Desktop/figures/starfish.png");
    QPixmap seahorse("/Users/yaraomar/Desktop/figures/seahorse.png");
    QPixmap seashells("/Users/yaraomar/Desktop/figures/seashells.png");
    QPixmap crab("/Users/yaraomar/Desktop/figures/crab.png");


    Sea=Sea.scaledToWidth(40);
    Sea=Sea.scaledToHeight(40);
    seaweed=seaweed.scaledToWidth(40);
    seaweed=seaweed.scaledToHeight(40);
    starfish=starfish.scaledToWidth(40);
    starfish=starfish.scaledToHeight(40);
    seahorse=seahorse.scaledToWidth(40);
    seahorse=seahorse.scaledToHeight(40);
    seashells=seashells.scaledToWidth(40);
    seashells=seashells.scaledToHeight(40);
    crab=crab.scaledToWidth(40);
    crab=crab.scaledToHeight(40);

    for (int i=0;i<8;i++)
        for (int j=0;j<42;j++)
        {
            if(boarddata[i][j]==-1)
                dataimage[i][j].setPixmap(seaweed);

            else if(boarddata[i][j]==-6)
                dataimage[i][j].setPixmap(starfish);

            else if(boarddata[i][j]==-8)
                dataimage[i][j].setPixmap(seahorse);

            else if(boarddata[i][j]==-7)
                dataimage[i][j].setPixmap(seashells);

            else if(boarddata[i][j]==-9)
                dataimage[i][j].setPixmap(crab);

            else
                dataimage[i][j].setPixmap(Sea);
            dataimage[i][j].setPos(40+40*j,40+40*i);
            scene.addItem(&dataimage[i][j]);
        }


    fish f(boarddata);
    scene.addItem(&f);
    f.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    f.setFocus();
    Net n;


//level 1
    octopus o;
    scene.addItem(&o);
    shark s;
    scene.addItem(&s);
Bigboss b;
scene.addItem(&b);


//level 2
if(h.getHealth()!=0 && o.isActive()==false)
{

   // fish::R=8;
}



    view.setScene(&scene);
    view.show();
    return a.exec();
}
