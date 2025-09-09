#include "pch.h"
#include "Heroe.h"

// Utilitario para mover cursor en consola
void Heroe::gotoxy(int x, int y) {
    COORD c; c.X = x; c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Heroe::Heroe() {
    this->cabeza = "";
    this->cuerpo = "";
    this->pies = "";
    this->x = 0; y = 0;
    this->direccion = 0;
}

Heroe::Heroe(string cabeza, string cuerpo, string pies, int x, int y) {
    this->cabeza = cabeza;
    this->cuerpo = cuerpo;
    this->pies = pies;
    this->x = x;
    this->y = y;
    this->direccion = 0; // por defecto mirando arriba
}

Heroe::~Heroe() {}


string Heroe::getCabeza() { return cabeza; }
void Heroe::setCabeza(string cabeza) { this->cabeza = cabeza; }

string Heroe::getCuerpo() { return cuerpo; }
void Heroe::setCuerpo(string cuerpo) { this->cuerpo = cuerpo; }

string Heroe::getPies() { return pies; }
void Heroe::setPies(string pies) { this->pies = pies; }

int Heroe::getX() { return x; }
void Heroe::setX(int x) { this->x = x; }

int Heroe::getY() { return y; }
void Heroe::setY(int y) { this->y = y; }

int Heroe::getDireccion() { return direccion; }
void Heroe::setDireccion(int direccion) { this->direccion = direccion; }


void Heroe::dibujar() {
    gotoxy(x, y);     cout << cabeza;
    gotoxy(x, y + 1); cout << cuerpo;
    gotoxy(x, y + 2); cout << pies;
}

void Heroe::borrar() {
    gotoxy(x, y);     cout << "     ";
    gotoxy(x, y + 1); cout << "     ";
    gotoxy(x, y + 2); cout << "     ";
}

void Heroe::mover(char tecla) {
    borrar();
    if (tecla == 'w') { y--; direccion = 0; }
    if (tecla == 's') { y++; direccion = 1; }
    if (tecla == 'a') { x--; direccion = 2; }
    if (tecla == 'd') { x++; direccion = 3; }
    dibujar();
}
