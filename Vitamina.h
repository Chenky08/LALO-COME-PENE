#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "Heroe.h"
using namespace std;

class Vitamina {
private:
    int x;
    int y;
    int direccion;   // 0=arriba, 1=abajo, 2=izquierda, 3=derecha
    string estado;   // "activa" o "inactiva"
    char avatar;
    Heroe* heroe;    // referencia al héroe que la lanzó

    void gotoxy(int x, int y);

public:
    Vitamina();
    Vitamina(int x, int y, int direccion, string estado, char avatar, Heroe* heroe);
    ~Vitamina();

    int getX(); void setX(int x);
    int getY(); void setY(int y);
    int getDireccion(); void setDireccion(int direccion);
    string getEstado(); void setEstado(string estado);
    char getAvatar(); void setAvatar(char avatar);
    Heroe* getHeroe(); void setHeroe(Heroe* heroe);

    
    void dibujar();
    void borrar();
    void mover();
};
