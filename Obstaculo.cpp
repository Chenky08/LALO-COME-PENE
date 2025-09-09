#include "pch.h"
#include "Obstaculo.h"

void Obstaculo::gotoxy(int x, int y) {
    COORD c; c.X = x; c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Obstaculo::Obstaculo() {
    this->x = 0;
    this->y = 0;
    this->estado = "activo";
    this->avatar = '#';
}

Obstaculo::Obstaculo(int x, int y, string estado, char avatar) {
    this->x = x;
    this->y = y;
    this->estado = estado;
    this->avatar = avatar;
}

Obstaculo::~Obstaculo() {}

int Obstaculo::getX() { return x; }
void Obstaculo::setX(int x) { this->x = x; }

int Obstaculo::getY() { return y; }
void Obstaculo::setY(int y) { this->y = y; }

string Obstaculo::getEstado() { return estado; }
void Obstaculo::setEstado(string estado) { this->estado = estado; }

char Obstaculo::getAvatar() { return avatar; }
void Obstaculo::setAvatar(char avatar) { this->avatar = avatar; }

void Obstaculo::dibujar() {
    if (estado == "activo") {
        gotoxy(x, y);
        cout << avatar;
    }
}

void Obstaculo::borrar() {
    gotoxy(x, y);
    cout << " ";
}

void Obstaculo::mover() {
    if (estado == "activo") {
        borrar();
        y++;
        dibujar();
    }
}
