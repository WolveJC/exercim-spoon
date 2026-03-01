#include "rotational_cipher.h"
using namespace std;

namespace rotational_cipher {
    string rotate(const string& text, int shift){
        string result = "";
        int k = shift % 26;
        for (char c : text) {
            if (c >= 'a' && c <= 'z' ) result += (c - 'a' + k) % 26 + 'a' ;
            else if (c >= 'A' && c <= 'Z') result += (c - 'A' + k) % 26 + 'A';
            else result += c;
        }return result;
    }
}
