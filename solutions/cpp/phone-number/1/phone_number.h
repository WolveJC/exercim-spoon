#pragma once
#include <string>

namespace phone_number {

class phone_number {
private:
    std::string m_cleaned_number;

    // Función para aplicar las reglas estrictas de NANP
    void validate_and_clean(const std::string& raw_input);

public:
    // El constructor recibe la cadena sucia
    explicit phone_number(const std::string& raw_input);

    // Método de acceso al número limpio
    std::string number() const;
    
    // Getters de partes
    std::string area_code() const;
};

}