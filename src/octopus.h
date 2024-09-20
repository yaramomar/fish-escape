#ifndef OCTOPUS_H
#define OCTOPUS_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <ink.h>
#include <QGraphicsRectItem>
#include <QObject>


class octopus: public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
octopus();
public slots:
void spray();
void move();
};

#endif // OCTOPUS_H
