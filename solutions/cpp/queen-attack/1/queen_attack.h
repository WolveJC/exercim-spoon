#pragma once
#include <utility>

namespace queen_attack {

class chess_board {
private:
    // Atributos privados: coordenadas de cada reina
    std::pair<int, int> m_white;
    std::pair<int, int> m_black;

    // Validar que los índices estén entre 0 y 7
    bool is_valid_position(std::pair<int, int> pos) const;

public:
    // Constructor que recibe las posiciones de ambas reinas
    chess_board(std::pair<int, int> white, std::pair<int, int> black);

    // Getters
    std::pair<int, int> white() const;
    std::pair<int, int> black() const;

    // ¿Se pueden atacar?
    bool can_attack() const;
};

}