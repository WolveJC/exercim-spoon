#include "trinary.h"
using namespace std;

namespace trinary {
    int to_decimal(const string& input){
        int result = 0;
        for (char c : input){
            if (c < '0' || c > '2') return 0;
            int digit = c - '0';
            result = (result * 3) + digit;
        } return result;
    }
}
