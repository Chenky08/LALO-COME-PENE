#pragma once

#include "Tanque.h"
#include "Ladrillo.h"
#include "Enemigo.h"
class Juego
{
public:
	Juego(int t,int l) {
		tanque = new Tanque();
		int i = 0;
		while (i < t) {
			enemigos.push_back(new Enemigo());
			i++;
		}
		i = 0;
		while (i < l) {
			ladrillos.push_back(new Ladrillo());
			i++;
		}
	}
	~Juego(){}
	void dibujar(Graphics^g,Bitmap^imgTanque,Bitmap^imgEnemigo,Bitmap^imgLadrillo) {
		tanque->dibujar(g,imgTanque);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->dibujar(g, imgEnemigo);
		}
		for (int i = 0; i < ladrillos.size(); i++) {
			ladrillos[i]->dibujar(g, imgLadrillo);
		}
	}
	void mover(Graphics^ g) {
		tanque->mover(g);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(g);
		}
	}
	void verificarColisionLadrillos() {
		for (int i = 0; i < ladrillos.size(); i++) {
			for (int j = 0; j < enemigos.size(); j++) {
				ladrillos[i]->verificarColisionBalaEnemigos(enemigos[j]->getBalas());
			}
		}
		for (int i = 0; i < ladrillos.size(); i++) {
			if (ladrillos[i]->getEliminado()) {
				ladrillos.erase(ladrillos.begin() + i);
			}
		}
	}
	void iniciar(Graphics^g,Bitmap^imgTanque,Bitmap^imgEnemigo,Bitmap^imgLadrillo) {
		dibujar(g,imgTanque,imgEnemigo,imgLadrillo);
		mover(g);
		verificarColisionConEnemigos();
		verificarColisionLadrillos();
	}
	Tanque* getTanque() {
		return tanque;
	}
	void verificarColisionConEnemigos() {
		for (int i = 0; i < enemigos.size(); i++) {
			for (int j = 0; j < tanque->getBalas().size(); j++) {
				if (enemigos[i]->mascara().IntersectsWith(tanque->getBalas()[j]->mascara())) {
					enemigos.erase(enemigos.begin() + i);
					tanque->getBalas()[j]->setEliminado(true);
				}
			}
		}
	}
private:
	Tanque* tanque;
	vector<Enemigo*>enemigos;
	vector<Ladrillo*>ladrillos;
};

