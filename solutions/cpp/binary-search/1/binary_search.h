#pragma once
#include <vector>
#include <cstddef>

namespace binary_search {

    // Busca un valor en un vector ordenado y devuelve su índice.
    // Lanza std::domain_error si el valor no existe.
    std::size_t find(const std::vector<int>& data, int value);

}
