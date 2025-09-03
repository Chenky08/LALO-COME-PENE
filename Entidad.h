#pragma once
using namespace System::Drawing;
#include<iostream>
class Entidad
{
public:
	Entidad(){
		ancho = 50;
		alto = 50;
		eliminar = false;
		x = 0;
		y = 0;
		dx = 0;
		dy = 0;
	}
	~Entidad(){}
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	void virtual dibujar(Graphics^g) {}
	void virtual mover() {};
	Rectangle virtual mascara() {
		return Rectangle(x, y, ancho, alto);
	}
	int getTipo() { return tipo; }
	bool getEliminar() { return eliminar; }
	void setEliminar(bool eliminar) { this->eliminar = eliminar; }
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int tipo;
	bool eliminar;
};
