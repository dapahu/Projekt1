#ifndef TIER_H
#define TIER_H

#include <stdio.h>
#include "lebewesen.h"

enum Tiertyp {Wolf, Spinne, Gluehwuermchen, Einhorn, Biene};

class Tier : public Lebewesen {
public:
    using Lebewesen::Lebewesen;
    Tier(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie, Tiertyp typ);

protected:
    void advance(int);

private:
    Tiertyp typ;
};

#endif // TIER_H
