#include "mainwindow.h"
#include <QApplication>

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

#include <iostream>
#include <vector>
#include "objekt.h"
#include "lebewesen.h"
#include "essen.h"
#include "tier.h"
#include "spieler.h"
#include "deko.h"

int main(int argc, char *argv[])
{
//    vector<Objekt> objekte;
//    Spieler s = Spieler(1, 0, Spielerebene, Geschwindigkeit{0,0}, "Spieler.jpg", 1000);
//    objekte.push_back(s);
//    Deko d = Deko(28, 15, Hintergrundebene, Geschwindigkeit{3,0}, "Wolke.jpg", Wolke);
//    objekte.push_back(d);
//    Essen e = Essen(40, 10, Spielerebene, Geschwindigkeit{0,0}, "Essen.jpg", 10);
//    objekte.push_back(e);
//    Tier t = Tier(4, 0, Spielerebene, Geschwindigkeit{10,0}, "Wolf.jpg", Wolf);
//    objekte.push_back(t);

    QApplication app(argc, argv);


    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 8000, 800);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    Tier * t = new Tier(0, 600, Ebene::Spielerebene, Geschwindigkeit{1,0}, ":/Images/blume.png", Wolf);
    t->setOpacity(23);
    t->setPos(0,600);
    scene.addItem(t);

    Tier * t2 = new Tier(800, 600, Ebene::Spielerebene, Geschwindigkeit{-2,0}, ":/Images/bird.png", Wolf);

    t2->setPos(800,600);
    scene.addItem(t2);

    Tier * t4 = new Tier(0, 200, Ebene::Vordergrundebene, Geschwindigkeit{2,0}, ":/Images/bird.png", Wolf);

    t4->setPos(0,200);
    scene.addItem(t4);
    Deko * w1 = new Deko(500, 100, Spielerebene, Geschwindigkeit{1,0}, ":/Images/Wolke.png", Dekotyp::Wolke);
    w1->setPos(500,100);
    scene.addItem(w1);
    Deko * w2 = new Deko(100, 100, Spielerebene, Geschwindigkeit{1,0}, ":/Images/Wolke.png", Dekotyp::Wolke);
    w2->setPos(100,100);
    scene.addItem(w2);
    Deko * w3 = new Deko(200, 300, Spielerebene, Geschwindigkeit{1,0}, ":/Images/Wolke.png", Dekotyp::Wolke);
    w3->setPos(200,300);
    scene.addItem(w3);

    //Tier * t3 = new Tier(400, 600, Spielerebene, Geschwindigkeit{0,0}, ":/Images/blume.png", Wolf);
    Deko * d1 = new Deko(200, 600, Hintergrundebene, Geschwindigkeit{0,0}, ":/Images/Stein.png", Dekotyp::Stein);

    //t3->setPos(400,600);
    //scene.addItem(t3);

    d1->setPos(200,600);
    scene.addItem(d1);

    Essen * e1 = new Essen(100, 600, Spielerebene,Geschwindigkeit{0,0}, ":/Images/Kirsche.png", 5);
    e1->setPos(100,600);
    scene.addItem(e1);

    auto * s1 = new Spieler(49, 600, Spielerebene, Geschwindigkeit{0,0}, ":/Images/Spieler.png", 50);
    s1->setPos(49,600);

    scene.addItem(s1);


    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/cheese.jpg"));
//! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
//! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice"));
    view.resize(800, 800);
    view.centerOn(s1);
    view.show();


    s1->setActive(true);
    s1->setFocus();

    cout << " we hqve focus" << s1->hasFocus();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(5);

    return app.exec();

}
