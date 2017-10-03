#include "deko.h"

Deko::Deko(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, Dekotyp typ) :
Objekt{x,y, ebene, geschwindigkeit, bildname}, typ {typ} {
};

void Deko::advance(int phase) {
    if (!phase){
    bewegeObjekt();
    setPos(x,y);
}
}
