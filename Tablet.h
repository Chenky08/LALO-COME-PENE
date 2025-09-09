#pragma once
#include <string>
using namespace std;

class Tablet {
private:
    string modelo;
    string estado; 

public:
    Tablet();
    Tablet(string modelo);

    ~Tablet();

    string getModelo();
    void setModelo(string modelo);

    string getEstado();
    void setEstado(string estado);
};
