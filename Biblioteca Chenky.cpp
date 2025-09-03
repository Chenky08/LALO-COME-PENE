
#include <iostream>
using namespace std;
#include "autor.h"
#include "libro.h"

int main() {
	Fecha* fecha1 = new Fecha(7, 11, 2005);
	Autor* autor1 = new Autor("Matheo","Astudillo","Peru",fecha1);
	Libro* libro1 = new Libro("Los Heraldos Negros", "Lumbreras", "Primera", 340, autor1);
	Libro* libro2 = new Libro("Trilce", "Lumbreras", "Primera", 340, autor1);


	cout << libro1->getAutor()->getNombre() << " " << libro1->getAutor()->getApellido() << endl;
	cout << libro2->getAutor()->getFecha()->getAnio() << endl;


}

