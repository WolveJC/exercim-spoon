#include "phone_number.h"
#include <cctype>
#include <stdexcept>

using namespace std;

namespace phone_number {

void phone_number::validate_and_clean(const string& raw_input) {
    string digits = "";

    // 1. Filtrar y extraer únicamente los dígitos numéricos
    for (char c : raw_input) {
        if (isdigit(c)) {
            digits += c;
        } else if (isalpha(c)) {
            // Si contiene letras, el número es inválido
            throw domain_error("El número no puede contener letras");
        }
    }

    // 2. Validar longitud y código de país (Prefijo 1)
    if (digits.length() == 11) {
        if (digits[0] != '1') {
            throw domain_error("El codigo de pais no es 1");
        }
        // Si el prefijo es correcto nos quedamos con los 10 dígitos locales
        digits = digits.substr(1);
    } else if (digits.length() != 10) {
        throw domain_error("Número de teléfono invalido");
    }

    // 3. Validar estructura NANP: NXX NXX-XXXX (Donde N es entre 2 y 9)
    // El código de área no puede empezar con 0 o 1
    if (digits[0] == '0' || digits[0] == '1') {
        throw domain_error("El código de área no puede empezar con 0 o 1.");
    }

    // El código de central no puede empezar con 0 o 1
    if (digits[3] == '0' || digits[3] == '1') {
        throw domain_error("El código de central no puede empezar con 0 o 1.");
    }

    // Guardamos el resultado validado
    m_cleaned_number = digits;
}

// Constructor
phone_number::phone_number(const string& raw_input) {
    validate_and_clean(raw_input);
}

// Getter del número completo limpio
string phone_number::number() const {
    return m_cleaned_number;
}

// Extrae los primeros 3 dígitos
string phone_number::area_code() const {
    return m_cleaned_number.substr(0, 3);
}

} 
