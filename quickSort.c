#include <iostream>
#include <vector>
#include <chrono>

template<typename T>
int particion(std::vector<T>& v, int ini, int fin) {
    T x = v[fin];
    int i = ini;
    
    for (int j = ini; j < fin; ++j) {
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            i = i + 1;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

template<typename T>
void quickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = particion(v, ini, fin);
        quickSort(v, ini, pivote - 1);
        quickSort(v, pivote + 1, fin);
    }
}

int main() {
    std::vector<int> datos = {9, -4, 3, 6, 1, 5};

    auto inicio_tiempo = std::chrono::high_resolution_clock::now();
    
    quickSort(datos, 0, datos.size() - 1);
    
    auto fin_tiempo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin_tiempo - inicio_tiempo;

    std::cout << "Vector ordenado: ";
    for(const auto& elemento : datos) {
        std::cout << elemento << " ";
    }
    std::cout << "\nTiempo de ejecución: " << duracion.count() << " ms\n";

    return 0;
}