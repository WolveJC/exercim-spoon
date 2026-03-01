#include "kindergarten_garden.h"
#include <vector>
#include <algorithm>
using namespace std;

namespace kindergarten_garden {
    // Función auxiliar: Decodificador de caracteres
    Plants char_to_plant(char c){
        switch (c){
            case 'G': return Plants::grass;
            case 'C': return Plants::clover;
            case 'R': return Plants::radishes;
            case 'V': return Plants::violets;
            default : return Plants::grass;
        }
    }
    array<Plants, 4>plants(string diagram, string student){
        static const vector<string>students = {
            "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
            "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
        };
        
        // 1. Localización del índice del estudiante
        auto i = find(students.begin(), students.end(), student);
        const int plant_position = distance(students.begin(), i) * 2;

        // 2. Localización del punto de quiebre (newline)
        const size_t row2_start = diagram.find('\n') + 1;

        // 3. Extracción y conversión de las 4 plantas
        return {
            char_to_plant(diagram[plant_position]),
            char_to_plant(diagram[plant_position + 1]),
            char_to_plant(diagram[row2_start + plant_position]), 
            char_to_plant(diagram[row2_start + plant_position + 1])
        };
    }
}
