#include "lebewesen.h"

Lebewesen::Lebewesen(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie) :
Objekt{x,y, ebene, geschwindigkeit, bildname}, lebensenergie {lebensenergie} {
};

int Lebewesen::aendereEnergie(int deltaEnergie) {
    lebensenergie += deltaEnergie;
    return lebensenergie;
};
