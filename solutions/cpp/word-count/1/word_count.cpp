#include "word_count.h"
#include <cctype>

using namespace std;

namespace word_count {

map<string, int> words(const string& text) {
    map<string, int> counts;
    string current_word = "";

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];

        // 1. Si es alfanumérico, se acumula en minúsculas
        if (isalnum(c)) {
            current_word += tolower(c);
        } 
        // 2. Si es un apóstrofo, validamos si es una contracción válida
        else if (c == '\'') {
            if (!current_word.empty() && i + 1 < text.length() && isalnum(text[i + 1])) {
                current_word += c;
            } else {
                // Si no es válida actúa como separador de la palabra actual.
                if (!current_word.empty()) {
                    counts[current_word]++;
                    current_word = "";
                }
            }
        } 
        // 3. Cualquier otro carácter actúa como un separador 
        else {
            if (!current_word.empty()) {
                counts[current_word]++;
                current_word = ""; // Limpiamos la ventana para la siguiente palabra
            }
        }
    }

    // Aduana de cierre: Si el texto terminó y quedó una palabra en el búfer
    if (!current_word.empty()) {
        counts[current_word]++;
    }

    return counts;
}

}
