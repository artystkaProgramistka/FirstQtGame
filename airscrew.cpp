#include "airscrew.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include <QPainter>

Airscrew::Airscrew(QGraphicsItem* parent): QObject(), QPainter(), QGraphicsPixmapItem(parent)
{
    // draw the rect
    setPixmap(QPixmap(":/images/smiglo1.gif"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Airscrew::move(){

    // rotate
    //setPos(x(),y()-10);
    setTransformOriginPoint(240,95);
    setRotation(180);
}
