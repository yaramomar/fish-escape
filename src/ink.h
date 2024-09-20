#ifndef INK_H
#define INK_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class ink: public QObject, public QGraphicsPixmapItem{
Q_OBJECT

    public:
       ink();
    public slots:
       void move();
    };
#endif // INK_H
