#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

#include "ServicioPrestamoTablets.h"
#include "Estudiante.h"
#include "Tablet.h"
#include "Prestamo.h"

int main() {
   
    ServicioPrestamoTablets* servicio = new ServicioPrestamoTablets();

    // --- Estudiantes---
    Estudiante* e1 = new Estudiante(20251001, "Henry Antonio Mendoza Puerta");
    Estudiante* e2 = new Estudiante(20251002, "Pablo Paredes");
    servicio->registrarEstudiante(e1);
    servicio->registrarEstudiante(e2);

    // --- Tablets  ---
    Tablet* t1 = new Tablet("iPad-10gen");
    Tablet* t2 = new Tablet("GalaxyTab-A8");
    Tablet* t3 = new Tablet("SurfaceGo-3");
    servicio->registrarTablet(t1);
    servicio->registrarTablet(t2);
    servicio->registrarTablet(t3);

    // --- Prestamos ---    
    Prestamo* p1 = new Prestamo(e1, t1, "2025-09-07", "2025-09-14");
    servicio->registrarPrestamo(p1);
    

    Prestamo* p2 = new Prestamo(e2, t2, "2025-09-08", "2025-09-15");
    servicio->registrarPrestamo(p2);
   

    Prestamo* p3 = new Prestamo(e1, t3, "2025-09-10", "2025-09-17");
    servicio->registrarPrestamo(p3);
    

    cout << endl << "-- Prestamos de 20251001 --" << endl;
    servicio->listarPrestamosPorEstudiante(20251001);

    cout << endl << "-- Devolviendo SOLO SurfaceGo-3 de 20251001 --" << endl;
    servicio->registrarDevolucionDeTablet(20251001, "SurfaceGo-3");

    cout << endl << "-- Prestamos de 20251001 (luego de devolver) --" << endl;
    servicio->listarPrestamosPorEstudiante(20251001);

    
    delete e1;
    delete e2;
    delete t1;
    delete t2;
    delete t3;
    delete p1;
    delete p2;
    delete p3;

    delete servicio;
    return 0;
}


//#include "pch.h"
//#include <iostream>
//#include <string>
//
//#include "ServicioPrestamoTablets.h"
//#include "Estudiante.h"
//#include "Tablet.h"
//#include "Prestamo.h"
//
//using namespace std;
//
//int main() {
//    // Servicio en heap
//    ServicioPrestamoTablets* servicio = new ServicioPrestamoTablets();
//    int opcion = -1;
//
//    do {
//        cout << endl << "--- MENU ---" << endl;
//        cout << "1. Registrar estudiante" << endl;
//        cout << "2. Registrar tablet" << endl;
//        cout << "3. Registrar prestamo" << endl;
//        cout << "4. Listar prestamos por estudiante" << endl;
//        cout << "5. Registrar devolucion (por codigo estudiante y modelo)" << endl;
//        cout << "0. Salir" << endl;
//        cout << "Opcion: ";
//        cin >> opcion;
//
//        switch (opcion) {
//        case 1: {
//            int codigo;
//            string nombre;
//
//            cout << "Codigo estudiante: ";
//            cin >> codigo;
//
//            cout << "Nombre: ";
//            getline(cin >> ws, nombre); // limpia el salto de linea previo
//
//            Estudiante* e = new Estudiante(codigo, nombre);
//            servicio->registrarEstudiante(e);
//            delete e; // el servicio guarda su propia copia
//            break;
//        }
//        case 2: {
//            string modelo;
//
//            cout << "Modelo tablet: ";
//            getline(cin >> ws, modelo);
//
//            Tablet* t = new Tablet(modelo);
//            servicio->registrarTablet(t);
//            delete t; // el servicio guarda su propia copia
//            break;
//        }
//        case 3: {
//            int codigo;
//            string modelo, fi, ff;
//
//            cout << "Codigo estudiante: ";
//            cin >> codigo;
//
//            cout << "Modelo tablet: ";
//            getline(cin >> ws, modelo);
//
//            cout << "Fecha inicio (AAAA-MM-DD): ";
//            getline(cin, fi);
//
//            cout << "Fecha fin (AAAA-MM-DD): ";
//            getline(cin, ff);
//
//            // Objetos temporales para invocar la lógica
//            Estudiante* eTemp = new Estudiante(codigo, "");
//            Tablet* tTemp = new Tablet(modelo);
//            Prestamo* p = new Prestamo(eTemp, tTemp, fi, ff);
//
//            servicio->registrarPrestamo(p);
//
//            delete p;
//            delete eTemp;
//            delete tTemp;
//            break;
//        }
//        case 4: {
//            int codigo;
//            cout << "Codigo estudiante: ";
//            cin >> codigo;
//            servicio->listarPrestamosPorEstudiante(codigo);
//            break;
//        }
//        case 5: {
//            int codigo;
//            string modelo;
//
//            cout << "Codigo estudiante: ";
//            cin >> codigo;
//
//            cout << "Modelo tablet: ";
//            getline(cin >> ws, modelo);
//
//            servicio->registrarDevolucionDeTablet(codigo, modelo);
//            break;
//        }
//        case 0:
//            cout << "Saliendo..." << endl;
//            break;
//        default:
//            cout << "Opcion invalida" << endl;
//            break;
//        }
//    } while (opcion != 0);
//
//    delete servicio;
//    return 0;
//}
