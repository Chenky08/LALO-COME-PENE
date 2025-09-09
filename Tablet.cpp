#include "pch.h"
#include "Tablet.h"

Tablet::Tablet() {
    this->modelo = "";
    this->estado = "Disponible";
}

Tablet::Tablet(string modelo) {
    this->modelo = modelo;
    this->estado = "Disponible";
}

Tablet::~Tablet() {
}

string Tablet::getModelo() { return modelo; }
void Tablet::setModelo(string modelo) { this->modelo = modelo; }

string Tablet::getEstado() { return estado; }
void Tablet::setEstado(string estado) { this->estado = estado; }
