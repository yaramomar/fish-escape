#ifndef BIGBOSS_H
#define BIGBOSS_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <ink.h>
#include <QGraphicsRectItem>
#include <QObject>



class Bigboss: public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
Bigboss();
public slots:
void spray();
void move();
};

#endif // BIGBOSS_H
