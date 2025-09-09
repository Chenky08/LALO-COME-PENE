#pragma once
#include <string>
using namespace std;

class Estudiante;
class Tablet;

class Prestamo {
private:
    string fechaInicio;
    string fechaFin;
    string estado;
    Estudiante* estudiante;
    Tablet* tablet;

public:
    Prestamo();
    Prestamo(Estudiante* estudiante, Tablet* tablet, string fechaInicio, string fechaFin);

    ~Prestamo();

    string getFechaInicio();
    void setFechaInicio(string fechaInicio);

    string getFechaFin();
    void setFechaFin(string fechaFin);

    string getEstado();
    void setEstado(string estado);

    Estudiante* getEstudiante();
    void setEstudiante(Estudiante* estudiante);

    Tablet* getTablet();
    void setTablet(Tablet* tablet);
};
