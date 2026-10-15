#include <iostream>
#include <vector>
#include <chrono>

template<typename T>
int busquedaBinaria(T x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; 
    }
    
    int medio = ini + (fin - ini) / 2; 
    
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] > x) {
        return busquedaBinaria(x, v, ini, medio - 1);
    } else {
        return busquedaBinaria(x, v, medio + 1, fin);
    }
}

int main() {
    std::vector<int> datos = {1, 3, 5, 7, 9, 11, 15};
    int valor_a_buscar = 7;

    auto inicio_tiempo = std::chrono::high_resolution_clock::now();
    
    int posicion = busquedaBinaria(valor_a_buscar, datos, 0, datos.size() - 1);
    
    auto fin_tiempo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = fin_tiempo - inicio_tiempo;

    if (posicion != -1) {
        std::cout << "Elemento encontrado en la posición: " << posicion << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }
    std::cout << "Tiempo de ejecución: " << duracion.count() << " ms\n";

    return 0;
}