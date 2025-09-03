#pragma once
#include "Entidad.h"
class QuarkArriba:public Entidad
{
public:
	QuarkArriba(int x, int y, int dx, int dy, int tipo){
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->tipo = tipo;
	}
	~QuarkArriba(){}
	void dibujar(Graphics^g) {
		g->FillEllipse(Brushes::Green, x, y, ancho, alto);
		Pen^ pen = gcnew Pen(Color::Yellow, 3);
		g->DrawEllipse(pen, x, y, ancho, alto);
		g->DrawString("U", gcnew Font("Arial", 20), Brushes::Black, x + 5, y);
	}
	void mover() {
		x += dx;
		y += dy;
	}
	Rectangle mascara() {
		return Rectangle(x, y, ancho, alto);
	}
private:

};
