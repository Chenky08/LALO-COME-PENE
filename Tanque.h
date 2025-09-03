#pragma once
#include "Objeto.h"
#include "Bala.h"
enum Tecla
{
	Derecha,
	Izquierda,
	Arriba,
	Abajo,
	Ninguno
};
class Tanque:public Objeto
{
public:
	Tanque(){
	
		x = 100;
		y = 100;
		dx = dy = 0;
		col = fil = 0;
	}
	~Tanque(){}
	void dibujar(Graphics^g, Bitmap^img) {
		ancho = img->Width / 3;
		alto = img->Height / 4;
		Rectangle frame = Rectangle(ancho * col, alto * fil, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);

		for (int i = 0; i < balas.size(); i++) {
			balas[i]->dibujar(g);
		}
	}
	void mover(Graphics^g) {
		switch (tecla)
		{
		case Arriba: dx = 0; dy = -2; col++; if (col > 2) col = 0; fil = 3; ultimaTecla = Arriba; break;
		case Abajo: dx = 0; dy = 2; col++; if (col > 2) col = 0; fil = 0; ultimaTecla = Abajo; break;
		case Derecha: dx = 2; dy = 0; col++; if (col > 2) col = 0; fil = 1;  ultimaTecla = Derecha; break;
		case Izquierda: dx = -2; dy = 0; col++; if (col > 2) col = 0; fil = 2;  ultimaTecla = Izquierda; break;
		case Ninguno: dx = 0; dy =0;  break;
		}
		if (x + dx<0 || x + dx + ancho>g->VisibleClipBounds.Width) dx = 0;
		if (y + dy<0 || y + dy + alto>g->VisibleClipBounds.Height) dy = 0;
		x += dx;
		y += dy;

		for (int i = 0; i < balas.size(); i++) {
			balas[i]->mover();
		}
		verificarLimiteBalas(g);
		eliminarBalas();
	
	}
	void verificarLimiteBalas(Graphics^g) {
		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->fueraLimite(g)) {
				balas.erase(balas.begin() + i);
			}
		}
	}
	void setTecla(Tecla tecla) {
		this->tecla = tecla;
	}
	void disparar() {
		switch (ultimaTecla)
		{
		case Derecha:
			balas.push_back(new Bala(x+ancho,y+alto/2 -20,5,0));
			break;
		case Izquierda:
			balas.push_back(new Bala(x , y + alto / 2 -20, -5, 0));
			break;
		case Arriba:
			balas.push_back(new Bala(x + ancho/2, y, 0, -5));
			break;
		case Abajo:
			balas.push_back(new Bala(x + ancho/2, y + alto , 0, 5));
			break;
		}
	}
	void eliminarBalas() {
		for (int i = 0; i < balas.size(); i++) {
			if (balas[i]->getEliminado()) {
				balas.erase(balas.begin() + i);
			}
		}
	}
	vector<Bala*>getBalas() {
		return balas;
	}
private:
	Tecla tecla;
	Tecla ultimaTecla;
	vector<Bala*>balas;
};
