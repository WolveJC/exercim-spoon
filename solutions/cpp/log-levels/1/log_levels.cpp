#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

namespace log_line {
string message(string line) {
    size_t position = line.find(":");
    string text = line.substr(position + 2);
    const string whitespace = " \t\n\r";
    size_t first = text.find_first_not_of(whitespace);
    if (first == string::npos) return ""; 
    size_t last = text.find_last_not_of(whitespace);
    return text.substr(first, (last - first + 1));
}

string log_level(string line) {
    size_t start = line.find("[") + 1;
    size_t end = line.find("]");
    string level = line.substr (start, end - start);
    transform(level.begin(),level.end(),level.begin(), ::toupper);
    return level;
}

string reformat(string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
