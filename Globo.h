#pragma once
using namespace System::Drawing;
#include<iostream>
using namespace System;
class Globo
{
public:
	Globo(){
		x = rand() % 400 + 100;
		y = 500;
		color = rand() % 5;
		operador = rand() % 3;
		switch (operador)
		{
		case 0: // Multiplicacion
			num1 = rand() % 7 + 3;
			num2 = rand() % 20 + 10;
			resultado = num1 * num2;
			break;

		case 1: // Suma
			num1 = rand() % 20 + 10;
			num2 = rand() % 20 + 10;
			resultado = num1 + num2;
			break;
		case 2:
			num1 = rand() % 20 + 10;
			num2 = rand() % 20 + 10;
			resultado = num1 - num2;
			break;
		}
	}
	~Globo(){}
	void dibujar(Graphics^g) {
		switch (color)
		{
		case 0: 	g->FillEllipse(Brushes::LightCoral, x, y, 100, 100); break;
		case 1: 	g->FillEllipse(Brushes::LightCyan, x, y, 100, 100); break;
		case 2: 	g->FillEllipse(Brushes::LightGreen, x, y, 100, 100); break;
		case 3: 	g->FillEllipse(Brushes::LightPink, x, y, 100, 100); break;
		case 4: 	g->FillEllipse(Brushes::LightSalmon, x, y, 100, 100); break;
		}
		Font^ fuente = gcnew Font("Arial", 12);
		char simbolo = operador == 0 ? 'x' : (operador == 1 ? '+' : '-');
		g->DrawString(num1 + " " + gcnew String(simbolo, 1) + " " + num2, fuente, Brushes::Black, x + 20, y + 40);
	}
	void mover() {
		y -= 5;
	}
	int getY() {
		return y;
	}
	int getResultado() {
		return resultado;
	}
private:
	int x, y;
	int num1, num2;
	int operador;
	int color;
	int resultado;
};
