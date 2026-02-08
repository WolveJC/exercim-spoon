#include "armstrong_numbers.h"

namespace armstrong_numbers {

// Calcula la cantidad de dígitos de un entero.
int count_digits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Ejecuta la potencia de un entero. 
// Para mayor escala, considera usar long long en el retorno y el resultado.
int integer_pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Determinar si un número cumple la condición de Armstrong.
bool is_armstrong_number(int number) {
    if (number < 10) return true;
    
    int power = count_digits(number);
    int sum = 0; // Para números muy grandes, cambiar a long long para evitar overflow.
    int temp = number;
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += integer_pow(digit, power);
        temp /= 10;
    }
    
    // Si se usa long long, reemplace por: return sum == static_cast<long long>(number);
    return sum == number;
}

}  // namespace armstrong_numbers