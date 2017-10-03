#ifndef DEKO_H
#define DEKO_H

#include <stdio.h>
#include "objekt.h"

enum Dekotyp {Wolke, Stein, Baum};

class Deko : public Objekt  {
public:
    using Objekt::Objekt;
    Deko(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, Dekotyp typ);

protected:
    void advance(int);

private:
    Dekotyp typ;
};

#endif // DEKO_H
