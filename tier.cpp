#include "tier.h"
#include "deko.h"
#include <QGraphicsScene>

Tier::Tier(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie, Tiertyp typ) :
Lebewesen{x,y, ebene, geschwindigkeit, bildname, lebensenergie}, typ {typ} {
};

void Tier::advance(int phase) {
    if (phase == 0){
//        if (!(scene()->collidingItems(this).isEmpty())) {
//            for (auto x : scene()->collidingItems(this)) {
//                if (dynamic_cast<Deko*>(x)) {
//                    if (static_cast<Deko*>(x)->getEbene() == this->ebene) {
//                      this->geschwindigkeit.dx *= -1;
//                    }
//                }
//            }
//        }
        bewegeObjekt();
        setPos(x,y);
        }
}
