#pragma once
#include<vector>
using namespace std;
#include "Globo.h"
class Juego
{
public:
	Juego(){
		srand(time(0));
		timer = 0;
		vidas = 10;
		puntos = 0;
	}
	~Juego(){}
	void dibujar(Graphics^g) {
		for (int i = 0; i < globos.size(); i++) {
			globos[i]->dibujar(g);
		}
	}
	void mover() {
		for (int i = 0; i < globos.size(); i++) {
			globos[i]->mover();
		}
	}
	void agregar() {
		if (timer >= 60) {
			globos.push_back(new Globo());
			timer = 0;
		}
		timer++;
	}
	void obtenerRespuesta(int numero_entrada) {
		if (globos.size() <= 0) return;
		if (numero_entrada == globos[0]->getResultado()) {
			puntos += 5;
			globos.erase(globos.begin() + 0);
		}
	}
	void iniciar(Graphics^g) {
		mover();
		dibujar(g);
		agregar();
		verificarGlobos();
	}
	void verificarGlobos() {
		for (int i = 0; i < globos.size(); i++) {
			if (globos[i]->getY() <= -50) {
				globos.erase(globos.begin() + i);
				vidas--;
			}
		}
	}
	int getPuntos() { return puntos; }
	int getVidas() { return vidas; }
private:
	vector<Globo*>globos;
	int timer;
	int vidas;
	int puntos;
};
