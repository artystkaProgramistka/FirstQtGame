#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <player.h>
#include <airscrew.h>
#include <score.h>
#include <health.h>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Airscrew * airscrew;
    Score * score;
    Health * health;
};

#endif // GAME_H
