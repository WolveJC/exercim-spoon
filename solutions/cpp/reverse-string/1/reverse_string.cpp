#include <algorithm>
#include "reverse_string.h"
using namespace std;

namespace reverse_string {
    string reverse_string(string text){
        reverse(text.begin(), text.end());
        return text;
    }
    
}
