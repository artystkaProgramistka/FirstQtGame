#ifndef AIRSCREW_H
#define AIRSCREW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>

class Airscrew: QObject, QPainter, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Airscrew(QGraphicsItem* parent=0);
public slots:
    void move();
};

#endif // AIRSCREW_H
