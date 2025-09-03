#pragma once
#include <string>
#include "fecha.h"

class Autor
{
public:
	Autor(string nombre,string apellido,string pais,Fecha* fecha) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->pais = pais;
		this->fecha = fecha;
	}
	~Autor() {

	}

	//setters

	void SetNombre(string nombre) {
		this->nombre = nombre;
	}
	void SetApellido(string apellido) {
		this->apellido = apellido;
	}
	void SetPais(string pais) {
		this->pais = pais;
	}
	

	//getters

	string getNombre(){
		return nombre;
	}

	string getApellido() {
		return apellido;
	}

	string getPais() {
		return pais;
	}

	Fecha* getFecha() {
		return fecha;
	}

private:
	string nombre, apellido, pais;
	Fecha* fecha;
};


