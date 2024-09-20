#ifndef NET_H
#define NET_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Net: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Net();
    int x=0;
    int dead();
public slots:
    void move();
};

#endif // NET_H
