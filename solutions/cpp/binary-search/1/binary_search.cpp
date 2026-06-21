#include "binary_search.h"
#include <stdexcept>

namespace binary_search {

std::size_t find(const std::vector<int>& data, int value) {
    // 1. Caso: Si el vector está vacío, no hay nada que buscar
    if (data.empty()) {
        throw std::domain_error("La lista está vacía");
    }

    // 2. Control de límites para evitar underflows
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;

    while (left <= right) {
        // Optimización para evitar overflow
        int mid = left + (right - left) / 2;

        // ¡Aqui lo encontramos!
        if (data[mid] == value) {
            return static_cast<std::size_t>(mid);
        }
        
        // Si el valor del centro es mayor, descartamos la mitad derecha
        if (data[mid] > value) {
            right = mid - 1;
        } 
        // Si el valor del centro es menor, descartamos la mitad izquierda
        else {
            left = mid + 1;
        }
    }

    // 3. Si salimos del bucle, los límites se cruzaron: el valor no existe
    throw std::domain_error("El valor buscado no existe en la lista");
}

}
