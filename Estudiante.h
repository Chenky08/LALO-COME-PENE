#pragma once
#include <string>
using namespace std;

class Estudiante {
private:
    int codigoEstudiante;   
    string nombre;

public:
    
    Estudiante();
    Estudiante(int codigoEstudiante, string nombre);

   
    ~Estudiante();

 
    int getCodigoEstudiante();
    void setCodigoEstudiante(int codigoEstudiante);

    string getNombre();
    void setNombre(string nombre);
};
