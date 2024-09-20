#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <cmath>
#include <set>
//#include <bits/stdc++.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <fish.h>
#include <stack>
#include <QTimer>
#define ROW 42
#define COL 8

// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef std::pair<double, std::pair<int, int> > pPair;

// A structure to hold the necessary parameters
struct cell {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

class boss: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    fish* ptr;
    std::stack<Pair> Pathfinal;
public:
    boss();
    void getshortestpath();
    boss(int [10][10], fish *);
    bool isValid(int row, int col);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    void aStarSearch(int grid[][COL], Pair src, Pair dest);






public slots:
   void spawn();
   void move();

};

#endif // BOSS_H
