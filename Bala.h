#pragma once
#include "Objeto.h"
class Bala:public Objeto
{
public:
	Bala(int x,int y, int dx,int dy){
		this->x = x;
		this->y = y;
		ancho = 30;
		alto = 30;
		this->dx = dx;
		this->dy = dy;
		eliminado = false;
	}
	~Bala(){}
	void setEliminado(bool eliminado) {
		this->eliminado = eliminado;
	}
	bool getEliminado() {
		return eliminado;
	}
	void dibujar(Graphics^g) {
		g->FillEllipse(Brushes::Red, x, y, ancho,alto);
	}
	void mover() {
		x += dx;
		y += dy;
	}
	bool fueraLimite(Graphics^ g) {
		if (x + dx<0 || x + dx>g->VisibleClipBounds.Width) return true;
		if (y + dy<0 || y + dy>g->VisibleClipBounds.Height) return true;
		return false;
	}

	Rectangle mascara() {
		return Rectangle(x, y, ancho, alto);
	}
	
private:
	bool eliminado;
};

