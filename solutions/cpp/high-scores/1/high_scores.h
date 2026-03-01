#pragma once

#include <vector>
#include <algorithm>

namespace arcade {

    class HighScores {
    public:
        // Constructor: Recibe las puntuaciones iniciales
        HighScores(std::vector<int> scores) : scores_(scores) {}

        // Métodos requeridos (Const para garantizar inmutabilidad)
        std::vector<int> list_scores() const;
        int latest_score() const;
        int personal_best() const;
        std::vector<int> top_three() const;

    private:
        std::vector<int> scores_;
    };

}