
#include "pch.h"
#include "Prestamo.h"
#include "Estudiante.h"
#include "Tablet.h"

Prestamo::Prestamo() {
    this->fechaInicio = "";
    this->fechaFin = "";
    this->estado = "EnUso";
    this->estudiante = 0;
    this->tablet = 0;
}

Prestamo::Prestamo(Estudiante* estudiante, Tablet* tablet, string fechaInicio, string fechaFin) {
    this->estudiante = estudiante;
    this->tablet = tablet;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->estado = "EnUso";
}

Prestamo::~Prestamo() {
}

string Prestamo::getFechaInicio() { return fechaInicio; }
void Prestamo::setFechaInicio(string fechaInicio) { this->fechaInicio = fechaInicio; }

string Prestamo::getFechaFin() { return fechaFin; }
void Prestamo::setFechaFin(string fechaFin) { this->fechaFin = fechaFin; }

string Prestamo::getEstado() { return estado; }
void Prestamo::setEstado(string estado) { this->estado = estado; }

Estudiante* Prestamo::getEstudiante() { return estudiante; }
void Prestamo::setEstudiante(Estudiante* estudiante) { this->estudiante = estudiante; }

Tablet* Prestamo::getTablet() { return tablet; }
void Prestamo::setTablet(Tablet* tablet) { this->tablet = tablet; }
