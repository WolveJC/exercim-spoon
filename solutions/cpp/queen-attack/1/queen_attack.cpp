#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {

// Implementación del validador de límites
bool chess_board::is_valid_position(std::pair<int, int> pos) const {
    return pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8;
}

// Constructor con lista de inicialización y filtros
chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) 
    : m_white(white), m_black(black) {
    
    // 1. Validar que estén dentro del tablero
    if (!is_valid_position(m_white) || !is_valid_position(m_black)) {
        throw std::domain_error("Posicion fuera de los limites del tablero");
    }

    // 2. Validar que no compartan la misma casilla
    if (m_white == m_black) {
        throw std::domain_error("Las reinas no pueden ocupar la misma casilla.");
    }
}

std::pair<int, int> chess_board::white() const { return m_white; }
std::pair<int, int> chess_board::black() const { return m_black; }

// El cálculo
bool chess_board::can_attack() const {
    // Extraemos para que el código sea ultra legible
    int f1 = m_white.first,  c1 = m_white.second;
    int f2 = m_black.first,  c2 = m_black.second;

    // Misma fila, misma columna, o misma diagonal
    return (f1 == f2) || (c1 == c2) || (std::abs(f1 - f2) == std::abs(c1 - c2));
}

}