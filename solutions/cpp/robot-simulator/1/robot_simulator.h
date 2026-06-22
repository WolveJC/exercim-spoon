#pragma once
#include <string>
#include <utility>

namespace robot_simulator {

    // Enumerado que representa la orientación del robot en un naillo cíclico 
    enum class Bearing {
        NORTH = 0,
        EAST = 1,
        SOUTH = 2,
        WEST = 3
    };

    class Robot {
    private:
        std::pair<int, int> m_position;
        Bearing m_bearing;

    public:
        // Constructor
        Robot();
        Robot(std::pair<int, int> position, Bearing bearing);

        // Getters
        std::pair<int, int> get_position() const;
        Bearing get_bearing() const;

        // Comandos de movimiento individuales
        void turn_right();
        void turn_left();
        void advance();

        // Procesa una cadena de comandos completa
        void execute_sequence(const std::string& instructions);
    };

}
