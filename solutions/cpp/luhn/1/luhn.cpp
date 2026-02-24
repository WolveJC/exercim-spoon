#include "luhn.h"
#include <cctype>
using namespace std;

namespace luhn {
    // Esta función solo limpia y valida la la entrada
    string clean_input(const string& input) {
        string format = "";
        for (char c : input) {
            if (isspace(c)) continue;   // Ignorar espacios
            // Si hay una letra, el string queda invalidado (retorno vacío)
            if (!isdigit(c)) return ""; 
            format += c;
        }
        
        // Regla de Luhn: longitud mínima > 1
        if (format.length() <= 1) return ""; 
        
        return format; 
    }
    int luhn_sum(string format){
        int sum = 0;
        bool should_double = false;
        for (int i = format.length() - 1; i >= 0; i--){
            int digit = format[i] - '0';
            if (should_double == true){
                digit *= 2;
                if (digit > 9) digit-=9;
            } sum += digit;
            should_double = !should_double;
        }return sum;
    }

    bool valid(const string& input) {
    string clean = clean_input(input);
    if (clean.empty()) return false;
    return (luhn_sum(clean) % 10 == 0);
    }
}  // namespace luhn
