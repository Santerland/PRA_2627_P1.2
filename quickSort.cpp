#include <iostream>
#include <vector>
#include <chrono>

// Función auxiliar que reorganiza un subarreglo en torno a un elemento "pivote".
// Todos los elementos menores o iguales al pivote quedan a su izquierda, y los mayores a su derecha.
template<typename T>
int particion(std::vector<T>& v, int ini, int fin) {
    // Se selecciona el último elemento del subarreglo como pivote.
    T x = v[fin];
    
    // 'i' actúa como el índice donde se colocará el próximo elemento menor o igual al pivote.
    int i = ini;
    
    // Se recorren los elementos desde 'ini' hasta 'fin - 1'.
    for (int j = ini; j < fin; ++j) {
        // Si el elemento actual es menor o igual al pivote, se intercambia para moverlo a la parte izquierda.
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            i = i + 1; // Se avanza el límite de la sección de menores/iguales.
        }
    }
    // Finalmente, se coloca el pivote en su posición definitiva e intercambiándolo con el primer elemento mayor encontrado.
    std::swap(v[i], v[fin]);
    
    // Se retorna la posición definitiva del pivote.
    return i;
}

// Función principal recursiva del algoritmo de ordenación QuickSort.
template<typename T>
void quickSort(std::vector<T>& v, int ini, int fin) {
    // Condición de continuación: si hay al menos dos elementos en el rango a ordenar.
    if (ini < fin) {
        // Se particiona el subarreglo y se obtiene el índice exacto del pivote ya ordenado.
        int pivote = particion(v, ini, fin);
        
        // Llamada recursiva para ordenar la sublista izquierda (elementos menores al pivote).
        quickSort(v, ini, pivote - 1);
        
        // Llamada recursiva para ordenar la sublista derecha (elementos mayores al pivote).
        quickSort(v, pivote + 1, fin);
    }
}

int main() {
    // Definición de un vector de enteros desordenado.
    std::vector<int> datos = {9, -4, 3, 6, 1, 5};

    // Captura de la marca de tiempo de alta resolución al iniciar la ordenación.
    auto inicio_tiempo = std::chrono::high_resolution_clock::now();
    
    // Llamada a la función QuickSort abarcando todo el tamaño del vector.
    quickSort(datos, 0, datos.size() - 1);
    
    // Captura de la marca de tiempo al finalizar la ejecución del algoritmo.
    auto fin_tiempo = std::chrono::high_resolution_clock::now();
    
    // Cálculo de la duración de la operación en milisegundos.
    std::chrono::duration<double, std::milli> duracion = fin_tiempo - inicio_tiempo;

    // Impresión del vector ya ordenado iterando sobre sus elementos.
    std::cout << "Vector ordenado: ";
    for(const auto& elemento : datos) {
        std::cout << elemento << " ";
    }
    
    // Impresión del tiempo total que tomó la ejecución de QuickSort.
    std::cout << "\nTiempo de ejecución: " << duracion.count() << " ms\n";

    return 0;
}