#pragma once
#include "Entidad.h"
#include "QuarkAbajo.h"
#include "QuarkArriba.h"
#include "Proton.h"
#include "Neutron.h"
#include<vector>
using namespace std;
class Juego
{
public:
	Juego(){
		int cantidadQuarks = 50;
		int i = 0;
		while (i < cantidadQuarks) {
			int tipo = rand() % 2;
			int x = rand() % 700;
			int y = rand() % 500;
			int dx = rand() % 2 == 0 ? 5 : -5;
			int dy = rand() % 2 == 0 ? 5 : -5;
			if (tipo == 0) {
				quarks.push_back(new QuarkAbajo(x, y, dx,dy,2));
			}
			else {
				quarks.push_back(new QuarkArriba(x, y,dx,dy,1));
			}
			i++;
		}
	}
	~Juego(){}
	void dibujar(Graphics^ g) {
		for (int i = 0;i < quarks.size();i++) {
			quarks[i]->dibujar(g);
		}
	}
	void mover() {
		for (int i = 0;i < quarks.size();i++) {
			quarks[i]->mover();
		}
	}
	void iniciar(Graphics^g) {
		dibujar(g);
		mover();
		creacionDeProtones();
	}
	void creacionDeProtones() {
		for (int i = 0;i < quarks.size();i++) {
			for (int j = 0;j < quarks.size();j++) {
				for (int k = 0;k < quarks.size();k++) {
					if (i != j && i != k && j != k) {
						if(quarks[i]->getTipo()==1 && quarks[i]->mascara().IntersectsWith(quarks[j]->mascara()) && 
							quarks[j]->getTipo()==1 && quarks[k]->getTipo()==2 && 
							quarks[i]->mascara().IntersectsWith(quarks[k]->mascara())) {
							quarks[i]->setEliminar(true);
							quarks[j]->setEliminar(true);
							quarks[k]->setEliminar(true);
							quarks.push_back(new Proton(quarks[i]->mascara().X, quarks[i]->mascara().Y));
						}
					}
				}
			}
		}
		for (int i = 0;i < quarks.size();i++) {
			if (quarks[i]->getEliminar()) {
				quarks.erase(quarks.begin() + i);
			}
		}
	} 
	void creacionDeNeutrones() {
	}
private:
	vector<Entidad*>quarks;
};
