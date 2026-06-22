#include "all_your_base.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace all_your_base {

vector<unsigned int> convert(unsigned int from_base, 
                                  const vector<unsigned int>& input_digits, 
                                  unsigned int to_base) {
    
    // 1. El sistema posicional requiere una base mínima de 2
    if (from_base <= 1 || to_base <= 1){
        throw invalid_argument("Las bases deben ser mayor o igual a 2");
    }

    // 2. Fase de Acumulación (Base A -> Base 10)
    unsigned int decimal_value = 0;
    bool leading_zero = true;

    for (unsigned int digit : input_digits) {
        // Validación de rango: Un dígito no puede ser igual o mayor que su base
        if (digit >= from_base) {
            throw invalid_argument("Dígito inválido para la base");
        }

        // Detectar si hay ceros no significativos a la izquierda
        if (leading_zero && digit == 0) {
            continue; // Los ignoramos en el cálculo
        }
        leading_zero = false;

        // Desplazamiento posicional y acumulación matemática
        decimal_value = (decimal_value * from_base) + digit;
    }

    // Si la entrada estaba vacía o consistía únicamente en ceros
    if (decimal_value == 0) {
        return {};
    }

    // 3. Fase de Descomposición (Base 10 -> Base B)
    vector<unsigned int> output_digits;
    
    while (decimal_value > 0) {
        unsigned int remainder = decimal_value % to_base;
        output_digits.push_back(remainder);
        decimal_value /= to_base;
    }

    // Invertimos el vector para devolver el orden posicional correcto 
    std::reverse(output_digits.begin(), output_digits.end());

    return output_digits;
}

} 
