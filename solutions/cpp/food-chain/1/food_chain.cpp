#include "food_chain.h"
#include <sstream>

using namespace std;

namespace food_chain {

const vector<Animal> data = {
    {"fly", ""},
    {"spider", "It wriggled and jiggled and tickled inside her.\n"},
    {"bird", "How absurd to swallow a bird!\n"},
    {"cat", "Imagine that, to swallow a cat!\n"},
    {"dog", "What a hog, to swallow a dog!\n"},
    {"goat", "Just opened her throat and swallowed a goat!\n"},
    {"cow", "I don't know how she swallowed a cow!\n"},
    {"horse", "She's dead, of course!\n"}
};

string verse(int number) {
    int idx = number - 1;
    ostringstream ss;

    ss << "I know an old lady who swallowed a " << data[idx].name << ".\n";
    ss << data[idx].reaction;

    if (number == 8) {
        return ss.str();
    }

    for (int i = idx; i > 0; --i) {
        ss << "She swallowed the " << data[i].name << " to catch the " << data[i - 1].name;
        if (i - 1 == 1) {
            ss << " that wriggled and jiggled and tickled inside her";
        }
        ss << ".\n";
    }

    ss << "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    
    return ss.str();
}

string verses(int start, int end) {
    ostringstream ss;
    
    for (int i = start; i <= end; ++i) {
        ss << verse(i);
        ss << "\n";
    }
    
    return ss.str();
}

std::string sing() {
    return verses(1, 8);
}

}
