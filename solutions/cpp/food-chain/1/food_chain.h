#pragma once
#include <string>
#include <vector>

namespace food_chain {

    struct Animal {
        std::string name;
        std::string reaction;
    };

    // Devuelve una sola estrofa (1 a 8)
    std::string verse(int number);

    // Devuelve un rango de estrofa
    std::string verses(int start, int end);

    // Devuelve la canción completa
    std::string sing();

}
