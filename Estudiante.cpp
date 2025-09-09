#include "pch.h"
#include "Estudiante.h"


Estudiante::Estudiante() {
    this->codigoEstudiante = 0;
    this->nombre = "";
}

Estudiante::Estudiante(int codigoEstudiante, string nombre) {
    this->codigoEstudiante = codigoEstudiante;
    this->nombre = nombre;
}


Estudiante::~Estudiante() {
   
}

int Estudiante::getCodigoEstudiante() {
    return codigoEstudiante;
}

void Estudiante::setCodigoEstudiante(int codigoEstudiante) {
    this->codigoEstudiante = codigoEstudiante;
}

string Estudiante::getNombre() {
    return nombre;
}

void Estudiante::setNombre(string nombre) {
    this->nombre = nombre;
}

