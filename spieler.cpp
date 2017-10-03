#include "spieler.h"
#include "deko.h"
#include "tier.h"
#include "essen.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Spieler::Spieler(int x,int y, Ebene ebene, Geschwindigkeit geschwindigkeit, string bildname, int lebensenergie) :
    Lebewesen{x,y, ebene, geschwindigkeit, bildname, lebensenergie} {
    this->setFlag( ItemIsFocusable, true );
};



void Spieler::advance(int phase) {
    if (!phase) {
        //setPos(x,y);
        //scene()->setSceneRect(QRectF(this->x - 300, 0.f, 600, 800));
        //flag = false;

        return;
    } else {

        if (geschwindigkeit.dx != 0 ){
            bewegeObjekt();
            setPos(x,y);

//            if (!(scene()->collidingItems(this).isEmpty())) {
//                for (auto x : scene()->collidingItems(this)) {
//                    if (dynamic_cast<Deko*>(x)) {
//                        if (static_cast<Deko*>(x)->getEbene() == this->ebene) {
//                            setPos(this->x,this->y);
//                            if (this->collidesWithItem(x)) {
//                                this->x = old_x;
//                                this->y = old_y;
//                                //setPos(this->x,this->y);
//                            }
//                        }
//                    } else if (dynamic_cast<Tier*>(x)) {
//                        if (static_cast<Tier*>(x)->getEbene() == this->ebene) {
//                            //setPos(this->x,this->y);
//                            if (this->collidesWithItem(x)) {
//                                this->lebensenergie -= 5;
//                                //cout << "Autsch!";
//                                if (this->lebensenergie <= 0) {
//                                    //cout << "Game over!";
//                                }

//                            }
//                        }
//                    } else if (dynamic_cast<Essen*>(x)) {
//                        if (static_cast<Essen*>(x)->getEbene() == this->ebene) {
//                            setPos(this->x,this->y);
//                            if (this->collidesWithItem(x)) {
//                                this->lebensenergie += static_cast<Essen*>(x)->getDeltaenergie();
//                                cout << "Mjam";
//                                delete x;
//                            }
//                        }
//                    }
//                }
//            }

        }
    }
}

void Spieler::keyPressEvent( QKeyEvent * event ) {
    if( event->key() == Qt::Key_Right || event->key() == Qt::Key_Left) {
        // do your stuff here
        //      if( (event->key() == Qt::Key_Right && geschwindigkeit.dx < 0 )|| (event->key() == Qt::Key_Left && geschwindigkeit.dx > 0) ){
        //        geschwindigkeit.dx *= -1;
        //      }
        if(event->key() == Qt::Key_Right ){
            geschwindigkeit.dx = 3;
        }else if (event->key() == Qt::Key_Left){
            geschwindigkeit.dx = -3;
        }
        //      if (600 - this->x + scene()->sceneRect()->bottomLeft()->x() < 50) {
        //     scene()->setSceneRect(QRectF(this->x - 300, 0.f, 600, 800));
        //      }
    }
}

void Spieler::keyReleaseEvent(QKeyEvent *event){
    //ToDo: nur fuer die richtigen Tasten
    geschwindigkeit.dx = 0;
}
