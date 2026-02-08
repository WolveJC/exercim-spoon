#pragma once

#include <string>
#include <unordered_set>
#include <map>

namespace allergies {

class allergy_test {
public:
    // El constructor recibe el puntaje
    allergy_test(unsigned int score);

    // Método para verificar un ítem individual
    bool is_allergic_to(const std::string& item) const;

    // Método para obtener la lista completa
    std::unordered_set<std::string> get_allergies() const;

private:
    unsigned int score_;
    // Una estructura para mapear nombres a sus valores binarios
};

} // namespace allergies