#include <iostream>
#include <vector>
#include <chrono>

// Plantilla de función para realizar una búsqueda binaria recursiva en un vector ordenado.
// Recibe el valor a buscar (x), el vector constante (v), y los límites del subarreglo (ini, fin).
template<typename T>
int busquedaBinaria(T x, const std::vector<T>& v, int ini, int fin) {
    // Caso base negativo: si el índice inicial supera al final, el rango es inválido y el elemento no existe.
    if (ini > fin) {
        return -1; 
    }
    
    // Cálculo del índice central. Se utiliza `ini + (fin - ini) / 2` en lugar de `(ini + fin) / 2` 
    // para evitar el desbordamiento (overflow) de enteros con índices muy grandes.
    int medio = ini + (fin - ini) / 2; 
    
    // Caso base positivo: el elemento central coincide con el valor buscado.
    if (v[medio] == x) {
        return medio;
    } 
    // Si el valor central es mayor que el buscado, se descarta la mitad derecha y se busca en la izquierda.
    else if (v[medio] > x) {
        return busquedaBinaria(x, v, ini, medio - 1);
    } 
    // Si el valor central es menor que el buscado, se descarta la mitad izquierda y se busca en la derecha.
    else {
        return busquedaBinaria(x, v, medio + 1, fin);
    }
}

int main() {
    // Definición del vector de datos. Es un requisito estricto que esté ordenado para la búsqueda binaria.
    std::vector<int> datos = {1, 3, 5, 7, 9, 11, 15};
    int valor_a_buscar = 7;

    // Se captura la marca de tiempo de alta resolución justo antes de iniciar el algoritmo.
    auto inicio_tiempo = std::chrono::high_resolution_clock::now();
    
    // Se ejecuta la búsqueda abarcando todo el vector (índice inicial 0, índice final size - 1).
    int posicion = busquedaBinaria(valor_a_buscar, datos, 0, datos.size() - 1);
    
    // Se captura la marca de tiempo justo al terminar la ejecución.
    auto fin_tiempo = std::chrono::high_resolution_clock::now();
    
    // Se calcula la diferencia entre ambas marcas de tiempo, expresando el resultado en milisegundos.
    std::chrono::duration<double, std::milli> duracion = fin_tiempo - inicio_tiempo;

    // Evaluación del resultado: un valor distinto de -1 indica éxito.
    if (posicion != -1) {
        std::cout << "Elemento encontrado en la posición: " << posicion << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }
    
    // Impresión del coste temporal de la búsqueda en consola.
    std::cout << "Tiempo de ejecución: " << duracion.count() << " ms\n";

    return 0;
}