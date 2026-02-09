#include <string>
#include <unordered_set>
#include <map>
#include "allergies.h"
using namespace std;

namespace allergies {

    const map<string, int> tabla_alergenos = {
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128}
    };
    // Constructor 
    allergy_test::allergy_test(unsigned int score):score_(score){}
    // Es alérgico?
    bool allergy_test::is_allergic_to(const string& item) const{
        // Buscar y guardar el iterador
        auto it = tabla_alergenos.find(item);
        // Si el iterador llegó al final, el alérgeno no existe
        if (it == tabla_alergenos.end()) {
        return false;
        }
        // 'it->second' es el valor binario
        return (score_ & it->second) != 0;
    }
    unordered_set<string> allergy_test::get_allergies() const {
    unordered_set<string> allergies;
    for (const auto& [allergy, value]:tabla_alergenos){
        if (is_allergic_to(allergy)){
            allergies.emplace(allergy);
        }
    }return allergies;
    }

}  // namespace allergies
