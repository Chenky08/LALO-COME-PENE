#include "pch.h"
#include "Vitamina.h"

void Vitamina::gotoxy(int x, int y) {
    COORD c; c.X = x; c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Vitamina::Vitamina() {
    this->x = 0;
    this->y = 0;
    this->direccion = 0;
    this->estado = "inactiva";
    this->avatar = '*';
    this->heroe = nullptr;
}

Vitamina::Vitamina(int x, int y, int direccion, string estado, char avatar, Heroe* heroe) {
    this->x = x;
    this->y = y;
    this->direccion = direccion;
    this->estado = estado;
    this->avatar = avatar;
    this->heroe = heroe;
}

Vitamina::~Vitamina() {}

int Vitamina::getX() { return x; }
void Vitamina::setX(int x) { this->x = x; }

int Vitamina::getY() { return y; }
void Vitamina::setY(int y) { this->y = y; }

int Vitamina::getDireccion() { return direccion; }
void Vitamina::setDireccion(int direccion) { this->direccion = direccion; }

string Vitamina::getEstado() { return estado; }
void Vitamina::setEstado(string estado) { this->estado = estado; }

char Vitamina::getAvatar() { return avatar; }
void Vitamina::setAvatar(char avatar) { this->avatar = avatar; }

Heroe* Vitamina::getHeroe() { return heroe; }
void Vitamina::setHeroe(Heroe* heroe) { this->heroe = heroe; }

void Vitamina::dibujar() {
    if (estado == "activa") {
        gotoxy(x, y);
        cout << avatar;
    }
}

void Vitamina::borrar() {
    gotoxy(x, y);
    cout << " ";
}

void Vitamina::mover() {
    if (estado == "activa") {
        borrar();

        if (direccion == 0) y--;
        else if (direccion == 1) y++;
        else if (direccion == 2) x--;
        else if (direccion == 3) x++;

        dibujar();
    }
}
