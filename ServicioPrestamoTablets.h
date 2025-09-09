#pragma once
#include <string>
#include <iostream>

#include "Estudiante.h"
#include "Tablet.h"
#include "Prestamo.h"
#include "ArregloDinamico.h"  

class ServicioPrestamoTablets {
private:
    ArregloDinamico<Estudiante> estudiantes;
    ArregloDinamico<Tablet>     tablets;
    ArregloDinamico<Prestamo>   prestamos;

    int posicionEstudiantePorCodigo(int codigo);
    int posicionTabletPorModelo(string modelo);

public:
    ServicioPrestamoTablets() = default;
    ~ServicioPrestamoTablets() = default;

    // 1) Registrar estudiantes
    void registrarEstudiante(Estudiante* e);

    // 2) Registrar tablets
    void registrarTablet(Tablet* t);

    // 3) Registrar préstamos
    void registrarPrestamo(Prestamo* p);

    // 4) Listar préstamos por estudiante
    void listarPrestamosPorEstudiante(int codigoEstudiante);

    // 4) Devolver UNA tablet por estudiante y modelo
    void registrarDevolucionDeTablet(int codigoEstudiante, string modeloTablet);
};
