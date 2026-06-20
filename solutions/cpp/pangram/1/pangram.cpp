#include "pangram.h"

namespace pangram {
    bool is_pangram(std::string_view text) {
        int seen_letters = 0; // Aquí guardaremos los 26 bits

        for (char c : text) {
            // 1. Convertir a minúscula de forma manual y segura (ASCII)
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }

            // 2. Si es una letra del alfabeto inglés, encendemos su bit
            if (c >= 'a' && c <= 'z') {
                int bit_position = c - 'a';
                seen_letters |= (1 << bit_position); 
            }
        }

        // 3. Máscara de control: ¿Están los 26 bits encendidos?
        constexpr int all_26_letters_mask = (1 << 26) - 1;
        
        return seen_letters == all_26_letters_mask;
    }

}