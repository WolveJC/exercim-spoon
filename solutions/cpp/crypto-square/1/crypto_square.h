#pragma once
#include <string>

namespace crypto_square {

class cipher {
private:
    std::string m_cipher_text;

    void process_encryption(const std::string& text);

public:
    explicit cipher(const std::string& text);
    std::string normalized_cipher_text() const;
};

}
