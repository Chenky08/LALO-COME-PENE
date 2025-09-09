#include "pch.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Juego.h"

using namespace std;




int main() {
    srand(time(NULL));
    
    // Inicializar juego y héroe
    Juego* juego = new Juego();
    juego->iniciarHeroe(" 0 ", "/|\\", "_|_", 10, 5);

    Heroe* heroe = juego->getHeroe();
    heroe->dibujar();

    int contadorObs = 0;

    // Bucle principal
    while (!juego->juegoTerminado()) {
        if (_kbhit()) {
            char tecla = _getch();

            if (tecla == 27) break;        // tecla ESC = salir
            else if (tecla == ' ') {
                juego->lanzarVitamina();   // espacio = dispara vitamina
            }
            else {
                heroe->borrar();
                heroe->mover(tecla);       // WASD = mueve héroe
                heroe->dibujar();
            }
        }

       // Cada cierto tiempo genera un obstáculo en posición aleatoria
        contadorObs++;
        if (contadorObs % 20 == 0) {
            int x = rand() % 80;
            juego->generarObstaculo(x, 0); // aparece arriba
        }

        // Actualizar dinámicas
        juego->moverVitaminas();
        juego->moverObstaculos();
        juego->detectarColisiones();
        juego->mostrarEstado();
        _sleep(100); // retraso para controlar velocidad
    }

    delete juego;
    system("pause>0");
    return 0;
}
