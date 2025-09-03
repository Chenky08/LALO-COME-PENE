#pragma once
using namespace System::Drawing;
#include<vector>
using namespace std;
class Objeto
{
public:
	Objeto(){}
	~Objeto(){}
	int getX() { return x; }
	int getY() { return y; }
protected:
	int x, y;
	int ancho, alto;
	int fil, col;
	int dx, dy;
};
