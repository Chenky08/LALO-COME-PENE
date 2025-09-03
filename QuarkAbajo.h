#pragma once
#include "Entidad.h"
class QuarkAbajo :public Entidad
{
public:
	QuarkAbajo(int x,int y,int dx,int dy,int tipo) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->tipo = tipo;
	}
	~QuarkAbajo() {}
	void dibujar(Graphics^ g) {
		g->FillEllipse(Brushes::Red, x, y, ancho, alto);
		Pen^ pen = gcnew Pen(Color::Blue, 3);
		g->DrawEllipse(pen, x, y, ancho, alto);
		g->DrawString("D", gcnew Font("Arial", 20), Brushes::Black, x + 5, y);
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
