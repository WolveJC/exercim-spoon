#include <string>
#include <cctype>
#include "bob.h"
using namespace std;

namespace bob {

    string hey(string input) {
        // 1. Limpiar espacios en blanco al inicio y final (Trimming)
        const string ignore = " \t\n\r";
        size_t first = input.find_first_not_of(ignore);
        if (first == string::npos) {
        return "Fine. Be that way!"; // Retornar en caso de string vacio o solo espacios
    }
        size_t last = input.find_last_not_of(ignore);
        input = input.substr(first, (last - first + 1));
        // 2. Identificar si hay letras y si todas son mayúsculas (Grito)
        bool has_letters = false;
        bool has_minus = false;
        for (char c : input){
            if (isalpha(c)){
                has_letters = true;
                if (islower(c)){
                    has_minus = true;
                    break;
                }
            }
        }
        bool scream = has_letters && !has_minus;
        // 3. Identificar si el último carácter relevante es '?' (Pregunta)
        bool question = input.back() == '?';
        // 4. Orquestacion final
        if (scream && question) return "Calm down, I know what I'm doing!";
        if (scream) return "Whoa, chill out!";
        if (question) return "Sure.";
        
        return "Whatever."; 
    }

}