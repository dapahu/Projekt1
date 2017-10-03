#ifndef ESSEN_H
#define ESSEN_H

#include <stdio.h>
#include "objekt.h"

class Essen : public Objekt  {
public:
    using Objekt::Objekt;
    Essen(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int deltaenergie);

private:
    int deltaenergie;

public:
    int getDeltaenergie();

protected:
    void advance(int);

};
#endif // ESSEN_H
