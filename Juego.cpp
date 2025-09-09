#include "pch.h"
#include "Juego.h"
#include <iostream>
#include <Windows.h>   // para COORD / SetConsoleCursorPosition
using namespace std;

static void gotoxy(int x, int y) {
    COORD c;
    c.X = static_cast<SHORT>(x);
    c.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Juego::Juego() {
    heroe = nullptr;
    puntaje = 0;
    meta = 4;
}

Juego::~Juego() {
    if (heroe) delete heroe;
}

void Juego::iniciarHeroe(string cabeza, string cuerpo, string pies, int x, int y) {
    if (heroe) delete heroe;
    heroe = new Heroe(cabeza, cuerpo, pies, x, y);
    heroe->setDireccion(0);
}

// --- Vitaminas ---
/*
// Versión original basada en GestorArreglo (comentada)
void Juego::lanzarVitamina() {
    if (!heroe) return;
    Vitamina v(heroe->getX(), heroe->getY(), heroe->getDireccion(), "activa", '*', heroe);
    agregar(vitaminas, nVit, tamVit, v);
}
*/

void Juego::lanzarVitamina() {
    if (!heroe) return;

    int dir = heroe->getDireccion();
    int x = heroe->getX();
    int y = heroe->getY();

    // posicionar el disparo según dirección del héroe
    if (dir == 0)      y -= 1;  // arriba (sobre la cabeza)
    else if (dir == 1) y += 3;  // abajo (debajo de los pies)
    else if (dir == 2) x -= 1;  // izquierda
    else if (dir == 3) x += 3;  // derecha

    Vitamina v(x, y, dir, "activa", '*', heroe);
    vitaminas.agregar(v);  // ahora usamos ArregloDinamico<Vitamina>
}

/*
void Juego::moverVitaminas() {
    for (int i = 0; i < nVit; ) {
        if (vitaminas[i].getEstado() == "activa") {
            vitaminas[i].mover();
            if (vitaminas[i].getX() < 0 || vitaminas[i].getY() < 0 ||
                vitaminas[i].getX() > 80 || vitaminas[i].getY() > 25) {
                vitaminas[i].borrar();
                eliminar(vitaminas, nVit, i);
                continue;
            }
        }
        i++;
    }
}
*/

void Juego::moverVitaminas() {
    const int ancho = 80;
    const int alto = 25;

    int i = 0;
    while (i < vitaminas.size()) {
        if (vitaminas[i].getEstado() == "activa") {
            // borrar en posición actual, mover y validar límites
            vitaminas[i].borrar();
            vitaminas[i].mover();

            if (vitaminas[i].getX() < 0 || vitaminas[i].getY() < 0 ||
                vitaminas[i].getX() >= ancho || vitaminas[i].getY() >= alto) {

                // fuera de área: eliminar sin avanzar índice (el siguiente cae en i)
                vitaminas.eliminar(i);
                continue;
            }

            // redibujar si sigue activa y dentro de área
            vitaminas[i].dibujar();
        }
        ++i;
    }
}

// --- Obstáculos ---
void Juego::generarObstaculo(int x, int y) {
    Obstaculo o(x, y, "activo", '#');
    obstaculos.agregar(o); // ahora usamos ArregloDinamico<Obstaculo>
}

void Juego::moverObstaculos() {
    int i = 0;
    while (i < obstaculos.size()) {
        if (obstaculos[i].getEstado() == "activo") {
            obstaculos[i].mover();
            if (obstaculos[i].getY() > 25) {
                obstaculos[i].borrar();
                obstaculos.eliminar(i); // no incrementamos i
                continue;
            }
        }
        ++i;
    }
}

// --- Colisiones ---
void Juego::detectarColisiones() {
    int i = 0;
    while (i < vitaminas.size()) {
        bool elimVitamina = false;

        int j = 0;
        while (j < obstaculos.size()) {
            if (vitaminas[i].getEstado() == "activa" &&
                obstaculos[j].getEstado() == "activo" &&
                vitaminas[i].getX() == obstaculos[j].getX() &&
                vitaminas[i].getY() == obstaculos[j].getY()) {

                // borrar en pantalla
                vitaminas[i].borrar();
                obstaculos[j].borrar();

                // eliminar de las arreglos
                obstaculos.eliminar(j);   // el siguiente obstáculo pasa a ocupar j
                vitaminas.eliminar(i);    // la siguiente vitamina pasa a ocupar i
                ++puntaje;

                elimVitamina = true;
                break; // salimos del while j, seguimos controlando i
            }
            else {
                ++j;
            }
        }

        if (!elimVitamina) {
            ++i; // sólo avanzamos i si no se eliminó la vitamina actual
        }
    }
}

// --- Estado ---
void Juego::mostrarEstado() {
    gotoxy(0, 0); // esquina superior izquierda
    cout << "Puntaje: " << puntaje << "/" << meta << "   " << endl; // espacios para limpiar
}

bool Juego::juegoTerminado() {
    return puntaje >= meta;
}

Heroe* Juego::getHeroe() {
    return heroe;
}
