#pragma once
#include "Entidad.h"
#include "QuarkAbajo.h"
#include "QuarkArriba.h"
class Proton :public Entidad
{
public:
	Proton(int x, int y){
		int dx = rand() % 2 == 0 ? 5 : -5;
		int dy = rand() % 2 == 0 ? 5 : -5;
		quark_u1 = new QuarkArriba(x, y,dx,dy,1);
		quark_u2 = new QuarkArriba(x - quark_u2->getAncho()/2, y + quark_u1->getAlto(),dx,dy,1);
		quark_d1 = new QuarkAbajo(x + quark_u2->getAncho() / 2, y + quark_u1->getAlto(),dx,dy,2);
	}
	~Proton(){}
	void dibujar(Graphics^g) {
		quark_u1->dibujar(g);
		quark_u2->dibujar(g);
		quark_d1->dibujar(g);
	}
	void mover(){
		quark_u1->mover();
		quark_u2->mover();
		quark_d1->mover();
	}
private:
	QuarkArriba*quark_u1;
	QuarkArriba*quark_u2;
	QuarkAbajo*quark_d1;
};
