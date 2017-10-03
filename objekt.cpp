#include "objekt.h"


Objekt::Objekt(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname) :
QGraphicsPixmapItem {QPixmap::fromImage(QImage(QString::fromStdString(bildname)))},
  x {x}, y {y}, ebene {ebene}, geschwindigkeit {geschwindigkeit}, bildname {bildname}, old_x{x}, old_y{y}{
    qreal rEb = 0;
    if (ebene == Ebene::Spielerebene){
        rEb = 1.0;
    } else if ( ebene == Ebene::Hintergrundebene){
        rEb = 0.0;
    } else if ( ebene == Ebene::Vordergrundebene){
        rEb = 2.0;
    }

    this->setZValue(rEb);

};

void Objekt::bewegeObjekt() {
    old_x = x;
    old_y = y;
    x += geschwindigkeit.dx;
    y += geschwindigkeit.dy;
};

Punkt Objekt::getPosition() {
    return Punkt{x,y};
};

void Objekt::advance(int phase) {
    if (!phase){
    bewegeObjekt();
    setPos(mapToParent(0,y));

    }
}

Ebene Objekt::getEbene() {
    return ebene;
}
