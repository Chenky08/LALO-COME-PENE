#pragma once
#include "Entidad.h"
#include "QuarkAbajo.h"
#include "QuarkArriba.h"
class Neutron :public Entidad
{
public:
	Neutron(int x, int y) {
		int dx = rand() % 2 == 0 ? 5 : -5;
		int dy = rand() % 2 == 0 ? 5 : -5;
		quark_d1 = new QuarkAbajo(x, y, dx, dy,2);
		quark_d2 = new QuarkAbajo(x - quark_d2->getAncho() / 2, y + quark_u1->getAlto(), dx, dy,2);
		quark_u1 = new QuarkArriba(x + quark_d1->getAncho() / 2, y + quark_u1->getAlto(), dx, dy,1);
	}
	~Neutron() {}
	void dibujar(Graphics^ g) {
		quark_u1->dibujar(g);
		quark_d2->dibujar(g);
		quark_d1->dibujar(g);
	}
	void mover() {
		quark_u1->mover();
		quark_d2->mover();
		quark_d1->mover();
	}
private:
	QuarkArriba* quark_u1;
	QuarkAbajo* quark_d1;
	QuarkAbajo* quark_d2;
};
