#ifndef OBJEKT_H
#define OBJEKT_H


#include <iostream>
#include <vector>
#include <QGraphicsItem>

using namespace std;

enum Ebene {Vordergrundebene, Hintergrundebene, Spielerebene};
struct Punkt {int x; int y;};
struct Geschwindigkeit {float dx; float dy;};

class Objekt : public QGraphicsPixmapItem  {
public:
    using QGraphicsPixmapItem::QGraphicsPixmapItem;
    Objekt(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname);
    void bewegeObjekt();
    Punkt getPosition();
    Ebene getEbene();

protected:
    void advance(int);
    int x;
    int y;
    int old_x;
    int old_y;
    Ebene ebene;
    Geschwindigkeit geschwindigkeit;
    string bildname;
};

#endif // OBJEKT_H
