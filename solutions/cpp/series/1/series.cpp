#include "series.h"
#include <stdexcept>

using namespace std;

namespace series {

vector<string> slice(const string& digits, int n) {
    vector<string> result;
    int len = static_cast<int>(digits.length());

    // 1. Fase de Validación en caso de Overflow 
    if (n <= 0) {
        throw domain_error("La longitud de la serie debe ser mayor que cero.");
    }
    if (len == 0) {
        throw domain_error("La cadena de dígitos no puede estar vacía.");
    }
    if (n > len) {
        throw domain_error("La longitud de la serie no puede ser mayor que la cadena original.");
    }

    // 2. Fase de Barrido Lineal
    // El límite estricto es i <= len - n
    for (int i = 0; i <= len - n; ++i) {
        // Extrae 'n' caracteres a partir de la posición 'i'
        result.push_back(digits.substr(i, n));
    }

    return result;
}

} 
