#ifndef FISH_H
#define FISH_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class fish:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
int data[8][42];
public:
static int R;
    fish(int [8][42]);
   // void start();

public slots:
    void keyPressEvent(QKeyEvent* event);

};

#endif // FISH_H
