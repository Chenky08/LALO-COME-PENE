#pragma once
#include "Objeto.h"
class Enemigo :public Objeto
{
public:
	Enemigo(){
		x = rand() % 2000;
		y = rand() % 500;
		int direccion = rand() % 4;
		switch (direccion)
		{
		case 0: // Arriba 
			dx = 0; dy = -2; fil = 0; col = 0; break;
		case 1: // Abajo 
			dx = 0; dy = 2; fil = 1; col = 0; break;
		case 2: // Izquirda 
			dx = -2; dy = 0; fil = 1; col = 1; break;
		case 3: // Derecha 
			dx = 2; dy = 0; fil = 0; col = 1; break;

		}
		tiempo = 0;
		intervalo = rand() % 60 + 40;
	}
	~Enemigo(){}
	void dibujar(Graphics^ g, Bitmap^ img) {
		ancho = img->Width / 2;
		alto = img->Height / 2;
		Rectangle frame = Rectangle(ancho * col, alto * fil, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.5, alto*0.5);
		g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);

		for (int i = 0; i < balas.size(); i++) {
			balas[i]->dibujar(g);
		}

	}
	void agregarBalas() {
		 
		if (tiempo > intervalo) {
			if (dx == -2 && dy == 0) {
				balas.push_back(new Bala(x, y + alto / 4, -5, 0));
			}
			else if (dx == 2 && dy == 0) {
				balas.push_back(new Bala(x + ancho/2, y + alto / 4, 5, 0));
			}
			else if (dx == 0 && dy == 2) {
				balas.push_back(new Bala(x + ancho/4, y + alto/2, 0, 5));
			}
			else if (dx == 0 && dy == -2) {
				balas.push_back(new Bala(x + ancho / 4, y, 0, -5));
			}
			tiempo = 0;
			intervalo = rand() % 600 + 400;
		}
		tiempo++;
	}
	void mover(Graphics^g) {
		if (x + dx<0 || x + dx + ancho>g->VisibleClipBounds.Width) {
			y += dx;
			dx = -dx;
			if (dx < 0) {
				fil = 1;
				col = 1;
			}
			else {
				fil = 0;
				col = 1;
			}
		}
		if (y + dy<0 || y + dy + ancho>g->VisibleClipBounds.Height) {
			x += dy;
			dy = -dy;
			if (dy < 0) {
				fil = 0;
				col = 0;
			}
			else {
				fil = 1;
				col = 0;
			}
		}
		x += dx;
		y += dy;
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->mover();
		}
		verificarLimiteBalas(g);
		agregarBalas();
		eliminarBalas();
	}
	void verificarLimiteBalas(Graphics^ g) {
		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->fueraLimite(g)) {
				balas.erase(balas.begin() + i);
			}
		}
	}
	Rectangle mascara() {
		return Rectangle(x, y, ancho*0.5, alto*0.5);
	}
	vector<Bala*>getBalas() {
		return balas;
	}
	void eliminarBalas() {
		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->getEliminado()) {
				balas.erase(balas.begin() + i);
			}
		}
	}
private:
	vector<Bala*>balas;
	int tiempo;
	int intervalo;
};