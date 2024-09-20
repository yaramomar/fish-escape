#include "health.h"
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

health::health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 100
    Health = 100;

    // add text
    setPlainText(QString("Health=") + QString::number(Health));
    setFont(QFont("arial",20));
    setDefaultTextColor(Qt::green);


}

void health::decrease()
{
    Health= Health-10;
    setPlainText(QString("Health=") + QString::number(Health));
}

int health::getHealth()
{
    return Health;
}
