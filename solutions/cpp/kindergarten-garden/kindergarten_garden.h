#pragma once
#include <string>
#include <array>



namespace kindergarten_garden {

    // Tarea 1: Identificación botánica
    enum class Plants{ grass, clover, radishes, violets};

    // Tarea 2: Función de mapeo del jardín
    // Recibe el diagrama y el nombre del niño, devuelve sus 4 plantas
    std::array<Plants, 4>plants(std::string diagram, std::string student);

}