#pragma once
#include <string>
#include "Heroe.h"
#include "Vitamina.h"
#include "Obstaculo.h"
#include "ArregloDinamico.h"  

using namespace std;

class Juego {
private:
    Heroe* heroe;

    
    ArregloDinamico<Vitamina> vitaminas;
    ArregloDinamico<Obstaculo> obstaculos;

    int puntaje;
    int meta;

public:
    Juego();
    ~Juego();

    void iniciarHeroe(string cabeza, string cuerpo, string pies, int x, int y);

    // Vitaminas
    void lanzarVitamina();
    void moverVitaminas();

    // Obstáculos
    void generarObstaculo(int x, int y);
    void moverObstaculos();

    // Colisiones y estado
    void detectarColisiones();
    void mostrarEstado();
    bool juegoTerminado();

    // Acceso al héroe
    Heroe* getHeroe();
};
