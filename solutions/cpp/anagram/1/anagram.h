#pragma once
#include <string>
#include <vector>

namespace anagram {

class anagram {
private:
    std::string m_target_original;
    std::string m_target_lowercase;
    std::string m_target_sorted;

    // Función auxiliar para convertir un string a minúsculas
    static std::string to_lowercase(std::string str);

public:
    // El constructor recibe y pre-procesa la palabra objetivo
    explicit anagram(const std::string& target);

    // Encuentra y devuelve las candidatas que cumplen 
    std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
};

}
