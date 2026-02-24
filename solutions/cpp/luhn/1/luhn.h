#pragma once

#include <string>

namespace luhn {

    // Filtra la entrada: elimina espacios y valida que solo contenga dígitos.
    std::string clean_input(const std::string& input);

    // Motor aritmético: calcula la suma de comprobación siguiendo la lógica de Luhn.
    int luhn_sum(std::string format);

    // Función principal: coordina la validación total del identificador.
    bool valid(const std::string& input);

}  // namespace luhn