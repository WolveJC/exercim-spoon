#include "crypto_square.h"
#include <cctype>
#include <cmath>

namespace crypto_square {

// Constructor
cipher::cipher(const std::string& text) {
    process_encryption(text);
}

void cipher::process_encryption(const std::string& text) {
    // Caso: Si la entrada está vacía
    if (text.empty()) {
        m_cipher_text = "";
        return;
    }

    // 1. Fase de Normalización
    std::string normalized = "";
    for (char c : text) {
        if (std::isalnum(c)) {
            normalized += std::tolower(c);
        }
    }

    size_t L = normalized.length();
    if (L == 0) {
        m_cipher_text = "";
        return;
    }

    // 2. Cálculo de Dimensiones de la Matriz Geométrica
    size_t c = std::ceil(std::sqrt(L));
    size_t r = (L + c - 1) / c;

    // 3. Relleno (Padding) para un bloque rectangular perfecto
    size_t perfect_size = c * r;
    if (normalized.length() < perfect_size) {
        normalized.append(perfect_size - normalized.length(), ' ');
    }

    // 4. Transposición y Segmentación por Columnas
    std::string encoded = "";
    for (size_t col = 0; col < c; ++col) {
        for (size_t row = 0; row < r; ++row) {
            encoded += normalized[row * c + col];
        }
        
        if (col < c - 1) {
            encoded += " ";
        }
    }

    m_cipher_text = encoded;
}

// Getter
std::string cipher::normalized_cipher_text() const {
    return m_cipher_text;
}

}
