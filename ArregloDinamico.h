#pragma once
#include <iostream>
using namespace std;  

template <typename T>
class ArregloDinamico {
    T* arreglo = nullptr;
    int n = 0;
    int tam = 0;

    void redimensionar(int nuevoTam) {
        T* nuevoArr = new T[nuevoTam];
        for (int i = 0; i < n; ++i) nuevoArr[i] = arreglo[i];
        delete[] arreglo;
        arreglo = nuevoArr;
        tam = nuevoTam;
    }

public:
    ArregloDinamico() = default;
    ~ArregloDinamico() { delete[] arreglo; }

    void agregar(const T& elemento) {
        if (n >= tam) redimensionar(tam < 2 ? 2 : tam * 2);
        arreglo[n++] = elemento;
    }

    void listar() const {
        for (int i = 0; i < n; ++i) cout << i << ". " << arreglo[i] << "\n";
    }

    T* buscar(int pos) { return (pos >= 0 && pos < n) ? &arreglo[pos] : nullptr; }

    int buscarPorId(int id) {
        for (int i = 0; i < n; ++i) if (arreglo[i].getId() == id) return i;
        return -1;
    }

    template <typename K>
    int buscarPorClave(K clave, K(*obtener)(T*)) {
        for (int i = 0; i < n; ++i) if (obtener(&arreglo[i]) == clave) return i;
        return -1;
    }

    int buscarPorPredicado(bool (*pred)(T*)) {
        for (int i = 0; i < n; ++i) if (pred(&arreglo[i])) return i;
        return -1;
    }

    void eliminar(int pos) {
        if (pos < 0 || pos >= n) return;
        for (int i = pos; i < n - 1; ++i) arreglo[i] = arreglo[i + 1];
        --n;
    }

    void actualizar(int pos, const T& v) { if (pos >= 0 && pos < n) arreglo[pos] = v; }

    int size() const { return n; }

    T& operator[](int idx) { return arreglo[idx]; }
    const T& operator[](int idx) const { return arreglo[idx]; }
};
