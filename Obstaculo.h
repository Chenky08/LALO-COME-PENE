#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

class Obstaculo {
private:
    int x;
    int y;
    string estado;   // "activo" o "inactivo"
    char avatar;

    void gotoxy(int x, int y);

public:
    Obstaculo();
    Obstaculo(int x, int y, string estado, char avatar);
    ~Obstaculo();

    int getX(); void setX(int x);
    int getY(); void setY(int y);
    string getEstado(); void setEstado(string estado);
    char getAvatar(); void setAvatar(char avatar);

    // lógica
    void dibujar();
    void borrar();
    void mover();
};
