#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// Función que calcula el cambio mínimo de monedas[cite: 2]
// Entradas:
// m: vector con los valores de cada moneda[cite: 39]
// d: valor entero con la cantidad a devolver[cite: 39]
// Salida:
// s: vector de enteros con las cantidades a devolver de cada moneda, pasado por referencia[cite: 39]
void cambio_monedas(const std::vector<int>& m, int d, std::vector<int>& s) {
    int n = m.size();
    if (n == 0) return;
    
    // Representación del valor "infinito" usando el máximo valor de un entero en C++[cite: 38]
    // Equivale al valor 'None' utilizado en la matriz de la reformulación iterativa[cite: 12, 36]
    int inf_val = std::numeric_limits<int>::max(); 
    
    // Construcción de la tabla T bidimensional mediante std::vector[cite: 38]
    // Tamaño n x (d + 1) inicializado a infinito, donde almacenaremos el mínimo de monedas para cada subproblema (i, m)[cite: 12]
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, inf_val));
    
    // Caso base: para una cantidad m=0, el número de monedas necesarias es 0[cite: 12, 36]
    T[0][0] = 0;[cite: 36]
    
    // Cálculo de la primera fila de la tabla[cite: 13, 36]
    for (int j = 1; j <= d; ++j) {
        // Si la cantidad a devolver j es mayor o igual a la moneda y la celda previa tiene solución válida[cite: 36]
        if (j >= m[0] && T[0][j - m[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - m[0]];[cite: 36]
        }
    }
    
    // Cálculo del resto de las filas[cite: 14, 36]
    for (int i = 1; i < n; ++i) {
        T[i][0] = 0; // Para cantidad 0 siempre es 0[cite: 36]
        for (int j = 1; j <= d; ++j) {
            // Si la cantidad j es menor que el valor de la moneda o no se puede alcanzar usando esta moneda[cite: 36]
            if (j < m[i] || T[i][j - m[i]] == inf_val) {
                T[i][j] = T[i - 1][j]; // Se arrastra el valor mínimo calculado en la fila anterior[cite: 36]
            } else if (T[i - 1][j] != inf_val) {
                // Si hay solución válida tanto con la moneda actual como sin ella, nos quedamos con el mínimo usando std::min[cite: 36, 38]
                T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);[cite: 36]
            } else {
                // Si solo hay solución válida usando la moneda actual[cite: 36]
                T[i][j] = 1 + T[i][j - m[i]];[cite: 36]
            }
        }
    }
    
    // Proceso para recuperar la solución y determinar qué monedas exactas se devuelven[cite: 25, 37]
    s.assign(n, 0); // Inicializa el vector solución (Sol={0...0})[cite: 37]
    int i = n - 1;  // Índice de la última moneda en la tabla[cite: 37]
    int j = d;      // Cantidad máxima a devolver[cite: 37]
    
    // Se recorre la tabla hacia atrás mientras queden monedas por evaluar o cantidad restante[cite: 37]
    while (i != 0 || j != 0) {
        if (j == 0) break; 
        
        // Si estamos en la primera fila o el valor actual difiere del valor en la celda directamente superior[cite: 37]
        if (i == 0 || (T[i][j] != inf_val && T[i][j] != T[i - 1][j])) {
            s[i] = s[i] + 1; // Se suma una unidad de esta moneda a la solución[cite: 37]
            j = j - m[i];    // Se resta el valor de dicha moneda a la cantidad pendiente[cite: 37]
        } else {
            i = i - 1;       // Se pasa a evaluar la fila correspondiente a la moneda anterior[cite: 37]
        }
    }
}