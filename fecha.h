#pragma once

class Fecha
{
public:
	Fecha(int dia, int mes, int anio) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	~Fecha() {}

	int getDia() {
		return dia;
	}

	int getMes() {
		return mes;
	}

	int getAnio() {
		return anio;
	}

private:
	int dia, mes, anio;
};

