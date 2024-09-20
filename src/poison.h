#ifndef POISON_H
#define POISON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class poison: public QObject, public QGraphicsPixmapItem{
Q_OBJECT

    public:
       poison();
    public slots:
       void move();
    };
#endif // POISON_H
