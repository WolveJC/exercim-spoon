#pragma once

namespace complex_numbers {

class Complex {
private:
    double m_real;
    double m_imag;

public:
    // Constructor
    Complex(double real = 0.0, double imag = 0.0);

    // Getters
    double real() const;
    double imag() const;

    // Métodos unarios
    double abs() const;
    Complex conj() const;
    Complex exp() const;

    // Operadores Simétricos como funciones libres "friend"
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);
};

}
