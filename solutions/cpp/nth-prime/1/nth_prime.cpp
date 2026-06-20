#include "nth_prime.h"
#include <stdexcept>

namespace nth_prime {

// Función auxiliar
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true; // 2 y 3 son primos
    if (num % 2 == 0 || num % 3 == 0) return false; // Filtramos múltiplos de 2 y 3

    // Bucle ultra avanzando de 6 en 6
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int nth(int n) {
    // Validación
    if (n <= 0) {
        throw std::domain_error("El argumento debe ser mayor o igual a 1.");
    }

    int prime_count = 0; // Cuántos primos llevamos encontrados
    int current_num = 1; // Número que estamos probando en cada iteración

    // 2. Bucle de búsqueda
    while (prime_count < n) {
        current_num++;
        if (is_prime(current_num)) {
            prime_count++;
        }
    }

    return current_num; // Este es el n-ésimo primo
}

}