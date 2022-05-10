#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QGraphicsScene>
//#include <QGraphicsView>
#include <QMediaPlayer>
#include <QImage>


Game::Game(QWidget *parent){
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //setBackgroundBrush(QBrush(QImage(":/images/bg1.png")));

    //visualize the scene:
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // create the player
    Player * player = new Player();
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(250,500);
    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Airscrew * airscrew = new Airscrew(player);
    airscrew->setPos(250,120);

    // add the item to the scene
    scene->addItem(player);
    scene->addItem(airscrew);

    //create the score and health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // play background music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bg.mp3"));
    music->play();

    show();
}
