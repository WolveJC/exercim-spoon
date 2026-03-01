#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>

namespace hexadecimal {

    // Transforma una cadena caótica en una estandarizada (Mayúsculas, sin espacios)
    std::string format_hex(const std::string& hex);

    // Realiza la síntesis matemática: de Base 16 a Decimal
    // Retorna el valor decimal o 0 si la entrada es inválida o vacía
    int convert(std::string hex);

} // namespace hexadecimal

#endif // HEXADECIMAL_H