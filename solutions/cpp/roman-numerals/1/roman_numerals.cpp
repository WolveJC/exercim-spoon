#include "roman_numerals.h"
#include <vector>
#include <utility>

using namespace std;

namespace roman_numerals {

string convert(int number) {
    string roman = "";

    // Diccionario estático de equivalencias
    const vector<pair<int, string>> roman_mapping = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
        {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
        {1,    "I"}
    };

    // Algoritmo Greedy
    for (const auto& mapping : roman_mapping) {
        while (number >= mapping.first) {
            roman += mapping.second;    // Concatenamos el símbolo
            number -= mapping.first;    // Reducimos el valor del número
        }
    }

    return roman;
}

}
