#pragma once
#include <vector>

namespace all_your_base {

    // Convierte un vector de dígitos de una base origen a una base destino.
    // Lanza std::invalid_argument si las bases o los dígitos son incorrectos.
    std::vector<unsigned int> convert(unsigned int from_base, 
                                      const std::vector<unsigned int>& input_digits, 
                                      unsigned int to_base);

}
