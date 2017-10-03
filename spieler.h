#ifndef SPIELER_H
#define SPIELER_H

#include <stdio.h>
#include "lebewesen.h"

class Spieler : public Lebewesen {
public:
    using Lebewesen::Lebewesen;
    Spieler(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie);

protected:
    void advance(int);
    void keyPressEvent( QKeyEvent * );
    void keyReleaseEvent( QKeyEvent *);

private:
    vector<Objekt> rucksack;
};

#endif // SPIELER_H
