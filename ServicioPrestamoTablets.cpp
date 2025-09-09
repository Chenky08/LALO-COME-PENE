#include "pch.h"
#include "ServicioPrestamoTablets.h"
#include <iostream>

using namespace std;

int ServicioPrestamoTablets::posicionEstudiantePorCodigo(int codigo) {
    int pos = -1;
    for (int i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i].getCodigoEstudiante() == codigo) {
            pos = i;
            break;  
        }
    }
    return pos;
}

int ServicioPrestamoTablets::posicionTabletPorModelo(string modelo) {
    int pos = -1;
    for (int i = 0; i < tablets.size(); i++) {
        if (tablets[i].getModelo() == modelo) {
            pos = i;
            break;
        }
    }
    return pos;
}

// 1) Registrar estudiantes
void ServicioPrestamoTablets::registrarEstudiante(Estudiante* e) {
    if (e == nullptr) return;

    // sin duplicados por c�digo
    if (posicionEstudiantePorCodigo(e->getCodigoEstudiante()) >= 0) return;

    estudiantes.agregar(*e);
    cout << "Estudiante registrado" << endl;
}

// 2) Registrar tablets
void ServicioPrestamoTablets::registrarTablet(Tablet* t) {
    if (t == nullptr) return;

    if (posicionTabletPorModelo(t->getModelo()) >= 0) return;

    tablets.agregar(*t);
    cout << "Tablet registrada" << endl;
}

// 3) Registrar pr�stamos
void ServicioPrestamoTablets::registrarPrestamo(Prestamo* p) {
    // regla 0: el puntero del pr�stamo debe existir
    if (p == nullptr) return;

    // regla 1: el pr�stamo debe traer referencias a estudiante y tablet
    Estudiante* e = p->getEstudiante();
    Tablet* tb = p->getTablet();

    if (e == nullptr || tb == nullptr) {
        cout << "Falta estudiante o tablet" << endl;
        return;
    }

    // regla 2: el estudiante debe estar registrado
    int posE = posicionEstudiantePorCodigo(e->getCodigoEstudiante());
    if (posE < 0) {
        cout << "Estudiante no existe" << endl;
        return;
    }

    // regla 3: la tablet debe estar registrada
    int posT = posicionTabletPorModelo(tb->getModelo());
    if (posT < 0) {
        cout << "Tablet no existe" << endl;
        return;
    }

    // regla 4: la tablet debe estar disponible
    if (tablets[posT].getEstado() != "Disponible") {
        cout << "Tablet no disponible" << endl;
        return;
    }

    // regla 5: no debe existir pr�stamo vigente para esa misma tablet
    for (int i = 0; i < prestamos.size(); i++) {
        Tablet* tpp = prestamos[i].getTablet();
        if (tpp != nullptr &&
            tpp->getModelo() == tablets[posT].getModelo() &&
            prestamos[i].getEstado() == "EnUso") {
            cout << "Ya existe pr�stamo vigente para esa tablet" << endl;
            return;
        }
    }

    // acci�n: crear un pr�stamo nuevo apuntando a las instancias reales
    Prestamo nuevo(&estudiantes[posE], &tablets[posT], p->getFechaInicio(), p->getFechaFin());

    // acci�n: guardar (copia)
    prestamos.agregar(nuevo);

    // acci�n: marcar la tablet como prestada
    tablets[posT].setEstado("Prestada");
    cout << "Pr�stamo registrado" << endl;
}

// 4) Listar pr�stamos por estudiante
// 4) Listar pr�stamos por estudiante
void ServicioPrestamoTablets::listarPrestamosPorEstudiante(int codigoEstudiante) {
    cout << "Pr�stamos del estudiante " << codigoEstudiante << ":" << endl;
    int c = 0;

    for (int i = 0; i < prestamos.size(); i++) {
        Estudiante* e = prestamos[i].getEstudiante();

        if (e != nullptr && e->getCodigoEstudiante() == codigoEstudiante) {
            Tablet* t = prestamos[i].getTablet();

            cout << "- tablet=" << t->getModelo()
                << " ini=" << prestamos[i].getFechaInicio()
                << " fin=" << prestamos[i].getFechaFin()
                << " estado=" << prestamos[i].getEstado()
                << endl;

            c++;
        }
    }

    if (c == 0) {
        cout << "(sin registros)" << endl;
    }
}


// 5) Registrar devoluci�n de tablet
void ServicioPrestamoTablets::registrarDevolucionDeTablet(int codigoEstudiante, string modeloTablet) {
    // regla 0: estudiante debe existir
    int posE = posicionEstudiantePorCodigo(codigoEstudiante);
    if (posE < 0) {
        cout << "Estudiante no existe" << endl;
        return;
    }

    // regla 1: tablet debe existir
    int posT = posicionTabletPorModelo(modeloTablet);
    if (posT < 0) {
        cout << "Tablet no existe" << endl;
        return;
    }

    // regla 2: buscar pr�stamo en uso para esa tablet y estudiante
    for (int i = 0; i < prestamos.size(); i++) {
        if (prestamos[i].getEstado() == "EnUso" &&
            prestamos[i].getEstudiante() != nullptr &&
            prestamos[i].getEstudiante()->getCodigoEstudiante() == codigoEstudiante &&
            prestamos[i].getTablet() != nullptr &&
            prestamos[i].getTablet()->getModelo() == modeloTablet) {

            // acci�n: devolver este pr�stamo
            prestamos[i].setEstado("Devuelto");
            tablets[posT].setEstado("Disponible");

            cout << "Devoluci�n registrada para tablet [" << modeloTablet << "]" << endl;
            return;
        }
    }

    cout << "No hay pr�stamo vigente de esa tablet para ese estudiante" << endl;
}
