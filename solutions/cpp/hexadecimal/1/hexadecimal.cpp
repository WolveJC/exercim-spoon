#include "hexadecimal.h"
#include <map>
#include <cctype>
#include <string>
using namespace std;

namespace hexadecimal {
    const map<char, int>HEX_VALUES{
        {'0',0}, {'1',1}, {'2',2}, {'3',3}, 
        {'4',4}, {'5',5}, {'6',6}, {'7',7},
        {'8',8}, {'9',9}, {'A',10}, {'B',11}, 
        {'C',12}, {'D',13}, {'E',14}, {'F',15}
    };
    string format_hex(const string& hex){
            string format = "";
            for (char c : hex){
                if (!isspace(c)) format += toupper(c); //Si no hay espacios, haz c MAYÚS
            }return format;
        }
    int convert(string hex){
        string format_number = format_hex(hex);
        if (format_number.empty()) return 0; //Si hay entrada vacía, finaliza 
        long long result = 0;
        for (char c : format_number){
            auto it = HEX_VALUES.find(c); //Recorrer el mapa
            // Si llegamos al final, y no encontramos nada, aborta, el numero no es HEX
            if (it == HEX_VALUES.end()) return 0;
            //Calcula en base 16, el resultado encontrado en MAP
            result = (result * 16) + it->second; 
        }return result;
    }
}  // namespace hexadecimal
