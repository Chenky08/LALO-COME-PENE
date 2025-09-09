#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

class Heroe {
private:
    string cabeza;
    string cuerpo;
    string pies;
    int x;
    int y;
    int direccion;  // 0=arriba, 1=abajo, 2=izquierda, 3=derecha

    void gotoxy(int x, int y);

public:
    Heroe();
    Heroe(string cabeza, string cuerpo, string pies, int x, int y);
    ~Heroe();


    string getCabeza();  void setCabeza(string cabeza);
    string getCuerpo();  void setCuerpo(string cuerpo);
    string getPies();    void setPies(string pies);
    int getX();          void setX(int x);
    int getY();          void setY(int y);
    int getDireccion();  void setDireccion(int direccion);

    void dibujar();
    void borrar();
    void mover(char tecla);
};
