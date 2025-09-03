#pragma once
#include "Objeto.h"
#include "Bala.h"
class Ladrillo:public Objeto
{
public:
	Ladrillo(){
		x = rand() % 2000;
		y = rand()%1000;
		ancho = 100;
		alto = 50;
		eliminado = false;
	}
	~Ladrillo(){}
	void dibujar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, x, y, ancho, alto);
	}
	Rectangle mascara() {
		return Rectangle(x, y, ancho, alto);
	}
	void verificarColisionBalaEnemigos(vector<Bala*>balasEnemigos) {
		for (int i = 0; i < balasEnemigos.size(); i++) {
			if (balasEnemigos[i]->mascara().IntersectsWith(mascara())) {
				eliminado = true;
				balasEnemigos[i]->setEliminado(true);
			}
		}
	}
	bool getEliminado() {
		return eliminado;
	}
private:
	bool eliminado;
};