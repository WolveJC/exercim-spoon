#include "grains.h"

namespace grains {

    // Devuelve los granos en una casilla específica (1 a 64)
    unsigned long long square(int index) {
        // Desplazamiento de bits: 1ULL movido (index - 1) posiciones a la izquierda
        return 1ULL << (index - 1);
    }

    // Devuelve el total de granos en todo el tablero (2^64 - 1)
    unsigned long long total() {
        // En binario sin signo, invertir los bits de un 0 da el valor máximo posible
        return ~0ULL;
        // El operador de inversión es '~'
    }
}