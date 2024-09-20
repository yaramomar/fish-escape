#ifndef SHARK_H
#define SHARK_H
#include <QGraphicsRectItem>
#include <QObject>

class shark: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    shark();

public slots:
    void move();
    void spray();

};

#endif // SHARK_H
