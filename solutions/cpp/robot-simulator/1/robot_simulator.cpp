#include "robot_simulator.h"

using namespace std;

namespace robot_simulator {

// Constructor (esta mirando al norte)
Robot::Robot() : m_position({0, 0}), m_bearing(Bearing::NORTH) {}

// Constructor parametrizado
Robot::Robot(std::pair<int, int> position, Bearing bearing) 
    : m_position(position), m_bearing(bearing) {}

pair<int, int> Robot::get_position() const {
    return m_position;
}

Bearing Robot::get_bearing() const {
    return m_bearing;
}

void Robot::turn_right() {
    // Avanza un paso en sentido horario
    int next = (static_cast<int>(m_bearing) + 1) % 4;
    m_bearing = static_cast<Bearing>(next);
}

void Robot::turn_left() {
    // Retrocede un paso en sentido horario
    int next = (static_cast<int>(m_bearing) + 3) % 4;
    m_bearing = static_cast<Bearing>(next);
}

void Robot::advance() {
    // Tabla de movimiento indexada por el valor del enum Bearing
    static const std::pair<int, int> movement_map[] = {
        {0, 1},  // North: incrementa Y
        {1, 0},  // East: incrementa X
        {0, -1}, // South: decrementa Y
        {-1, 0}  // West: decrementa X
    };

    int idx = static_cast<int>(m_bearing);
    m_position.first += movement_map[idx].first;
    m_position.second += movement_map[idx].second;
}

void Robot::execute_sequence(const string& instructions) {
    for (char cmd : instructions) {
        switch (cmd) {
            case 'R': turn_right(); break;
            case 'L': turn_left();  break;
            case 'A': advance();    break;
            default:  break; // Ignora caracteres extraños
        }
    }
}

}