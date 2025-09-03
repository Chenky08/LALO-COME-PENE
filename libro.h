#pragma once
#include "autor.h"

class Libro
{
public:
	Libro(string titulo,string editorial,string edicion,int paginas,Autor*autor) {
		this->titulo = titulo;
		this->editorial = editorial;
		this->edicion = edicion;
		this->autor = autor;
	}
	~Libro() {

	}

	//setters
	void setTitulo(string titulo) {
		this->titulo = titulo;
	}


	void setEditorial(string editorial) {
		this->editorial = editorial;
	}

	void setEdicion(string edicion) {
		this->edicion = edicion;
	}

	void setPaginas(int paginas) {
		this->paginas = paginas;
	}

	void setAutor(Autor* autor) {
		this->autor = autor;
	}

	//getters

	string getTitulo() {
		return titulo;
	}

	string getEditorial() {
		return editorial;
	}

	string getEdicion() {
		return edicion;
	}

	int getPaginas() {
		return paginas;
	}

	Autor* getAutor() {
		return autor;
	}

private:
	string editorial;
	string titulo;
	string edicion;
	int paginas;

	Autor* autor;
};


