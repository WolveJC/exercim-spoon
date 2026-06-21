#include "complex_numbers.h"
#include <cmath>

using namespace std;

namespace complex_numbers {

Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

double Complex::real() const { return m_real; }
double Complex::imag() const { return m_imag; }

double Complex::abs() const {
    return sqrt((m_real * m_real) + (m_imag * m_imag));
}

Complex Complex::conj() const {
    return Complex(m_real, -m_imag);
}

Complex Complex::exp() const {
    double exp_real = std::exp(m_real);
    return Complex(exp_real * cos(m_imag), exp_real * sin(m_imag));
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.m_real + rhs.m_real, lhs.m_imag + rhs.m_imag);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.m_real - rhs.m_real, lhs.m_imag - rhs.m_imag);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    double r = (lhs.m_real * rhs.m_real) - (lhs.m_imag * rhs.m_imag);
    double i = (lhs.m_imag * rhs.m_real) + (lhs.m_real * rhs.m_imag);
    return Complex(r, i);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double denominator = (rhs.m_real * rhs.m_real) + (rhs.m_imag * rhs.m_imag);
    
    double r = ((lhs.m_real * rhs.m_real) + (lhs.m_imag * rhs.m_imag)) / denominator;
    double i = ((lhs.m_imag * rhs.m_real) - (lhs.m_real * rhs.m_imag)) / denominator;
    
    return Complex(r, i);
}

}
