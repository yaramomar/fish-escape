#ifndef COIN_H
#define COIN_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QKeyEvent>

class coin:public QObject,  public QGraphicsPixmapItem
{     Q_OBJECT
public:
    coin();
    void disp_coins();
    int coins;
};

#endif // COIN_H
