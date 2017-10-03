#include "essen.h"

Essen::Essen(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int deltaenergie) :
Objekt{x,y, ebene, geschwindigkeit, bildname}, deltaenergie {deltaenergie} {
};

 int Essen::getDeltaenergie() {
     return deltaenergie;
 }

 void Essen::advance(int phase) {
     if (!phase){
     bewegeObjekt();
     setPos(x,y);
 }
}
