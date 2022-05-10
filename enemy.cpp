#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> // rand()
#include "game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){
    // set random position
    int random_number = rand()%700;
    setPos(random_number, 0);

    // drew the rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/enemy1.gif"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    // checking if the bullet is off the screen
    if (pos().y() > 600){
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy deleted";
    }
}
