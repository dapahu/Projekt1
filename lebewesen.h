#ifndef LEBEWESEN_H
#define LEBEWESEN_H


#include <stdio.h>
#include "objekt.h"

class Lebewesen : public Objekt  {
public:
    using Objekt::Objekt;
    Lebewesen(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie);
    int aendereEnergie(int deltaEnergie);

protected:
    int lebensenergie;
};

#endif // LEBEWESEN_H
