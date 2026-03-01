#include "atbash_cipher.h"
#include <cctype>
using namespace std;

namespace atbash_cipher {
    string encode(const string& text){
        string result = "";
        int count = 0;
        for (char c : text){
            if (isalnum(c)){
                if (count > 0 && count % 5 == 0) result += ' ';
                if (isalpha(c)) result += 'z' - (tolower(c) - 'a');
                else result += c;
                count++;
            }
        }return result;
    }
    string decode(const string& text){
        string result = "";
        for (char c : text){
            if (isspace(c)) continue;
            if(isalpha(c)) result += 'z' - (c - 'a');
            else result += c;
        } return result;
    }
}
