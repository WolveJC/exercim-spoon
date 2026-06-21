#pragma once
#include <string>

namespace beer_song {

    // Genera un único verso específico (de 0 a 99)
    std::string verse(int number);

    // Genera una serie de versos desde un punto de inicio hasta un punto de fin
    std::string sing(int start, int end = 0);

}